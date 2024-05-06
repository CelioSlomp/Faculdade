-- Ex1 ---------------------------------------

-- main = do
--  putStrLn (show (1 + 1))

{-
  Ele retorna em string algum valor, como por exemplo o valor númerico
  de '1+1', em putStrLn retornaria erro, mas com o show não

  show a => a -> String
-}

-- Ex2 ---------------------------------------

nUltimos :: Int -> [a] -> [a]
nUltimos y [] = []
nUltimos y (x : xs)
  | y == length (x : xs) = x : xs
  | otherwise = nUltimos y xs

-- main = do
--  print (nUltimos 5 [1 .. 100])

-- Ex3 ---------------------------------------

-- Exercicio 16 da lista 6
filtraLista :: (Eq a) => [a] -> [a]
filtraLista [] = []
filtraLista (x : xs)
  | x `elem` xs = filtraLista xs
  | otherwise = x : filtraLista xs

interseccao :: (Eq a) => [a] -> [a] -> [a]
interseccao [] [] = [] -- Verifica se as listas estao vazias
interseccao (x : xs) [] = x : xs -- Verifica se alguma lista está vazia
interseccao [] (x : xs) = x : xs
interseccao (x : xs) (y : ys) -- Ambas tem itens
  | x `elem` xs || y `elem` ys = interseccao (filtraLista (x : xs)) (filtraLista (y : ys))
  | x `notElem` (y : ys) = x : interseccao xs (y : ys)
  | otherwise = interseccao xs (y : ys)

-- main = do
--  print (interseccao [10 .. 50] [1 .. 25])

-- Ex4 ---------------------------------------

convBin :: Int -> String
convBin x
  | x > 0 = convBin (div x 2) ++ show (mod x 2)
  | otherwise = ""

-- main = do
--  print (convBin 255)

-- Ex5 ---------------------------------------

ePar :: [Int] -> Bool
ePar (x : xs) = even x

listaDuplas :: [[Int]] -> [[Int]]
listaDuplas [] = []
listaDuplas (x : xs)
  | ePar x = x : listaDuplas xs
  | otherwise = listaDuplas xs

-- main = do
--  print (listaDuplas [[1, 2], [2, 3], [4, 6], [5, 7], [8, 8]])

-- Ex6 ---------------------------------------

possuiDigito :: Char -> Bool
possuiDigito x = x `notElem` "0123456789"

remDigitos :: [Char] -> [Char]
remDigitos [] = []
remDigitos (x : xs) = filter possuiDigito (x : xs)

-- main = do
--  print (remDigitos "123patos32 s543ai65ram 3122p09ara c978ami987nha43r")

-- Ex7 ---------------------------------------

calcTam :: [Char] -> Int
calcTam = foldr (\x -> (+) 1) 0

concatTamanho :: [String] -> [String]
concatTamanho = map (\x -> x ++ show (calcTam x))

-- main = do
--  print (concatTamanho ["casa", "predio", "computador", "monitor"])

-- Ex8 ---------------------------------------

listaDobrada :: [String] -> [String]
listaDobrada [] = []
listaDobrada x = zipWith (++) x x

-- Descobri agora que não precisa do (x:xs) :/

-- main = do
--  print (listaDobrada ["casa", "predio", "computador", "monitor"])

-- Ex9 ---------------------------------------

-- Ex10 --------------------------------------

main = do
  print $ show $ 4 * 5
  print $ show (4 * 5) ++ " uma frase de fato " ++ show (5 + 2)

{-
  Ele utiliza o $ para reduzir os parenteses. Mas não funciona no caso de baixo.
  Ele dá problema quando o show não está sozinho.

  print $ show (4 * 5) ++ " uma frase de fato " ++ show $ 5 + 2
-}
