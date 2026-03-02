# Q2

data <- read.table("./LG04_Files/skatingTime.txt", header = T)

# Q2a
data.mean <- mean(data$Time)
data.median <- median(data$Time)

library(DescTools)
data.mode <- Mode(data$Time)

# Q2b
hist(data$Time)
