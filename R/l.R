# Sample data
diet_A <- c(3, 5, 6, 7, 2)
diet_B <- c(8, 9, 10, 11, 7)
diet_C <- c(12, 14, 16, 15, 13)

# Combine into a data frame
data <- data.frame(
  weight_loss = c(diet_A, diet_B, diet_C),
  diet_group = factor(rep(c("A", "B", "C"), each = 5))
)

# Kruskal-Wallis Test
kruskal.test(weight_loss ~ diet_group, data = data)

