# Q1
data <- read.csv("sales_data.csv")

library(ggplot2)

data <- data[data$Year == 2021,]
data <- data[data$Total.Sales >= 10000,]

data$proportion <- data$Total.Sales / sum(data$Total.Sales)
data$ymax <- cumsum(data$proportion)
data$ymin <- c(0, head(data$ymax, n=-1))

ggplot(data, aes(ymax=ymax, ymin=ymin, xmax=4, xmin=3, fill = Product.Category)) +
  geom_rect() +
  labs(
    title = "Proportion of Total Sales by Cateogry", 
    subtitle = "Year: 2021",
    fill = "Category") +
  theme_void() +
  coord_polar(theta = "y") +
  xlim(c(2,4)) +
  theme(
    plot.title = element_text(hjust = 0.5, face = "bold"),
    plot.subtitle = element_text(hjust = 0.5)
  )

# Q2
library(dplyr)
mtcars$car_model = rownames(mtcars)
data <- mtcars %>% select(car_model, hp)
               
ggplot(data, aes(x = reorder(car_model, hp), y = hp, fill = hp)) +
  geom_bar(stat="identity") +
  coord_polar(theta = "x") +
  labs(
    title = "Circular Barplot of Horsepower by Car Model",
    x = "Horsepower",
    y = "Car Model"
  ) +
  theme_minimal() +
  theme(
      axis.text.x = element_text(angle = 90)
  )

  