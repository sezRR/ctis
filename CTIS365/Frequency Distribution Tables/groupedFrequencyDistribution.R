# Grouped Frequency Distribution Table

# Function to clear console
cat("\014")
# Learn R version
getRversion()
# Clearing all plots
graphics.off()
# To empty an environment
rm(list = ls())

# Cut gives incoherent/unclear results. We created a function called cut2 to do the same job
# Don't worry how it is created. Just use it
cut2 <- function(x, breaks) {
  labels <- paste0("[",  breaks[-length(breaks)], ",", breaks[-1L], ")")
  return(factor(labels[findInterval(x, breaks)], levels = labels))
}


# Sample takes a sample of the specified size from the elements of x using either with or without replacement
#dataset <- sample(x = 30:90, size = 80, replace = TRUE)
dataset <- c(30, 31, 32, 33, 34, 35, 36, 40, 79, 80, 81, 90)
dataset

# Manually determining the start point of the group and its width
low <- 30
width <- 5

dataset.low <- min(dataset)
print(dataset.low)
dataset.high <- max(dataset)
print(dataset.high)
dataset.length <- length(dataset)
print(dataset.length)

number.groups <- floor( (dataset.high - low)/width ) + 1    # Think of another solution!!!
print(number.groups)

group.max <- low + (width*number.groups)
print(group.max)

group.breaks <- seq(low, group.max, width)
print(group.breaks)

# For polygon plot
bin.midpoint <- seq(low + width/2, group.max - width/2, width)
print(bin.midpoint)

dataset.groups <- cut2(dataset, breaks=group.breaks)
print(dataset.groups)

freq <- table(dataset.groups)
print(freq)

class(freq)

# Converting to a dataframe
df <- data.frame(freq)
# Appending a column to the df
df$midpoint <- bin.midpoint
df

# Relative frequency proportion
n <- sum(df$Freq)
df$proportion <- df$Freq/n
print(df, digits = 3)

# Cumulative frequency
df$cf <- cumsum(df$Freq)
print(df, digits = 3)
# Cumulative frequency percentage (c%)
df$cf_percent <- df$cf /n * 100
print(df, digits = 3)

# Polygon plot
plot(df$midpoint, df$Freq, type = "b", pch = 19, col = "red", xlab = "x", ylab = "y", main = "Polygon Plot")
# Adding grid to the plot
grid(5, 5, col = "green", lwd = 2)

# Plotting Histogram
hist(dataset,
     xlab = "Data range", 
     col = "lightblue", 
     border = "black", 
     main = "Histogram", 
     xlim = c(dataset.low, group.max), 
     ylim = c(0,max(df$Freq) + 1), 
     breaks = number.groups + 1)


# Storing Histogram as an object
h <- hist(dataset, xlab = "Data range", 
     col = "lightblue", 
     border = "black", 
     main = "Histogram", 
     xlim = c(dataset.low, group.max), 
     ylim = c(0,max(df$Freq) + 1), 
     breaks = number.groups + 1)

class(h)
typeof(h)
h
sum(h$density)        # density is similar to probability. Why its sum is not 1.0????

sum( h$density * diff(h$breaks) ) 


#-------------------------------------------------------------------------------
# Another example using Normal Distribution data
#set.seed(123)
dataset1 <- rnorm(10000)
dataset1
mean(dataset1)
sd(dataset1)


# Density plot
h1 <- hist(dataset1,
          xlab = "Data range", 
          col = "lightblue", 
          border = "black", 
          main = "Histogram",
          prob = TRUE,        # show densities instead of frequencies
          #xlim = c(dataset.low, group.max), 
          ylim = c(0, 0.5), 
          breaks = 25)

lines(density(dataset1), # density plot
      lwd = 2, # thickness of line
      col = "chocolate3")


