# This is my first R script

x <- 34
y <- 16
z <- x + y # or z <- sum(x, y)
w <- mean(c(x,y ))

cat(x, y, z, w, sep= ", ")

midterm_grades <- read.delim("midterm.txt") # or scan("midterm.txt", numeric())
final_grades <- read.delim("final.txt") # or scan("final.txt", numeric())

scores <- midterm_grades * 0.4 + final_grades * 0.6

pass_index <- scores > 40
pass_grades <- scores[pass_index]

matrix <- cbind(midterm_grades, final_grades, scores)
colnames(matrix) <- c("midterm", "final", "grade")

matrix

