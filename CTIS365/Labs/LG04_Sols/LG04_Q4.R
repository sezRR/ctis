# Q4
data <- read.csv("./LG04_Files/happiness.csv", header = T)
str(data)

# Q4a
data.filtered_cities_lookup <- match(c("Ankara", "Istanbul", "Izmir"), data$City)
data.filtered_cities <- data[data.filtered_cities_lookup,]
data.filtered_cities

data.matrix <- rbind(
  Male = data.filtered_cities$Male, 
  Female = data.filtered_cities$Female)
data.matrix

?barplot
bp <- barplot(
  data.matrix, 
  names.arg = data.filtered_cities$City, 
  beside = T, 
  col = c("lightblue", "pink"),
  ylim = c(0, max(data.matrix, na.rm=TRUE) * 1.15))

text(
  x = bp,
  y = data.matrix,
  labels = data.matrix,
  pos = 3,
  cex = 0.8
)

?legend
legend("topleft", legend = rownames(data.matrix), fill = c("lightblue", "pink"), bty = "n")

# Q4b
data.male.mean <- mean(data$Male)
data.male.median <- median(data$Male)
data.male.mode <- Mode(data$Male)

data.female.mean <- mean(data$Female)
data.female.median <- median(data$Female)
data.female.mode <- Mode(data$Female)
