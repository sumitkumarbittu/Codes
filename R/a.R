a <- as.integer(readline("a : "))
b <- readline("b : ")
c <- readline("c : ")
d <- readline("d : ")

b <- as.integer(b)
c <- as.integer(c)
d <- as.integer(d)

total <- a+b+c
total0 <- sum(a,b,c,d)

print(paste("Total : ", total))
print(paste("Total : ", total0))
