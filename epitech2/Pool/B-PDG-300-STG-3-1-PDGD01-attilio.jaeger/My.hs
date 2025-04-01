{-
-- EPITECH PROJECT, 2025
-- My.hs
-- File description:
-- Tasks of the Day 01 of the Tech 2 Pool
-}

-- Step1

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x = if x < 0 then x * (-1) else x

myMin :: Int -> Int -> Int
myMin x y = if x < y then x else y

myMax :: Int -> Int -> Int
myMax x y = if x > y then x else y

-- Step2

myTuple :: a -> b -> (a, b)
myTuple a b = (a,b)

myTruple :: a -> b -> c -> (a , b , c )
myTruple a b c = (a,b,c)

myFst :: (a , b ) -> a
myFst (a, _) = a

mySnd :: (a, b) -> b
mySnd (_, b) = b

mySwap :: (a , b) -> (b , a )
mySwap (a,b) = (b,a)

-- Step3

myHead :: [ a ] -> a
myHead [] = error "List Empty"
myHead (a: _) = a

myTail :: [ a ] -> [ a ]
myTail [] = error "List Empty"
myTail (_:a) = a

myLength :: [ a ] -> Int
myLength [] = 0
myLength (_:a) = 1 + myLength a

myNth :: [ a ] -> Int -> a
myNth a b
         | b < 0 = error "Negative Index"
         | b >= myLength a = error "Too Large Index"
myNth [] _ = error "List Empty"
myNth (a:_) 0 = a
myNth (_:a) b = myNth a (b - 1)

myTake :: Int -> [ a ] -> [ a ]
myTake _ [] = []
myTake n _ | n <= 0 = []
myTake n (x:y) = x : myTake (n - 1) y

myDrop :: Int -> [ a ] -> [ a ]
myDrop 0 x = x
myDrop _ [] = []
myDrop n _ | n <= 0 = error "Negative Index"
myDrop n (_:y) = myDrop (n - 1) y

myAppend :: [ a ] -> [ a ] -> [ a ]
myAppend [] y = y
myAppend (x:xx) y = x : myAppend xx y

myReverse :: [ a ] -> [ a ]
myReverse [] = []
myReverse (x:xs) = myReverse xs `myAppend` [x]

myInit :: [ a ] -> [ a ]
myInit [] = error "Empty List"
myInit [_] = []
myInit (x:y) = x : myInit y

myLast :: [ a ] -> a
myLast [] = error "Empty List"
myLast [x] = x
myLast (x:y) = myLast y

myZip :: [ a ] -> [ b ] -> [( a , b ) ]
myZip [] _ = []
myZip _ [] = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myUnzip :: [( a , b ) ] -> ([ a ] , [ b ])
myUnzip [] = ([], [])
myUnzip ((x, y):xs) = (x : xs1, y : ys1)
    where
        (xs1, ys1) = myUnzip xs

-- Step4

myMap :: ( a -> b ) -> [ a ] -> [ b ]
myMap _ [] = []
myMap f (x:xs) = f x : myMap f xs

myFilter :: ( a -> Bool ) -> [ a ] -> [ a ]
myFilter _ [] = []
myFilter p (x:xs)
                  | p x = x : myFilter p xs
                  | otherwise = myFilter p xs

myFoldl :: ( b -> a -> b ) -> b -> [ a ] -> b
myFoldl _ acc [] = acc
myFoldl f acc (x:xs) = myFoldl f (f acc x) xs

myFoldr :: ( a -> b -> b ) -> b -> [ a ] -> b
myFoldr _ acc [] = acc
myFoldr f acc (x:xs) = f x (myFoldr f acc xs)

myPartition :: ( a -> Bool ) -> [ a ] -> ([ a ] , [ a ])
myPartition _ [] = ([], [])
myPartition p (x:xs)
                    | p x = (x : trueList, falseList)
                    | otherwise = (trueList, x : falseList)
            where
            (trueList, falseList) = myPartition p xs

myNot :: Bool -> Bool
myNot True = False
myNot False = True

myQuickSort :: ( a -> a -> Bool ) -> [ a ] -> [ a ]
myQuickSort _ [] = []
myQuickSort p (x:xs) =
                    let smaller = myQuickSort p [y | y <- xs, p y x]
                        bigger  = myQuickSort p [y | y <- xs, myNot (p y x)]
                    in myAppend (myAppend smaller [x]) bigger