{-
-- EPITECH PROJECT, 2025
-- boot.hs
-- File description:
-- boot
-}

module Config where

import Prelude hiding (lines)  -- Cache la fonction `lines` de Prelude
import Data.Maybe (fromMaybe)

data Conf = Conf
  { rule   :: Maybe Int
  , start  :: Maybe Int
  , lines  :: Maybe Int  -- Conflit résolu, on peut garder "lines"
  , window :: Maybe Int
  , move   :: Maybe Int
  } deriving (Show, Eq)

defaultConf :: Conf
defaultConf = Conf
  { rule   = Just 30
  , start  = Just 0
  , lines  = Just 10  -- Plus de problème ici !
  , window = Just 80
  , move   = Just 0
  }

getOpts :: Conf -> [String] -> Maybe Conf
getOpts conf [] = Just conf
getOpts conf ("--rule" : n : args) =
  case reads n of
    [(num, "")] | num >= 0 -> getOpts conf { rule = Just num } args
    _ -> Nothing
getOpts conf ("--start" : n : args) =
  case reads n of
    [(num, "")] -> getOpts conf { start = Just num } args
    _ -> Nothing
getOpts conf ("--lines" : n : args) =
  case reads n of
    [(num, "")] | num > 0 -> getOpts conf { lines = Just num } args
    _ -> Nothing
getOpts conf ("--window" : n : args) =
  case reads n of
    [(num, "")] | num > 0 -> getOpts conf { window = Just num } args
    _ -> Nothing
getOpts conf ("--move" : n : args) =
  case reads n of
    [(num, "")] -> getOpts conf { move = Just num } args
    _ -> Nothing
getOpts _ _ = Nothing

main :: IO ()
main = do
  let args = ["--rule", "90", "--start", "5", "--lines", "20"]
  case getOpts defaultConf args of
    Just newConf -> print newConf
    Nothing      -> putStrLn "Invalid configuration options!"
