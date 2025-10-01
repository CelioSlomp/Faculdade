import Data.Function (fix)

fatorial :: (Integer -> Integer) -> Integer -> Integer
fatorial = \f x -> if x == 0 then 1 else x*f (x-1)

--main = do
--    a <- readLn :: IO Integer
--    putStrLn $ show $ fix fatorial a

om [] = return ()
om (x:xs) = do
    putStrLn $ show x
    om xs

main :: IO() -- Pega uma linha com N valores 
main = do
    a <- getLine
    let b = map read (words a) :: [Int]
    om b