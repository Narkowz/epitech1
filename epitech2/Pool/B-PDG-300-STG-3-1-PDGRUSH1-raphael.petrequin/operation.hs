{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-STG-3-1-PDGRUSH1-raphael.petrequin
-- File description:
-- operation.hs
-}

module Operation (applyOperation) where

-- The sa function swaps the first two elements of l_a
sa :: [Int] -> [Int]
sa (x:y:xs) = y : x : xs    -- Swap the first two elements
sa xs = xs                  -- If there are fewer than two elements, do nothing

-- The sa function swaps the first two elements of l_b
sb :: [Int] -> [Int]
sb (x:y:xs) = y : x : xs    -- Swap the first two elements
sb xs = xs                  -- If there are fewer than two elements, do nothing

-- The sc function applies sa to l_a and sb to l_b
sc :: ([Int], [Int]) -> ([Int], [Int])
sc (l_a, l_b) = (sa l_a, sb l_b)

-- The pa function take the first element from l_b
-- and move it to the first position on the l_a list
pa :: ([Int], [Int]) -> ([Int], [Int])
pa (l_a, [])   = (l_a, [])      -- If l_b is empty, do nothing
pa (l_a, x:xs) = (x:l_a, xs)    -- Move the first element from l_b to l_a

-- The pb function take the first element from l_a
-- and move it to the first position on the l_b list
pb :: ([Int], [Int]) -> ([Int], [Int])
pb ([], l_b)   = ([], l_b)      -- If l_a is empty, do nothing
pb (x:xs, l_b) = (xs, x:l_b)    -- Move the first element from l_a to l_b

-- The ra function rotate l_a toward the beginning:
-- the first element becomes the last.
ra :: [Int] -> [Int]
ra (x:xs) = xs ++ [x]    -- Move the first element to the end.
ra [] = []               -- If l_a is empty, do nothing.

-- The ra function rotate l_b toward the beginning:
-- the first element becomes the last.
rb :: [Int] -> [Int]
rb (x:xs) = xs ++ [x]    -- Same logic as ra for l_b.
rb [] = []               -- If l_b is empty, do nothing.

-- The rr function rotate both l_a and l_b toward the beginning.
rr :: ([Int], [Int]) -> ([Int], [Int])
rr (l_a, l_b) = (ra l_a, rb l_b)  -- Apply ra to l_a and rb to l_b.

-- The rra function rotate l_a toward the end:
-- the last element becomes the first.
rra :: [Int] -> [Int]
rra xs = last xs : init xs   -- Move the last element to the beginning.
rra [] = []                  -- If l_a is empty, do nothing.

-- The rrb function rotate l_b toward the end:
-- the last element becomes the first.
rrb :: [Int] -> [Int]
rrb xs = last xs : init xs   -- Same logic as rra for l_b.
rrb [] = []                  -- If l_b is empty, do nothing.

-- The rrr function rotate both l_a and l_b toward the end.
rrr :: ([Int], [Int]) -> ([Int], [Int])
rrr (l_a, l_b) = (rra l_a, rrb l_b)  -- Apply rra to l_a and rrb to l_b.

applyOperation :: String -> ([Int], [Int]) -> ([Int], [Int])
applyOperation "sa" (l_a, l_b) = ((sa l_a), l_b)
applyOperation "sb" (l_a, l_b) = (l_a, (sb l_b))
applyOperation "sc" (l_a, l_b) = sc (l_a, l_b)
-- applyOperation "ra" (l_a, l_b) = ra l_a l_b
-- applyOperation "rb" (l_a, l_b) = rb l_a l_b
-- applyOperation "rr" (l_a, l_b) = rr l_a l_b
-- applyOperation "rra" (l_a, l_b) = rra l_a l_b
-- applyOperation "rrb" (l_a, l_b) = rrb l_a l_b
-- applyOperation "rrr" (l_a, l_b) = rrr l_a l_b
applyOperation op (l_a, l_b) = error $ "Unsupported operation: " ++ op
