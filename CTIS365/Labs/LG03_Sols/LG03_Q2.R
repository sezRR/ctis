getwd()

data <- read.delim("citiesTemperature.txt", header = T, sep = " ")
str(data)

### With Using Grouped Frequency Distribution Table
data.temper.max <- max(data$temperature)
data.temper.min <- min(data$temperature)
temper_range <- ceiling(data.temper.max - data.temper.min + 1)

w <- 2
# temper_range / 2
# temper_range / 5
# temper_range / 10
# temper_range / 20

data.intervals <- seq(36, data.temper.max, w)
data.cut <- cut(data$temperature, data.intervals)
data.cut

# Grouped Frequency Table
data.freq <- table(data.cut)
data.freq

# Cumulative Frequency
data.cumfreq <- cumsum(data.freq)
data.cumfreq

# n: Total number of elements
n <- sum(data.freq)

# Proportion
data.proportion <- data.freq / n
data.proportion

# Proportion Percentage
data.proportion_percentage <- data.proportion * 100
data.proportion_percentage

# Cumulative Proportion
data.cum_proportion <- data.cumfreq / n
data.cum_proportion

# Cumulative Proportion Percentage
data.cum_proportion_percentage <- data.cum_proportion * 100
data.cum_proportion_percentage

?cbind
data.table <- cbind(data.freq, data.cumfreq, data.proportion, data.proportion_percentage, data.cum_proportion, data.cum_proportion_percentage)
data.table

### With Using Frequency Distribution Table
data.freq <- count(data$temperature)
data.freq

# Cumulative Frequency
data.cum_freq <- cumsum(data.freq$freq)

# n: Total number of elements
n <- sum(data.freq$freq)
n

# Proportion
data.prop <- data.freq$freq / n
data.prop

# Proportion Percentage
data.prop_perc <- data.prop * 100
data.prop_perc

# Cumulative Proportion
data.cum_prop <- data.cum_freq / n
data.cum_prop

# Cumulative Proportion Percentage
data.cum_prop_perc <- data.cum_prop * 100
data.cum_prop_perc

?cbind
data.table <- cbind(data.freq, data.cum_freq, data.prop, data.prop_perc, data.cum_prop, data.cum_prop_perc)
data.table

colnames(data.table) <- c("Temperature", "Frequency", "Cumulative Frequency", "Proportion", "Proportion Percentage", "Cumulative Proportion", "Cumulative Proportion Percentage")
data.table
