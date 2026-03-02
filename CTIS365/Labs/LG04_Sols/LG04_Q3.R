# Q3

data <- read.table("./LG04_Files/q3data.txt")

# Q3a
data.mean <- mean(data$V1)

# Q3b

#population
definationalSS <- function(x){
  mean <-mean(x)
  return (sum((x-mean)^2))
}

#sample
computationalSS <- function(x){
  return (sum(x^2) - ((sum(x)^2)/length(x)))
}

N <- length(data$V1)# length of dataSet
N
#population
sdDefitional <- sqrt(definationalSS(data$V1)/N)
sdDefitional
#sample
sdComputational <-sqrt(computationalSS(data$V1)/(N-1))
sdComputational

data.sd <- sd(data$V1)
data.var <- var(data$V1)

# Q3c
data$V1 <- data$V1 + 2
data.new_mean <- mean(data$V1)
data.new_sd <- sd(data$V1)
data.new_var <- var(data$V1)

cat(data.new_mean, data.mean)
cat(data.new_sd, data.sd)
cat(data.new_var, data.var)
