fibonacci :: Integer -> Integer -> Integer -> Integer
fibonacci x _ 0 = x
fibonacci x y z = fibonacci y (x+y) (z-1) 

om 0 = return ()
om x = do
    val <- readLn :: IO Integer
    
    putStrLn $ "Fib(" ++ show val ++ ") = " ++ show (fibonacci 0 1 val)
    om (x-1)

main :: IO()
main = do
    a <- readLn :: IO Integer
    om a