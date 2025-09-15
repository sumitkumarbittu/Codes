#Linear Regresssion

sugar_consumption <- c(151, 166, 148, 186, 138, 135, 189, 143, 152, 132)
sulphur <- c(64, 85, 58, 92, 45, 58, 78, 74, 65, 49)

data <- data.frame(Sugar = sugar_consumption, Sulphur = sulphur)

model <- lm(Sulphur ~ Sugar, data = data)

summary(model)

new_data <- data.frame(Sugar = 160)

prediction <- predict(model, newdata = new_data)

print(paste("Prediction : ",prediction))
