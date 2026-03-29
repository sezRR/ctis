# Skewness and Kurtosis
# Good reading material on the topic of Skewness and Kurtosis
# https://www.spcforexcel.com/knowledge/basic-statistics/are-skewness-and-kurtosis-useful-statistics#kurtosis
# Kurtosis convergence reated
# https://www.geeksforgeeks.org/image-splicing-set-1-introduction/

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


# Read the wikipedia page
# https://en.wikipedia.org/wiki/Skewness
# If skewness is positive, the data are positively skewed or skewed right, meaning that 
# the right tail of the distribution is longer than the left. 
# If skewness is negative, the data are negatively skewed or skewed left, meaning that 
# the left tail is longer. If skewness = 0, the data are perfectly symmetrical.


# Custom function to compute population standard deviation
std <-  function(x) {
  output <- sd(x) * sqrt( (length(x) - 1)/length(x) )
  
}

skewness <-  function(x) {
  m3 <- mean((x-mean(x))^3)
  skew <- m3/(std(x)^3)
  skew
}

# Read the wikipedia page
# https://en.wikipedia.org/wiki/Kurtosis
kurtosis <- function(x) {  
  m4 <- mean((x-mean(x))^4) 
  kurt <- m4/(std(x)^4)  
  kurt
}

# Manually generated data
dataset <- c(19.09, 19.55, 17.89, 17.73, 25.15, 27.27, 25.24, 21.05, 21.65, 20.92, 22.61, 15.71, 22.04, 22.60, 24.25)
skewness(dataset)
kurtosis(dataset)

# For verification purpose using the moments package to compute skewness and kurtosis
library(moments)
moments::skewness(dataset)
moments::kurtosis(dataset)
detach("package:moments", unload = TRUE)


# Generating 10000 Normally distributed numbers with a mean of 10 and a std. of 2
n.sample1 <- rnorm(n = 5000, mean = 10, sd = 2)
skewness(n.sample1)                          # Normal distribution has a skewness of 0
kurtosis(n.sample1)                          # Normal distribution has a kurtosis of 3
excess.kurtosis1 <- kurtosis(n.sample1) - 3   # Normal distribution has an excess kurtosis of 0
excess.kurtosis1


# Histogram and density plot
library(ggplot2)
df1 <- data.frame(n.sample1)


# Both double and single quotes work for a string/character
ggplot(df1, aes(x = n.sample1), binwidth = 2) + 
  geom_histogram(aes(y = ..density..), fill = "red", alpha = 0.5) +
  geom_density(colour = "blue") + 
  ggtitle("Normal Distribution") +
  theme(plot.title = element_text(hjust = 0.5)) +
  xlab(expression(bold('x'))) + 
  ylab(expression(bold('Probability')))


# Generating 10000 random numbers from a Uniform Distributions
n.sample2 <- runif(10000, min=0, max=10)
skewness(n.sample2)                            # Uniform distribution has a skewness of 0
kurtosis(n.sample2)        
excess.kurtosis2 <- kurtosis(n.sample2) - 3   # Uniform distribution has an excess kurtosis of -6/5 = -1.2
excess.kurtosis2


# Histogram and density plot
df2 <- data.frame(n.sample2)
ggplot(df2, aes(x = n.sample2), binwidth = 2) + 
  geom_histogram(aes(y = ..density..), fill = 'red', alpha = 0.5) + 
  geom_density(colour = 'blue') + 
  ggtitle("Uniform Distribution") +
  theme(plot.title = element_text(hjust = 0.5)) +
  xlab(expression(bold('x'))) + 
  ylab(expression(bold('Probability')))


# Generate 10000 random numbers from a mixture of 2 Normal distributions (negatively skewed)
n1 <- 10000
w1 <-  rbinom(n1, 1, 0.5)                 # 50:50 random choice for 0 and 1
y1 <- rnorm(n1, mean = 4, sd = 3)         # Normal distribution with mean 4 and std. 3
y2 <- rnorm(n1, mean = 6, sd = 1)         # Normal distribution with mean 6 and std. 1
n.sample3 <- w1*y1 + (1-w1)*y2            # Normal mixture

# Another approach for the above mixture distribution
# https://stats.stackexchange.com/questions/70855/generating-random-variables-from-a-mixture-of-normal-distributions

skewness(n.sample3)
kurtosis(n.sample3)
excess.kurtosis3 <- kurtosis(n.sample3) - 3
excess.kurtosis3

# Histogram and density plot
df3 <- data.frame(n.sample3)
ggplot(df3, aes(x = n.sample3), binwidth = 2) + 
  geom_histogram(aes(y = ..density..), fill = 'red', alpha = 0.5) + 
  geom_density(colour = 'blue') + 
  ggtitle("Mixture Distribution (Negatively Skewed)") +
  theme(plot.title = element_text(hjust = 0.5)) +
  xlab(expression(bold('x'))) + 
  ylab(expression(bold('Probability')))

# Generate 10000 random numbers from a mixture of 2 Normal distributions (positively skewed)
n2 <- 10000
w2 <- rbinom(n2, 1, 0.5)                  # 50:50 random choice for 0 and 1
z1 <- rnorm(n2, mean = 2, sd = 2)         # Normal distribution with mean 2 and std. 2
z2 <- rnorm(n2, mean = 6, sd = 4)         # Normal distribution with mean 6 and std. 4
n.sample4 <- w2*z1 + (1-w2)*z2            # Normal mixture (This is not N(2, 2) + N(6, 4)

skewness(n.sample4)
kurtosis(n.sample4)
excess.kurtosis4 <- kurtosis(n.sample4) - 3
excess.kurtosis4

# Histogram and density plot
df4 <- data.frame(n.sample4)
ggplot(df4, aes(x = n.sample4), binwidth = 2) + 
  geom_histogram(aes(y = ..density..), fill = 'green', alpha = 0.6) + 
  geom_density(colour = 'blue') + 
  ggtitle("Mixture Distribution (Positively Skewed)") +
  theme(plot.title = element_text(hjust = 0.5, color="purple")) +
  xlab(expression(bold('x'))) + 
  ylab(expression(bold('Probability')))

