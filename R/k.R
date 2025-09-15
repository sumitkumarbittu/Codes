is_prime <- function(n) {
  if(n <= 1) {
    return(FAlSE)
  }
  if(n == 2) {
    return(FALSE)
  }
  if(n %% 2 == 0) {
    return(FALSE)
  }
  for(i in seq(3, sqrt(n), by = 2)) {
    if(n%%i == 0) {
      return(FALSE)
    }
  }
  return(TRUE)
}

numbers <- 50:100

print(numbers[sapply(numbers, is_prime)])
