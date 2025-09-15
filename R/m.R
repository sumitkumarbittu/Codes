data(mtcars)

model <- lm(mpg ~ disp + hp + wt, data = mtcars)

prediction <- predict(model, newdata = data.frame(disp=202, hp=102, wt=2.91))

print(prediction)

plot(model)

