getwd()

data <- read.delim("citiesTemperature.txt", header = T, sep = " ")
str(data)

data.freq <- count(data$temperature)
data.freq$cum_freq <- cumsum(data.freq$freq)
data.freq

find_percentile <- function(data, element) {
  # n: Total number of elements
  n <- sum(data.freq$freq)
  
  100 * data.freq[data.freq$x == element, "cum_freq"] / n
}

find_percentile(data, 39.4)
find_percentile(data, 40.6)

