{-
-- EPITECH PROJECT, 2025
-- Tree.hs
-- File description:
-- Tasks of the Day 03 of the Tech 2 Pool
-}

-- Step 2

data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving (Show)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree value Empty = Node Empty value Empty
addInTree value (Node left nodeValue right)
    | value < nodeValue = Node (addInTree value left) nodeValue right
    | otherwise         = Node left nodeValue (addInTree value right)


instance Functor Tree where
    fmap _ Empty = Empty
    fmap f (Node left value right) =
        Node (fmap f left) (f value) (fmap f right)

listToTree :: Ord a => [a] -> Tree a
listToTree = foldr addInTree Empty

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node left value right) =
    treeToList left ++ [value] ++ treeToList right

treeSort :: (Ord a) => [a] -> [a]
treeSort xs = treeToList (listToTree xs)

instance Foldable Tree where
    foldr _ z Empty = z
    foldr f z (Node left x right) = foldr f (f x (foldr f z right)) left