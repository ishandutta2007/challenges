helloWorld 0 = putStr ""
helloWorld x = do putStrLn "Hello World!"
                  helloWorld (x-1)
main = do
    helloWorld 4
