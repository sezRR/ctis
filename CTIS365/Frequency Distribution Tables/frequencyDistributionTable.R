# Frequency Distribution Table

# Function to clear console
cat("\014")
# Learn R version
getRversion()
# Clearing all plots
graphics.off()
# To empty an environment
rm(list = ls())

# Creating a dataset
dataset <- c(10, 10, 9, 9, 9, 9, 9, 8, 7, 6, 6, 6, 6 ,5, 4, 4, 3, 2, 2, 2)
dataset
# Determining the data type
class(dataset)
# Printing the dataset
print(dataset, digits = 3)
# Loading the installed package "plyr"
library(plyr)   # require(plyr)

# Determining the frequency by using the "count()" function of "plyr" package
y <- count(dataset)
y
class(y)

# Structure of y
str(y)

# Renaming columns in he dataframe "y"
colnames(y) <- c("X","f")
y


y$Xf <- y$X * y$f
y
# Number of elements in dataset
#n <- length(dataset)
n <- sum(y$f)
n

# Finding and printing the proportion
y$proportion <- y$f/n
y$prop_percent <- y$proportion * 100
y
print(y, digits = 3)

# Finding and printing the cumulative frequency
y$cf <- cumsum(y$f)
y$cf_percent <- y$cf/n * 100 
print(y, digits = 3)

# Printing the vertically flipped table
print(y[nrow(y):1, ], digits = 3)

# Finding and printing the mean by using the dataset
#mean1 <- mean(dataset)
mean1 <- sum(dataset)/n
mean1
# Finding and printing the mean by using Xf
mean2 <- sum(y$Xf)/n
mean2

# Creating a barplot for the count
barplot(y$f,
        names.arg = y$X,
        main = "Frequency Distribution Plot", 
        col = c("aquamarine1", "darkgoldenrod1", "khaki2", "Green", "Cyan", "Grey", "Brown", "Purple", "Pink"), 
        xlab = "Category", 
        ylab = "Frequency")
