-- Ex1 ---------------------------------------

calcCirc :: (Floating r) => r -> r
calcCirc r = pi * (r ** 2)

-- main = do
--  let r = 2.0
--  print (calcCirc r)

-- Ex2 ---------------------------------------

-- Ex3 ---------------------------------------

multiplica :: Int -> Int -> Int
multiplica x y =
  if x < 0 && y < 0 
    then multiplica (x * (-1)) (y * (-1)) 
  else if y == 0
    then 0
    else if y < 0 
      then (-x) + (multiplica x (y + 1))
      else x + multiplica x (y - 1)

--main = do
--  print (multiplica (-6) 5)

-- Ex4 ---------------------------------------

multiplicaNaturais :: Int -> Int -> Int
multiplicaNaturais x y = 
  if y == 0
    then 0
    else x + multiplicaNaturais x (y - 1)

-- main = do
--   print (multiplicaNaturais 4 5)

-- Ex5 ---------------------------------------

menor :: Int -> Int -> Int -> Int
menor x y z = 
  if x <= y && x <= z 
    then x
  else if y <= x && y <= z 
    then y
  else z

maior :: Int -> Int -> Int -> Int
maior x y z = 
  if x >= y && x >= z 
    then x
  else if y >= x && y >= z 
    then y
  else z

--main = do
--  print (menor 6 8 5)
--  print (maior 9 7 5)


-- Ex6 ---------------------------------------

xor :: Bool -> Bool -> Bool
xor x y 
  | (x && y) = False
  | ((not x) && (not y)) = False
  | otherwise = True

--main = do
--  print (xor True True)
--  print (xor True False)
--  print (xor False True)
--  print (xor False False)

-- Ex7 ---------------------------------------

duplicaLista :: [a] -> [a]
duplicaLista [] = []
duplicaLista (x:xs) = [x] ++ [x] ++ duplicaLista xs

--main = do
--  print (duplicaLista [5, 2, 3])

-- Ex8 ---------------------------------------

-- Ex9 ---------------------------------------

-- Ex10 --------------------------------------

-- Ex11 --------------------------------------

-- Ex12 --------------------------------------

-- Ex13 --------------------------------------

-- Ex14 --------------------------------------

-- Ex15 --------------------------------------

-- Ex16 --------------------------------------

-- Ex17 --------------------------------------

-- Ex18 --------------------------------------
