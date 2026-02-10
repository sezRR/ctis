# A R script to learn about lists
# Lists allow us to store objects of different types (i.e., vectors, matrices, data frame, list etc.) with different sizes

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

# Create a list containing strings, numbers, vectors and a logical values
list1 <- list("Red", "Green", c(21,32,11), TRUE, 51.23, 119.1)
list1

# Create a list containing a vector, a matrix and a list
list2 <- list(c("Jan","Feb","Mar"), matrix(c(3, 9, 5, 1, -2, 8), nrow = 2), list("green", 12.3))
list2

# Access the second element in the list
list2[[2]]

# Access the second element in the list (which is a matrix) and then return the element at index [1,1]
list2[[2]][1,1]

# Access the second element in the list (which is a matrix) and then return all the elements of the first row
list2[[2]][1,]

# Give names to the elements in the list
names(list2) <- c("Months", "Matrix", "Inner list")
list2

# Access the third element in the list. As it is also a list, all its elements will be printed
list2[3]

# Access a list element by using the name of the element
list2$Matrix
list2$`Inner list`    # see the back quote syntax

list3 <- list( c(10, 20, 40, 50), c(50, 10, 30), c(80, 80, 75) )
list3

# Find the minimum value for each list element
lapply(list3, min)

# Find the mean value for each list element
lapply(list3, mean)


# Find the mean value for each list element and convert to a vector
vector1 <- round( unlist( lapply(list3, mean) ), digits = 2) 
vector1
