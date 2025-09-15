data_frame <- data.frame(
  subjects = c("P", "C", "M"),
  marks = c(100, 150, 120),
  attendance = c(60, 30, 45)
)

data_frame

data_frame$Grade <- c("A", "B", "C")  #add column

data_frame

new_row <- data.frame(subjects = "P", marks = 140,attendance = 70, Grade = "D")
data_frame <- rbind(data_frame, new_row)    #add row

data_frame

mat <- matrix(letters[1:16], nrow = 4, ncol = 4, byrow = TRUE)

colnames(mat) <- c("C1", "C2", "C3", "C4")
rownames(mat) <- c("R1", "R2", "R3", "R4")

mat

mat <- rbind(mat, "R5" = matrix(c("Q", "R", "S", "T"), nrow = 1))

mat

mat <- cbind(mat, "C5" = matrix(c("U", "V", "W", "X", "Y"), ncol = 1))

mat

mat <- mat[-3, ]

mat
