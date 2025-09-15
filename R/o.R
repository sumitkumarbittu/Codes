matrix <- matrix(
  c("J","F","M","A","M","J","Jul","Au","S"), nrow = 3, ncol = 3, byrow = TRUE
)

matrix

matrix <- cbind(matrix, new = c("O", "N", "D"))

matrix <- rbind(matrix, nn = c("p", "p", "p", "p"))
