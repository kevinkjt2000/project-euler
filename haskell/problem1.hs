import qualified Data.Set as Set 

main :: IO ()
main = do
    let threes = Set.fromList [3,6..999]
    let fives = Set.fromList [5,10..999]
    let answer = Set.foldl (+) 0 $ Set.union threes fives
    print answer