import Data.Function (fix)

fatorial :: (Integer -> Integer) -> Integer -> Integer
fatorial = \f x -> if x == 0 then 1 else x*f (x-1)

main = do
    a <- readLn :: IO Integer
    putStrLn $ show $ fix fatorial a