import Data.Char (isUpper, toUpper)

-- Ex1 ---------------------------------------

calcCirc :: (Floating r) => r -> r
calcCirc r = pi * (r ** 2)

-- main = do
--  let r = 2.0
--  print (calcCirc r)

-- Ex2 ---------------------------------------

triangulo :: Int -> Int -> Int -> [Char]
triangulo x y z
  | x > (y + z) || y > (x + z) || z > (x + y) = "NAOTRI"
  | x == y && y == z = "Equilatero"
  | x == y || x == z || y == z = "Isosceles"
  | otherwise = "Escaleno"

-- main = do
--  print (triangulo 5 4 3)

-- Ex3 ---------------------------------------

multiplica :: Int -> Int -> Int
multiplica x y
  | x < 0 && y < 0 = multiplica (x * (-1)) (y * (-1))
  | y == 0 = 0
  | y < 0 = (-x) + multiplica x (y + 1)
  | otherwise = x + multiplica x (y - 1)

-- main = do
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
menor x y z
  | x <= y && x <= z = x
  | y <= x && y <= z = y
  | otherwise = z

maior :: Int -> Int -> Int -> Int
maior x y z
  | x >= y && x >= z = x
  | y >= x && y >= z = y
  | otherwise = z

-- main = do
--  print (menor 6 8 5)
--  print (maior 9 7 5)

-- Ex6 ---------------------------------------

xor :: Bool -> Bool -> Bool
xor x y
  | x && y = False
  | not x && not y = False
  | otherwise = True

-- Fazendo uma tabela verdade
-- main = do
--  print (xor True True)
--  print (xor True False)
--  print (xor False True)
--  print (xor False False)

-- Ex7 ---------------------------------------

duplicaLista :: [a] -> [a]
duplicaLista [] = []
duplicaLista (x : xs) = [x] ++ [x] ++ duplicaLista xs

-- main = do
--  print (duplicaLista [5, 2, 3])

-- Ex8 ---------------------------------------

someValores :: [a] -> [a]
someValores [] = []
someValores (x : xs) = drop 1 xs -- drop N [List] -> retira N elementos de [List]

-- main = do
--  print (someValores [1 .. 10])

-- Ex9 ---------------------------------------

listaZeroNum ::  Int -> [Int]
listaZeroNum x
  | x < 0 = listaZeroNum (x * (-1))
  | x == 0 = [0]
  | otherwise = listaZeroNum (x - 1) ++ [x]

-- main = do
--  print (listaZeroNum (-10))

-- Ex10 --------------------------------------

parOuImpar :: [Int] -> [Bool]
parOuImpar [] = []
parOuImpar (x : xs)
  | mod x 2 == 1 = False : parOuImpar xs
  | otherwise = True : parOuImpar xs

-- main = do
--  print (parOuImpar [1 .. 10])

-- Ex11 --------------------------------------

soPar :: [Int] -> [Int]
soPar [] = []
soPar (x : xs)
  | even x = x : soPar xs -- funcao para ver se é par
  | otherwise = soPar xs

-- main = do
--  print (soPar [1 .. 100])

-- Ex12 --------------------------------------

soMinusculas :: [Char] -> [Char]
soMinusculas [] = []
soMinusculas (x : xs)
  | isUpper x = soMinusculas xs
  | otherwise = x : soMinusculas xs

-- main = do
--  print (soMinusculas "abCdeABCDE")

-- Ex13 --------------------------------------

substituiVogais :: [Char] -> [Char]
substituiVogais [] = []
substituiVogais (x : xs)
  | x `elem` "aeiou" = toUpper x : substituiVogais xs -- o intellisense falou pra colocar no infixo. Achei podre.
  | otherwise = x : substituiVogais xs

-- main = do
--  print (substituiVogais "TEstando esta FrAse")

-- Ex14 --------------------------------------

addFriboi :: [String] -> [String]
addFriboi = map (++ " Friboi") -- funcao map adiciona algo em todos os elementos da lista

-- main = do
--  print (addFriboi ["bla", "Celio", "Poetico"])

-- Ex15 --------------------------------------

pertence :: Int -> [Int] -> Bool
pertence _ [] = False
pertence y (x : xs)
  | y == x = True
  | otherwise = pertence y xs

main = do
  print (pertence 10 [0])

-- Ex16 --------------------------------------

filtraLista :: (Eq a) => [a] -> [a] -- Intellisense pediu pra colocar esse (Eq a)
filtraLista [] = [] -- Pelo o que eu entendi, o (Eq a) é para que a seja alguma das 'classes'
filtraLista (x : xs) -- que Eq possui, então é quase todas as da linguagem.
  | x `elem` xs = filtraLista xs
  | otherwise = x : filtraLista xs

-- main = do
--  print (filtraLista [1, 2, 3, 4, 1, 2, 3, 6, 7, 8])

-- Ex17 --------------------------------------

nPrimeirosElem :: (Eq a) => Int -> [a] -> [a]
nPrimeirosElem y [] = []
nPrimeirosElem y (x : xs)
  | y > 0 = x : nPrimeirosElem (y - 1) xs
  | otherwise = []

-- main = do
--  print (nPrimeirosElem 5 [1 .. 10])

-- Ex18 --------------------------------------

multTres :: Int -> [Int]
multTres x
  | mod x 3 == 0 = x : multTres (x + 1)
  | x > 300 = []
  | otherwise = multTres (x + 1)

-- main = do
--  print (multTres 0)