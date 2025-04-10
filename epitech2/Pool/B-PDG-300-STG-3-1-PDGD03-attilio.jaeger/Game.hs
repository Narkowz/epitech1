{-
-- EPITECH PROJECT, 2025
-- Game.hs
-- File description:
-- Tasks of the Day 03 of the Tech 2 Pool
-}

-- Step 0

import Data.Typeable(typeOf)
import Data.Monoid (Sum(..))


data Item = Sword 
        | Bow
        | MagicWand
        deriving (Eq)

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"
        
-- Step 1

data Mob = Mummy | Skeleton Item | Witch (Maybe Item)
        deriving (Eq)

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = (Skeleton Bow)

createKnight :: Mob
createKnight = (Skeleton Sword)

createWitch :: Mob
createWitch = (Witch (Nothing))

createSorceress :: Mob
createSorceress = (Witch (Just MagicWand))

create :: String -> Maybe Mob
create "mummy" = Just createMummy
create "doomed archer" = Just createArcher
create "dead knight" = Just createKnight
create "witch" = Just createWitch
create "sorceress" = Just createSorceress
create _ = Nothing

equip :: Item -> Mob -> Maybe Mob
equip item (Skeleton _) = Just (Skeleton item)
equip item (Witch _) = Just (Witch (Just item))
equip _ Mummy = Nothing

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton item) = "skeleton holding a " ++ show item
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just item)) = "witch holding a " ++ show item

class HasItem a where
    getItem :: a -> Maybe Item

    hasItem :: a -> Bool
    hasItem obj = case getItem obj of
        Just _ -> True
        Nothing -> False

instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton item) = Just item
    getItem (Witch maybeItem) = maybeItem