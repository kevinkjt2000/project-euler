module Main where
import Data.Function (on)
import qualified Data.List as List
import Data.Tuple.Select

f x y = [x+y,x*y,x-y,y-x,x/y,y/x]

isInt x n = (round $ 10^(fromIntegral n)*(x-(fromIntegral $ round x)))==0

isPositive = (>0)

filterConsecutive list@(head:_) = 
    copyWhileEqual list [head..]
    where copyWhileEqual [] _ = []
          copyWhileEqual (h1:t1) (h2:t2)
              | h1 == h2 = h1 : copyWhileEqual t1 t2
              | otherwise = []

twos = [(a, b, f a b) | a <- [1..9], b <- [2..9], a < b]

main :: IO ()
main = do
    let stuff = [(a,b,c,d, filterConsecutive $ List.sort $ List.nub $ map round $ filter isPositive $ filter (\x -> isInt x 7) $ concat $ concat $ map (map (f d) . f c) $ f a b) | a <- [1..9], b <- [2..9], c <- [3..9], d <- [4..9], a < b, b < c, c < d]
    print $ List.maximumBy (compare `on` (length . sel5)) stuff