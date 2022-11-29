-- Enter your code here. Read input from STDIN. Print output to STDOUT
prefix [] _ = ""
prefix _ [] = ""
prefix (x:xs) (y:ys)
  | x == y = x:prefix xs ys
  | otherwise = ""

compress x y =
  let p = prefix x y
      len = length p
      lenx = length x - len
      leny = length y - len
  in map (\(l, s) -> unwords [show l, s]) [(len, p), (lenx, drop len x), (leny, drop len y)]

main = do
  x <- getLine
  y <- getLine
  putStrLn $ unlines $ compress x y
