# Initially discusses a data frame and tibble. Then demonstrates how to read a file.
# Part1 : R script that will convert selected columns to a currency format
# Part2 : R script that will read the data from a file and will display the row(s) of maximum and minimum temperature


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

# Get the working directory
getwd()

# Update this based on your Operating System (OS) and the used directory
# Can also use Session Menu's Set Working Directory option
# Windows (Windows uses forward slash)
setwd("D:/MyWork/MyTeaching/Spring 2021-2022/CTIS 365/RScripts")
getwd()

# Mac OS  (Mac uses back slash)
#setwd("D:\MyWork\MyTeaching\Spring 2021-2022\CTIS 365/RScripts")



# Creating and using matrices
matrix1 <- matrix(1:9, nrow = 3, ncol = 3)
matrix1

# Converting a matrix to a data frame
df <- as.data.frame(matrix1)
df

# Changing the column names
colnames(df) <- c("X1", "X2", "X3")
df

library(tidyverse)      # It is a set of essential packages for data science
tbl1 <- as_tibble(matrix1)
tbl1


#library(dplyr)         # no need as it is part of tidyverse
slice(tbl1)
tbl1 %>% slice()        # dplyr implementation of the pipe operator is %>% (default is |>) 

# Another example of pipe operator
cc <- c(1, 2, 3, NA)
cc %>% sum(na.rm = T)
cc %>% sum(., na.rm = T)

# Pipe operator when the input is not the first argument (. is used)
# Generating 20 letters randomly and replacing letter 'A' with 'R programming'
dd <- sample(LETTERS[1:26], 20, replace = TRUE)
dd
dd %>% gsub('A', 'R programming', ignore.case = TRUE, x = .)

# Changing the column names of tibble
colnames(tbl1) <- c("T1", "T2", "T3")
tbl1

# Converting a data frame to tibble
df
tbl2 <- as_tibble(df)
tbl2
detach("package:tidyverse", unload = TRUE)
#detach("package:dplyr", unload = TRUE)     # part of tidyverse


#=========================== P A R T 1 ===========================
# Creating a data frame with 3 numeric and 1 factor column 
df1 <-  data.frame(x1 = 10001:10010,
                   x2 = 11:20,
                   x3 = 21:30,
                   x4 = LETTERS[1:10])

df1$x1            # x1 column of the data frame df1
df1$x1[1:3]

# The upper approach is better
df1[1]            # first column of the data frame df1
df1[1:2]          # first and second columns of the data frame df1


# Object summary
summary(df1)

# The structure of an R Object
str(df1)

# Custom function to apply an operation to only certain column types of dataset
func1 <-  function(x) {
  if (is.numeric(x))                          # Test if input is numeric
    paste0('$', format(x, big.mark = ','))    # If TRUE, format as currency (Concatenate)
  else 
    as.character(x)                           # If FALSE, return as character
}

# lapply returns a list of the same length as df1
x <-  lapply(df1, func1)
x


y <-  data.frame(x)     # convert the list to a data frame
y
str(y)


#=========================== P A R T 2 ===========================
# Reading the file
#df2 <- read.delim("citiesTemperature.txt", header = T)    # Don't use this. Why?
#df2


# Read the file as a tibble
#tbl3 <- read_delim("citiesTemperature1.txt", delim = " ")
#tbl3
#str(tbl3)


df2 <- read.delim("citiesTemperature.txt", sep = " ", header = T)
df2

# Object summary
summary(df2)

# The structure of an R Object
str(df2)

# Display the first 6 rows of data
head(df2, n = 10)


# Custom function to apply an operation to only certain column types of dataset
func2 <-  function(x) {
  if (is.numeric(x)) {          # Test if input is numeric
    #match(max(x), x)           # Gives the index of only the first matching element
    which( x %in% max(x) )      # Gives the index of all matching element (to get help type  ?'%in%' or check help for match)
  }                         
}


which.max(df2$temperature)     # Gives the index of only the first maximum element
which.min(df2$temperature)     # Gives the index of only the first minimum element


# Maximum temperature (Approach 1)
result <- lapply(df2, FUN = func2)
result
index <- unlist(result, use.names = FALSE)
index
df2[index, ]      # leaving an empty index argument means all elements

# Maximum temperature (Approach 2)
#df2$temperature == max(df2$temperature)
max.index <- which(df2$temperature == max(df2$temperature))   # which --> Gives the TRUE indices of a logical object
max.index
df2[max.index, ]      # max.index row(s) and all columns


# Minimum temperature
#df2$temperature == min(df2$temperature)
min.index <- which(df2$temperature == min(df2$temperature))   # which --> Gives the TRUE indices of a logical object
min.index
df2[min.index, ]      # min.index row(s) and all columns
