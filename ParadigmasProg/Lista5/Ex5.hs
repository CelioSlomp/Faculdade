module Ex5 where

incremento :: (Num a) => a -> a
incremento x = x + 1

decremento :: (Num a) => a -> a
decremento x = x - 1

-- decremento (incremento 9)
-- decremento (incremento 9) :: Num a => a -- Resulta em 9.