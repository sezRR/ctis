# Central Tendency (Mean, Median and Mode)

# Function to clear console
cat("\014")
# Learn R version
getRversion()
# Clearing all plots
graphics.off()
# To empty an environment
rm(list = ls())
# To generate same output for every run (random number related)
set.seed(1234) 

# Generating 10000 numbers (data points)
n <- 10000
# normal + exponential distribution
data <- rnorm(n, 0, 1) + rexp(n, 1/5) # tau = 5 (rate = 1/tau)
data
# Summary of an object 
summary(data)
# Structure of an object 
str(data)        # can learn the data types and the number of elements


# Box plot
boxplot(data)

# How to read a box plot
# https://towardsdatascience.com/understanding-boxplots-5e2df7bcbd51

boxplot(data,
        main = "Title goes here",
        xlab = "x label goes here",
        ylab = "y label goes here",
        col = "orange",
        border = "brown",
        horizontal = TRUE,
        notch = TRUE)         # It is used to find out how the medians of different data groups match with each other# Finding the mode via bins
h <- hist(data, breaks = 30)
h

mode.location <- h$mids[h$counts == max(h$counts)]    # x-axis value for mode
mode.location

# Same as above
# index <- which(h$counts == max(h$counts))
# mode.location <- h$mids[index]

hist(data,                        # histogram
     col = "peachpuff",           # bar fill color
     border = "black",            # bar outline color
     prob = TRUE,                 # show densities instead of frequencies
     xlim = c(-5.0,20.0),         # x-axis limits i.e., minimum and maximum values
     ylim = c(0,0.15),            # y-axis limits i.e., minimum and maximum values
     xlab = "x",                  # x-axis label
     ylab = "Probability",        # y-axis label
     main = "Central Tendency",   # title
     breaks = 30)                 # number of bins/groups

# Adding connected line segment for the density to the plot
lines(density(data),              # density plot
      lwd = 2,                    # thickness of line
      col = "chocolate3",         # line color
      lty = 2)                    # line type  (http://www.sthda.com/english/wiki/line-types-in-r-lty)


# Adding a vertical line for the mean 
abline(v = mean(data),
         col = "royalblue",
         lwd = 2,
         lty = 6)

# Adding a vertical line for the median
abline(v = median(data),
         col = "red",
         lwd = 2,
         lty = 1)

# Adding a vertical line for the mode 
abline(v = mode.location,
       col = "green",
       lwd = 2,
       lty = 3)

# Adding a horizontal line (only for demonstration purpose)
abline(h = 0.1,
       col = "cyan",
       lwd = 4,
       lty = "solid")


# Adding legends, so it will be easy to tell which line belongs to which plot 
legend(x = "topright",                                      # location of legend within plot area
       c("Density plot", "Mean", "Median", "Mode"),         # text to display
       col = c("chocolate3", "royalblue", "red", "green"),  # line colors
       lwd = c(2, 2, 2, 2),                                 # line widths
       lty = c(2, 6, 1, 3))                                 # line types

