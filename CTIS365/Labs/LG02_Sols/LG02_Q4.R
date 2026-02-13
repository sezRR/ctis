data <- read.csv("./LG02_Files/temperature.csv", header = T)
data
data_list <- as.list(data)
data_list

# Q4a.
max_temps <- lapply(data_list, max)
min_temps <- lapply(data_list, min)
min_temps

cat(
  c(
    sprintf("Maximum temperature in %s is %d degree.\n", names(max_temps), unlist(max_temps)),
    sprintf("Minimum temperature in %s is %d degree.\n", names(min_temps), unlist(min_temps))
  ),
  sep = ""
)

# Q4b.

x <- c(-2, 0.3,1.4,2.4,4.5)
y <- c(-5,-0.5,8,2,11)

?plot

plot(
  c(1:7),
  data$Ankara,
  type="o",
  xlim=c(1,7),
  ylim=c(min_temps$Ankara, max_temps$Ankara),
  xlab="Days",
  ylab="Temperature",
  main="Temperature of Ankara for One Week", 
  col="blue")







