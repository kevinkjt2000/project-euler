import Data.List (nub, sort)
import Data.List.Split (chunksOf)

polygonals = [[n * (k*n - k+2) `div` 2 | n <- [1..]] | k <- [1..6]]
fourDigitPolys = map (dropWhile (< 1000) . takeWhile (< 10000)) polygonals

bigrams = map (map (chunksOf 2 . show)) fourDigitPolys

answer = 5

main :: IO ()
main = putStrLn $ show answer
