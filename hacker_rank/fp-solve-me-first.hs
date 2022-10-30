add a b = a + b

main = do
    putStrLn $ id "enter number 1:"
    a <- readLn
    putStrLn $ id "enter number 2:"
    b <- readLn
    let c = add a b
    putStrLn $ id "the sum is:"
    print c
