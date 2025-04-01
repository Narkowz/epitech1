{-
-- EPITECH PROJECT, 2025
-- DoOp.hs
-- File description:
-- Tasks of the Day 02 of the Tech 2 Pool
-}

import Data.Char (isDigit)
import System.Environment
import System.Exit


-- Step 0

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem x (y:ys)
  | x == y    = True
  | otherwise = myElem x ys

-- Step 1

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv x y = Just (x `div` y)

safeNth :: [ a ] -> Int -> Maybe a
safeNth a b
         | b < 0 = Nothing
         | b >= length a = Nothing
safeNth [] _ = Nothing
safeNth (a:_) 0 = Just a
safeNth (_:a) b = safeNth a (b - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just x) = Just $ x + 1

myLookup :: Eq a => a -> [ ( a , b ) ] -> Maybe b
myLookup _ [] = Nothing
myLookup x ((a, b):xs)
  | x == a = Just b
  | otherwise = myLookup x xs

maybeDo :: ( a -> b -> c ) -> Maybe a -> Maybe b -> Maybe c
maybeDo func (Just x) (Just y) = Just $ func x y
maybeDo _ _ _ = Nothing

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt str
    | head str == '-' =
        case readInt (tail str) of
            Just n -> Just (-n)
            Nothing -> Nothing
  | all isDigit str = Just (convertToInt str)
  | otherwise = Nothing

convertToInt :: [Char] -> Int
convertToInt str = convertAux str 0

convertAux :: [Char] -> Int -> Int
convertAux [] acc = acc
convertAux (c:cs) acc = convertAux cs (acc * 10 + charToDigit c)

charToDigit :: Char -> Int
charToDigit c = fromEnum c - fromEnum '0'

getLineLength :: IO Int
getLineLength = do
    line <- getLine
    return (length line)

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >> return (length str)


printBox :: Int -> IO ()
printBox 1 = putStrLn "++" 
printBox n
  | n <= 0    = return ()
  | otherwise = printLine '+' '-' ((n - 1) * 2) >> 
                printMiddle n ((n - 1) * 2) >> 
                printLine '+' '-' ((n - 1) * 2)

printLine :: Char -> Char -> Int -> IO ()
printLine start fill width = 
  putChar start >> 
  myPutStr fill width >> 
  putChar start >> 
  putChar '\n'

myPutStr :: Char -> Int -> IO ()
myPutStr _ 0 = return ()
myPutStr c n = putChar c >> myPutStr c (n - 1)

printMiddle :: Int -> Int -> IO ()
printMiddle 2 _ = return ()
printMiddle rows width = 
  putChar '|' >> 
  myPutStr ' ' width >> 
  putChar '|' >> 
  putChar '\n' >> 
  printMiddle (rows - 1) width

concatLines :: Int -> IO String
concatLines n
  | n <= 0    = return ""
  | otherwise = getLine >>= \line -> 
                concatLines (n - 1) >>= \rest -> 
                return (line ++ rest)

getInt :: IO ( Maybe Int)
getInt = do
    line <- getLine
    let result = case reads line of
                    [(n, "")] -> Just n
                    _ -> Nothing
    return result

calcul :: Maybe Int -> String -> Maybe Int -> Maybe Int
calcul Nothing _ _ = Nothing
calcul _ _ Nothing = Nothing
calcul (Just x) "+" (Just y) = Just (x + y)
calcul (Just x) "-" (Just y) = Just (x - y)
calcul (Just x) "*" (Just y) = Just (x * y)
calcul (Just x) "/" (Just 0) = Nothing
calcul (Just x) "/" (Just y) = Just (x `div` y)
calcul (Just x) "%" (Just 0) = Nothing
calcul (Just x) "%" (Just y) = Just (x `mod` y)
calcul _ _ _ = Nothing

parseArguments :: [String] -> Maybe Int
parseArguments [] = Nothing
parseArguments (x : operator : y: []) = calcul (readInt x) operator (readInt y)
parseArguments _ = Nothing
    
main :: IO Int
main = do
    args <- getArgs
    case parseArguments args of
        Nothing -> exitWith (ExitFailure 84)
        Just result -> print result >> return (0)
