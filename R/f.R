assign("x", c(1, 3, 5,7))
1/x

x^2<-4

roots <- polyroot(c(6, -5, 1))
roots

a<-7
b<-5
v <- 2*a + b +1
v

f <- function(x) { x^3 - 2*x -5 }
root <- uniroot(f, interval = c(1,3))
print(root$root)

sqrt(-16+0i)

