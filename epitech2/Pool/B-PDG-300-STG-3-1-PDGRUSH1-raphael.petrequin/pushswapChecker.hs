{-
-- EPITECH PROJECT, 2025
-- $PROJECT_NAME
-- File description:
-- $DESCRIPTION
-}

import Operation (applyOperation)
import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode(ExitFailure))
import Data.Char (isDigit)

isSignedInt :: String -> Bool
isSignedInt "" = False
isSignedInt ('-':xs) = all isDigit xs && not (null xs)
isSignedInt ('+':xs) = all isDigit xs && not (null xs)
isSignedInt xs = all isDigit xs

split :: Eq a => a -> [a] -> [[a]]
split _ [] = []
split delimiter xs =
    let (word, rest) = break (== delimiter) xs
    in word : case rest of
        [] -> []
        (_:xs2) -> split delimiter xs2

pushswapChecker :: [Int] -> IO ()
pushswapChecker list = do
    ops <- getLine
    let opsArray = split ' ' ops
        validOps = ["sa", "sb", "sc", "pa", "pb", "ra",
                    "rb", "rr", "rra", "rrb", "rrr"]
        isValid = all (`elem` validOps) opsArray
    case isValid of
        True -> putStrLn (show list)
        False -> exitWith (ExitFailure 84)

main :: IO ()
main = do
    strArgs <- getArgs
    case (all isSignedInt strArgs) of
        True -> pushswapChecker (map read strArgs :: [Int])
        False -> exitWith (ExitFailure 84)