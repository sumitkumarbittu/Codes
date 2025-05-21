#b <- read.table("a.csv", sep = ",", header = TRUE)
#c <- read.csv("a.csv")

#View(b)
#View(c)

#c$c

#c[1,1]

#c$c[1]


students <- read.csv("b.csv")

View(students)

students$Physics

sum(students$Physics)

sum(students$Physics + students$Chemistry)

students$Marks <- students$Physics + students$Chemistry

write.csv(students, "c.csv", row.names = FALSE)
