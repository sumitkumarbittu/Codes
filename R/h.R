install.packages('caTools')

library(caTools)

split = sample.split(data$Salary, SplitRatio = 0.7)
trainingset = subset(data, split == TRUE)
testset = subset(data, split == FALSE)

lm.r = lm(formula = Salary ~ Years_Exp,
          data = trainingset)

summary(lm.r)

