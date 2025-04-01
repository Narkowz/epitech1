{-
-- EPITECH PROJECT, 2025
-- main.hs
-- File description:
-- main
-}

module Main where

import System.Environment
import System.Exit
import Data.Maybe (fromMaybe)
import Data.Char (isDigit)

data Conf = Conf
  { rule :: Int
  , start :: Int
  , numLines :: Maybe Int
  , window :: Int
  , move :: Int
  , generation :: Maybe String
  } deriving (Show)

defaultConf :: Conf
defaultConf = Conf
  { rule = -1
  , start = 0
  , numLines = Nothing
  , window = 80
  , move = 0
  , generation = Nothing
  }

isPositiveInteger :: String -> Bool
isPositiveInteger str = all isDigit str && not (null str)

usageMessage :: String
usageMessage = "Usage: wolfram --rule <rule> [--start <start>] [--lines <lines>] [--window <window>] [--move <move>] [--generation <initial_cells>]"

parseArgs :: [String] -> Either String Conf
parseArgs args = parseArgsHelper defaultConf args
  where
    parseArgsHelper conf [] =
      if rule conf == -1
        then Left ("Error: Rule is required\n" ++ usageMessage)
        else validateConf conf
    parseArgsHelper conf (arg : val : rest) =
      case arg of
        "--rule" ->
          if isPositiveInteger val
            then let r = read val in
                   if r `elem` [30, 90, 110]
                     then parseArgsHelper (conf {rule = r}) rest
                     else Left ("Error: Rule must be 30, 90, or 110\n" ++ usageMessage)
            else Left ("Error: Rule must be a positive integer\n" ++ usageMessage)
        "--start" ->
          if isPositiveInteger val
            then parseArgsHelper (conf {start = read val}) rest
            else Left ("Error: Start must be a positive integer\n" ++ usageMessage)
        "--lines" ->
          if isPositiveInteger val
            then parseArgsHelper (conf {numLines = Just (read val)}) rest
            else Left ("Error: Lines must be a positive integer\n" ++ usageMessage)
        "--window" ->
          if isPositiveInteger val
            then parseArgsHelper (conf {window = read val}) rest
            else Left ("Error: Window must be a positive integer\n" ++ usageMessage)
        "--move" ->
          if all (\c -> isDigit c || c == '-') val
            then parseArgsHelper (conf {move = read val}) rest
            else Left ("Error: Move must be an integer\n" ++ usageMessage)
        "--generation" ->
          parseArgsHelper (conf {generation = Just val}) rest
        _ ->
          Left ("Error: Invalid argument " ++ arg ++ "\n" ++ usageMessage)
    parseArgsHelper _ _ = Left ("Error: Invalid arguments\n" ++ usageMessage)

validateConf :: Conf -> Either String Conf
validateConf conf = Right conf

calculateNextGeneration :: Int -> String -> String
calculateNextGeneration rule currentCells =
  let
    extendedCells = "   " ++ currentCells ++ "   "
    indexedCells = createTriplets extendedCells
    newCells = map (calculateCell rule) indexedCells
  in
    newCells

calculateCell :: Int -> (Char, Char, Char) -> Char
calculateCell rule (left, center, right) =
  let
    neighbors =
      (if left == '*' then 4 else 0)
        + (if center == '*' then 2 else 0)
        + (if right == '*' then 1 else 0)
    bit = (rule `div` (2 ^ neighbors)) `mod` 2
  in
    if bit == 1 then '*' else ' '

renderGeneration :: Conf -> String -> String
renderGeneration conf currentCells =
  let
    windowWidth = window conf
    moveOffset = move conf
    generationLength = length currentCells
    paddingNeeded = max 0 ((windowWidth - generationLength) `div` 2)
    startIndex = (generationLength - windowWidth) `div` 2 - moveOffset + paddingNeeded
    paddedCells = replicate (max 0 (-startIndex)) ' ' ++ currentCells ++ replicate (max 0 (startIndex + windowWidth - length currentCells)) ' '
    visibleCells = take windowWidth (drop (max 0 startIndex) paddedCells)
  in
    visibleCells

runWolfram :: Conf -> String -> IO ()
runWolfram conf initialCells =
  case numLines conf of
    Just lineCount ->
      displayGenerations conf lineCount initialCells
    Nothing ->
      displayInfiniteGenerations conf initialCells

displayGenerations :: Conf -> Int -> String -> IO ()
displayGenerations conf lineCount initialCells = do
  let
    generations =
      take lineCount (iterate (calculateNextGeneration (rule conf)) initialCells)
  mapM_ (putStrLn . renderGeneration conf) generations

displayInfiniteGenerations :: Conf -> String -> IO ()
displayInfiniteGenerations conf initialCells = do
  let
    generations =
      iterate (calculateNextGeneration (rule conf)) initialCells
  mapM_ (putStrLn . renderGeneration conf) generations

createTriplets :: String -> [(Char, Char, Char)]
createTriplets str =
  case str of
    (a:b:c:rest) -> (a, b, c) : createTriplets (b:c:rest)
    _ -> []

main :: IO ()
main = do
  args <- getArgs
  case parseArgs args of
    Right conf -> do
      let initialCells = fromMaybe "*" (generation conf)
      let initialPadding = 100
      let paddedInitialCells = replicate initialPadding ' ' ++ initialCells ++ replicate initialPadding ' '
      let startGeneration = start conf
      let evolvedCells = iterate (calculateNextGeneration (rule conf)) paddedInitialCells !! startGeneration
      runWolfram conf evolvedCells
    Left err -> do
      putStrLn err
      exitWith (ExitFailure 84)
