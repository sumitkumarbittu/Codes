friend.data <- data.frame(
  friend_id = c(1:5),
  friend_name = c("Sachin","sourav",
                  "Dravid", "Sehwag",
                  "Dhoni"),
  stringsAsFactors = FALSE
)

result <- data.frame(())

friend.data[1]

friend.data[['friend_name']]

friend.data$friend_id

dim(friend.data)



friend.data$location <- c("Kolkata", "Delhi",
                          )






Products <- data.frame(
  Product_id = c(101,102,103), 
  Product_Name = c("T-shirt", "Jeans", "Shoes"),
  Price = c(15.99, 29.99, 49.99),
  Stock = c(50, 30, 20)
)

cat("Existing dataframe (Products):\n")
print(Products)

Discount <- c(5,10,8)



library(dplyr)

data <- data.frame(
  friend_id = c(1, 2, 3, 4, 5),
  friend_name = c("Sachin", "Sourav", "Dravid", "Sehwag", "Dhoni"),
  location = c("Kolkata", "Delhi", "Bangalore", "Hydrabad", "Chennai")
)
data

data <- select(data, -location)
data
