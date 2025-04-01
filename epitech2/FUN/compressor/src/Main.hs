{-
-- EPITECH PROJECT, 2025
-- imageCompressor
-- File description:
-- Main
-}

import Data.List (nub, minimumBy)
import Data.Ord
import Text.Printf
import Text.Read (readMaybe)
import System.Environment (getArgs)
import System.Random (randomRIO)
import Control.Monad (replicateM)
import Control.Exception (catch, IOException)

type Point = (Int, Int)
type Value = (Int, Int, Int)
type DataPoint = (Point, Value)
type Centroid = (Point, Value)

splitOn :: Eq a => a -> [a] -> [[a]]
splitOn _ [] = []
splitOn delim str = 
    case break (== delim) str of
        (chunk, []) -> [chunk]
        (chunk, _:rest) -> chunk : splitOn delim rest

isValidColor :: (Int, Int, Int) -> Bool
isValidColor (r, g, b) = all (\x -> x >= 0 && x <= 255) [r, g, b]

parsePoint :: String -> Maybe DataPoint
parsePoint line = case words line of
    [pointStr, valueStr] -> 
        case (parseCoords pointStr, parseColor valueStr) of
            (Just (x, y), Just (v1, v2, v3)) | isValidColor (v1, v2, v3) -> 
                Just ((x, y), (v1, v2, v3))
            _ -> Nothing
    _ -> Nothing

parseCoords :: String -> Maybe (Int, Int)
parseCoords str = case splitOn ',' (cleanParens str) of
    [x, y] -> (,) <$> readMaybe x <*> readMaybe y
    _ -> Nothing

parseColor :: String -> Maybe (Int, Int, Int)
parseColor str = case splitOn ',' (cleanParens str) of
    [r, g, b] -> (,,) <$> readMaybe r <*> readMaybe g <*> readMaybe b
    _ -> Nothing

cleanParens :: String -> String
cleanParens = filter (`notElem` "()")

parseData :: String -> Maybe [DataPoint]
parseData input = mapM parsePoint (lines input)

initializeCentroids :: Int -> [DataPoint] -> IO [Centroid]
initializeCentroids k points = do
    indices <- replicateM k (randomRIO (0, length points - 1))
    return [points !! i | i <- nub indices]

assignPoints :: [Centroid] -> [DataPoint] -> [(DataPoint, Int)]
assignPoints centroids points = map assign points
    where
        assign point = (point, closestCentroid point)
        closestCentroid point = snd $ minimumBy
            (comparing (distance point . fst)) (zip centroids [0..])

updateCentroids :: Int -> [(DataPoint, Int)] -> [Centroid]
updateCentroids k assignments = map update [0..k-1]
    where
        update i = average (map fst (filter ((== i) . snd) assignments))
        
average :: [DataPoint] -> (Point, Value)
average ps = (averagePoint (map fst ps), averageValue (map snd ps))

averagePoint :: [Point] -> Point
averagePoint ps = if null ps then (0, 0)
                  else (sum (map fst ps) `div` length ps,
                        sum (map snd ps) `div` length ps)

averageValue :: [Value] -> Value
averageValue vs = if null vs then (0, 0, 0)
                  else (sum (map (\(v1, _, _) -> v1) vs) `div` length vs,
                        sum (map (\(_, v2, _) -> v2) vs) `div` length vs,
                        sum (map (\(_, _, v3) -> v3) vs) `div` length vs)

distance :: DataPoint -> DataPoint -> Float
distance ((x1, y1), (v1, v2, v3)) ((x2, y2), (v4, v5, v6)) =
    sqrt (fromIntegral (square (x1 - x2) + square (y1 - y2) + 
                       square (v1 - v4) + square (v2 - v5) + 
                       square (v3 - v6)) :: Float)
  where
    square :: Int -> Int
    square x = x * x

converged :: Float -> [Centroid] -> [Centroid] -> Bool
converged threshold old new = all (< threshold)
    (zipWith centroidDistance old new)

centroidDistance :: Centroid -> Centroid -> Float
centroidDistance ((_, _), v1) ((_, _), v2) = distance ((0,0), v1) ((0,0), v2)

kmeans :: Int -> Float -> [DataPoint] -> IO [(Centroid, [DataPoint])]
kmeans k threshold points = 
    initializeCentroids k points >>= \initialCentroids ->
        iterateUntilConvergence initialCentroids (0::Int)
  where
    iterateUntilConvergence centroids iterations = 
        let assignments = assignPoints centroids points
            newCentroids = updateCentroids k assignments
        in if converged threshold centroids newCentroids
        then return [(c,[p|(p,i)<-assignments,i==j])|(c,j)<-zip centroids[0..]]
        else iterateUntilConvergence newCentroids (iterations + 1)


handleReadError :: IOException -> IO (Maybe String)
handleReadError _ = return Nothing

formatOutput :: [(Centroid, [DataPoint])] -> String
formatOutput clusters = unlines $ concatMap formatCluster clusters

formatCluster :: (Centroid, [DataPoint]) -> [String]
formatCluster ((_, value), points) = ["--", formatValue value, "-"] ++
                                      map formatPoint points

formatValue :: Value -> String
formatValue (r, g, b) = printf "(%d,%d,%d)" r g b

formatPoint :: DataPoint -> String
formatPoint ((x, y), (r, g, b)) = printf "(%d,%d) (%d,%d,%d)" x y r g b

handleArgs :: [String] -> IO ()
handleArgs ["-n", kStr, "-l", lStr, "-f", filePath] =
    handleValidArgs kStr lStr filePath
handleArgs _ = putStrLn usageMessage

handleValidArgs :: String -> String -> String -> IO ()
handleValidArgs kStr lStr filePath =
    let maybeK = readMaybe kStr :: Maybe Int
        maybeL = readMaybe lStr :: Maybe Float
    in case (maybeK, maybeL) of
        (Just k, Just l) -> processFile k l filePath
        _ -> putStrLn ("Error: Invalid arguments. Ensure N is " ++ 
                            "an integer and L is a float.")


processFile :: Int -> Float -> String -> IO ()
processFile k l filePath = do
    result <- (Just <$> readFile filePath) `catch` handleReadError
    case result of
        Just contents -> processData contents k l
        Nothing -> putStrLn "Error: File not found or unreadable."

processData :: String -> Int -> Float -> IO ()
processData contents k l = case parseData contents of
    Just points -> do
        clusters <- kmeans k l points
        putStr $ formatOutput clusters
    Nothing -> putStrLn "Error: Invalid file format. Ensure format: \
                         \(x,y) (r,g,b)."

usageMessage :: String
usageMessage = "USAGE: ./imageCompressor -n N -l L -f F\n\n\tN\t" ++
               "number of colors in the final image\n\tL\tconvergence \
               \limit\n\tF\tpath to the file containing the colors of \
               \the pixels"

main :: IO ()
main = do
    args <- getArgs
    handleArgs args
