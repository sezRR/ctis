getwd()

mtcars
mtcars_table <- table(mtcars$gear)
mtcars_table

?plot
barplot(mtcars_table, main = "Car Distribution", xlab = "Number of Gears")
