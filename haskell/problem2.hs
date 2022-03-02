import Data.List

fib n = fibr 0 1 n
fibr a b 0 = a
fibr a b n = fibr b (a+b) (n-1)

main :: IO ()
main = do
    print $ sum $ filter even $ takeWhile (<4000000) $ map fib [1..]
