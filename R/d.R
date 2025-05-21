Car <- data.frame(
  row.names = c("Tata", "Hyundai", "Toyota"),
  Model = c("Nexon", "Creta", "Fortuner"),
  price = c(9.5, 11, 45),
  type = c("Suv", "Sedan", "Suv")
)

Car

Car$Model

Car$price

Car[1]          #data frame

Car[[1]]        #data series column

Car[, 2]        #data Series column

Car[1, 1]       

Car["Tata", ]   #access by row name
