module Problem66 where
import Math.NumberTheory.Powers.Squares (integerSquareRoot, isSquare)

-- I just looked up the first 1000 on this list
-- http://oeis.org/A033313/b033313.txt
-- 636 was the winner
-- ds !! 635   was the answer

notSquare = not . isSquare

-- let's precompute some values
squares = [x*x-1 | x<-[2..]]
ds = [d | d<-[2..1000], notSquare d]
-- findMinimalX :: Integer -> Integer
findMinimalX d =
    let filterSquares = filter (\s -> s `mod` d == (0::Integer) && isSquare (s `div` d)) squares
        pairs = [(x, y) | s<-filterSquares, x<-[integerSquareRoot (s+1)], y<-[integerSquareRoot (s`div`d)]]
    in head [(x, d, y) | (x, y)<-pairs, diophantine x y d]

diophantine x y d = 1 == x*x - d*y*y

main :: IO ()
main = print $ map findMinimalX ds
-- main = print $ maximum $ map ((\(x,_,_)->x) . findMinimalX) ds