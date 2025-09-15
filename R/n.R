employee <- data.frame(
  emp_id = c(1:5), emp_name = c("A","B","C","D","E"), emp_sal = c(10001:10005)
)

summary(employee)

employee

print(paste(employee$emp_id, employee$emp_sal))

employee[is.na(employee$emp_gen), "emp_gen"] <- c("M", "F", "M", "M", "F")

employee <- rbind(employee, data.frame(emp_id = 6, emp_name = "F", emp_sal = 10006, emp_gen = "F"))

row.names(employee) <- employee$emp_name

employee <- employee[,-2]

employee <- employee[-3,]

rownames(employee) <- c("R1", "R2", "R3")

colnames(employee) <- c("C1", "C2")
