# Variability (Variance and Standard Deviation)

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

# Let's assume that we have the following population data
dataset <- c(10, 10, 9, 9, 9, 9, 9, 8, 7, 6, 6, 6, 6 ,5, 4, 4, 3, 2, 2, 2)
# Printing the dataset
print(dataset, digits = 3)
# Loading the installed package "plyr"
library(plyr)   # require(plyr)

# Determining the frequency by using the "count()" function of "plyr" package
df <- count(dataset)

# Renaming columns in he dataframe "df"
colnames(df) <- c("X","f")
df

# order returns a permutation which rearranges its first argument 
# into ascending or descending order
#df <- df[order(nrow(df):1), ]    #invert row order
#df

# same as above
df <- df[nrow(df):1, ]          #invert row order
df


# Resetting the row numbering
rownames(df) <- NULL
df

# Finding X^2
df$"X^2" <- df$X^2
df

# Finding the mean
# mean(dataset)
N <- sum(df$f)
df.mean = sum(df$X * df$f)/N
df.mean
df$mu <- rep(df.mean, nrow(df))
df

# Finding the deviation score (X-mu)
df$"X-mu" <- df$X - df$mu
df

# Sum of deviation must be zero
print("The sum of deviation")
sum(df$`X-mu` * df$f)

# Finding the square deviation (X-mu)^2
df$"(X-mu)^2" <- df$`X-mu`^2
df

# Sum of squared deviations (Definitional formula)
df.SS1 <- sum(df$`(X-mu)^2` * df$f)
print("The sum of squared deviation")
df.SS1

# Sum of squared deviations (Computational formula)
df.SS2 <- sum(df$`X^2` * df$f) - ( (sum(df$X * df$f))^2 )/N
df.SS2

# mean squared deviation (also called variance)
df.variance1 <- df.SS1/N
df.variance2 <- df.SS2/N
df.variance1
df.variance2

# In R the "var()" function calculates the sample variance
# Making a simple adjustment to compute population variance
var(dataset) * (N - 1) / N


# Standard deviation
df.std1 <- sqrt(df.SS1/N)
df.std2 <- sqrt(df.SS2/N)
df.std1
df.std2

# In R the "sd()" function calculates the sample standard deviation
# Making a simple adjustment to compute population standard deviation
sd(dataset) * sqrt(N - 1) / sqrt(N)
