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
