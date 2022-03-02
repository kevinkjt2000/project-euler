import Data.Bits (xor)
import Data.Char (chr, ord)
import Data.Foldable (toList)
import Data.List (isInfixOf)
import Data.List.Split (splitOn)
import Data.Sequence (replicateM)
import System.IO (readFile)

decrypt :: [Int] -> [Int] -> [Int]
decrypt key message =
    zipWith xor message (cycle key)

validate :: [Int] -> Bool
validate message =
    let words = map (map ord) ["the", "and", "be"]
    in all id [isInfixOf w message | w <- words]

main :: IO ()
main = do
    file <- readFile "p059_cipher.txt"
    let encCharCodes = map read $ splitOn "," file :: [Int]
    let alphaCharCodes = map ord ['a'..'z']
    let possibleKeys = replicateM 3 alphaCharCodes
    let possibleDecrypts = [(k, decrypt k encCharCodes) | k <- map toList possibleKeys]
    let validDecrypts = filter (validate . snd) possibleDecrypts
    putStrLn $ show $ map (\(k,m) -> (k, map chr m, sum m)) validDecrypts
