# A R script to learn the basic syntax of R
# Vectors and matrices are discussed here

# In R all indexes/indices start from 1
# Use CTRL + L to clear the console
# Use CTRL + Enter to execute the script line by line
# Use mouse to select a group of lines and press CTRL + Enter to execute the selected block of code

# All elements in a vector and matrix should have the same data type. If any 
# element is a character then all elements will be converted to characters

# Difference between integer class and numeric class in R
# https://stackoverflow.com/questions/23660094/whats-the-difference-between-integer-class-and-numeric-class-in-r

# Function to clear console
cat("\014")
# Learn R version
getRversion()
# Clearing all plots
graphics.off()
# To empty an environment
rm(list = ls())
# Prints version information about R, OS and attached packages
sessionInfo(package = NULL)

a <- 1:10                 # Use (ALT -) to insert the assignment operator
print("Vector a is")
a
typeof(a)                 # typeof() determines the (R internal) type or storage mode of any object

b <- seq(1, 10, by = 1)
print("Vector b is")
b

c <- c(1:8, 9, 10)
print("Vector c is")
c

# Generating 10 random numbers between 1-5. The numbers are not unique
d <- sample(1:5, size = 10, replace = T)
print("Vector d is")
d

e <- a
print("Vector e is")
e

f <- rep(10, 5)    # creates a vector with identical/same values
print("Vector f is")
f

a.length <- length(a)
print("Vector a length")
a.length

cat("First 3 elements of Vector \"a\"")
a[1:3]
cat("All elements of Vector 'a' except the 3rd element")
a[-3]

cat("All elements of Vector 'a' except the last element")
a[1:length(a) - 1]
head(a, n = length(a) - 1)
head(a, n = -1)
a[-length(a)]

a
# Some examples using the minus index
a[c(-1, -2)]
a[-c(1, 2)]       # same as above
a[-c(1, 10)]

cat("All elements of Vector 'a' except the first element")
a[2:length(a)]
tail(a, n = length(a) - 1)
tail(a, n = -1)
a[-1]

cat("Split all elements of Vector 'a' by even and odd index")
a.odd <- a[seq(1, length(a), 2)]
a.odd
# If logical vectors are used for indexing in R, their values are recycled if the index vector is shorter than the vector containing the values
a
a.even <- a[c(FALSE, TRUE)]
a.even

# Pay attention to the syntax 
cat("All elements of Vector 'a' greater than 5")
g <- a
g
g > 5
g[g > 5]
g

# Setting all values greater than 5 to -1
g[g > 5] <- -1
g
# Setting all values NOT equal to -1 to 10
g[!(g == -1)] <- 10
g

# Using R's plotting utility (a is x-axis data and d is y-axis data)
plot(x = a,
     y = e,
     main = "Straight Line",
     xlab = "x-axis",
     ylab = "y-axis",
     type = "l",
     col = "Light Salmon",
     lwd = 3)
# Line types and colors in R
# http://www.sthda.com/english/wiki/line-types-in-r-lty
# https://www.stat.auckland.ac.nz/~ihaka/downloads/R-colours-a4.pdf
grid (NULL, NULL, lty = 6, col = "azure2") 

# https://www.r-exercises.com/2017/09/28/how-to-plot-basic-charts-with-plotly/
library(plotly)
packageVersion('plotly')
plot_ly (
  x = a,
  y = e,
  type = "scatter",
  line = list(color = '#FF0000'),     # line color
  mode = "lines")

detach("package:plotly", unload = TRUE)

# Creating and using matrices
matrix1 <- matrix(1:9, nrow = 3, ncol = 3)
matrix1

cat("First row of the matrix\n")
matrix1[1,]
matrix1
cat("All rows except 2 and all columns except 3\n")
matrix1[-2,-3]

matrix2 <- matrix(1:9, nrow=3, byrow = TRUE)    # fill matrix row-wise
matrix2

cat("Creating a matrix by defining columns\n")
matrix3 <- cbind(c(1,2,3), c(4,5,6), c(7,8, 9))
matrix3

cat("Creating a matrix by defining rows\n")
matrix4 <- rbind(c(1,2,3), c(4,5,6), c(7,8,9))
matrix4

num.row <- nrow(matrix4)              # num.row is a variable name
cat("Number of rows in a matrix\n")
num.row
  
num.col <- ncol(matrix4)              # num.col is a variable name
cat("Number of columns in a matrix\n")
num.col

matrix5 <- matrix(1:9, nrow=3, byrow = TRUE)    # fill matrix row-wise
matrix5
colSums(matrix5)            # columnwise sum
rowSums(matrix5)            # rownwise sum
colMeans(matrix5)           # columnwise mean
rowMeans(matrix5)           # rowumnwise mean
sum(matrix5)                # sum of all elements 
mean(matrix5)               # mean of all elements

matrix5

# https://www.datacamp.com/community/tutorials/r-tutorial-apply-family
# To use apply function make sure that you have numeric data for mathematical operations
apply(matrix5, MARGIN = 1, FUN = sum)       # row-wise sum
apply(matrix5, MARGIN = 2, FUN = sum)       # column-wise sum

# Creating a matrix with missing values
matrix6 <- cbind(c(NA,2,3), c(4,NA,6), c(7,8,NA))
matrix6

# which command allows us to get the index of TRUE values/items
temp <- c(T, T, F, F, T)
typeof(temp)
which(temp)
#which(!temp)   # index of FALSE values/items


# The all() and any() commands process the entire vector and report an overall single condition
all(temp)       # All elements TRUE. Answer is FALSE
any(temp)       # Any element TRUE. Answer is TRUE
all(a > 5)      # All elements of vector a > 5. Answer is FALSE
any(a > 5)      # Any element of vector a > 5. Answer is TRUE


# Seeing the missing values
is.na(matrix6)

# Creating index for missing values
index <- which(is.na(matrix6), arr.ind = TRUE)
index
matrix6[index]
matrix6

# Replace missing values with the column-wise sum after removing NA
# be careful here. If a column will have no missing values, then what will happen?
# or what if there are multiple missing values in a column then what will happen?
matrix6[index] <- apply( matrix6, MARGIN = 2, function(x)(sum(x, na.rm = T)) )
matrix6

# replacing missing values by 10
#matrix6[index] <- 10
#matrix6

apply( matrix6, MARGIN = 2, function(x)(sum(x, na.rm = T)) )


# Finding area under the curve (AUC)
# Area of a trapezoid is 0.5 * (a + b) * h
x <- seq(0, 5, 0.1)
y <- x                   # linear line 0 - 5
plot(x,y)
a <- head(y, n = -1)     # all elements except the last one (a)
b <- tail(y, n = -1)     # all elements except the first one (b)
h <- diff(x)             # difference between the elements (h)
AUC <- sum( 0.5 * (a + b) * h )
AUC