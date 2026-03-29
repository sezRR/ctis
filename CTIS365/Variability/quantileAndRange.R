# Quantile and range

# Tutorial explaining the boxplot
# https://www.kdnuggets.com/2019/11/understanding-boxplots.html

# Function to clear console
cat("\014")
# Learn R version
getRversion()
# Clearing all plots
graphics.off()
# To empty an environment
rm(list = ls())

# Defining dataset
dataset <- c(306,  152, 136, 113, 128, 72, 455, 85, 245, 227, 99, 324, 685, 220, 75, 77, 43, 211, 301, 80, 354, 1000, 1100, 1200)
#dataset <- c(2, 3, 5, 7, 11, 13, 17, 19, 23)

# Loading the installed package "plyr"
library(plyr)   # require(plyr)

# Determining the frequency by using the "count()" function of "plyr" package
df <- count(dataset)
df
# Renaming columns in he dataframe "df"
colnames(df) <- c("X","f")
df

# Cumulative frequency
df$cf <- cumsum(df$f)
df

# Cumulative frequency perecentage
df$"cf%" <- df$cf/sum(df$f)* 100
print(df, digits = 3)


# order returns a permutation which rearranges its first argument 
# into ascending or descending order
# df <- df[order(nrow(df):1), ]    #invert row order
df <- df[nrow(df):1, ]
print(df, digits = 3)



# Resetting the row numbering
rownames(df) <- NULL
print(df, digits = 3)


cat("Median")
median(dataset)     # Explain why the median is 215.5

cat("Minimum")
min(df$X)

cat("Maximum")
max(df$X)

cat("Range")
range(df$X) # min & max

print("All quartiles")
quantile(df$X)

# Any quantile value can be found by using the following syntax
quantile(df$X, 0.1)
quantile(df$X, 1/4)    # First quartile

cat("Interquartile range")
iqr <- IQR(df$X, type = 7) # interquartile range
iqr

cat("Dataset Summary")
summary(df$X) # range, quartiles and mean

cat("min, quartiles and max")
fivenum(df$X) # min, quartiles and max

cat("Decile (Quantile = 10%)")
quantile(df$X, 0.1,  type = 7) # first decile (p=0.1)

cat("Qunatile range 5% - 95%")
quantile(df$X, c(0.05,0.95), type = 7) # 90% range

# Box plot
boxplot(df$X, horizontal = T)
# boxplot(dataset, horizontal = T, notch = T)

# Important Note
# Not always same a R output but you get the rough idea how it works
min.line <- max(min(df$X), quantile(df$X, 0.25) - 1.5 * iqr)
min.line
max.line <- min(max(df$X), quantile(df$X, 0.75) + 1.5 * iqr)
max.line

# Marking the quartiles (additional)
abline(v = quantile(df$X, c(0.25, 0.5, 0.75)), col="blue")
abline(v = c(min.line, max.line), col="red")
title(main="Boxplot")

library(moments)
skewness(dataset)
kurtosis(dataset)
