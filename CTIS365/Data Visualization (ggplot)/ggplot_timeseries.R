# http://www.sthda.com/english/articles/32-r-graphics-essentials/128-plot-time-series-data-using-ggplot/

# Function to clear console
cat("\014")
# Learn R version
getRversion()
# Clearing all plots
graphics.off()
# To empty an environment
rm(list = ls())

library(ggplot2)
library(tidyr)

# dataset (also check help for "economics")
head(economics)   # using the built-in dataset "economics"
summary(economics)
str(economics)

df <-  economics %>%
  dplyr::select(date, psavert, uempmed) %>%
  # https://data.library.virginia.edu/a-tidyr-tutorial/
  tidyr::gather(key = "variable", value = "value", -date)    # all columns except date

head(df, 50)
str(df)

# Multiple line plot
plot1 <- ggplot(df, aes(x = date, y = value)) + 
  geom_line(aes(color = variable), size = 1) +
  theme(legend.title = element_text(size = 18), legend.position = "top", legend.text = element_text(size = 16)) +
  scale_color_manual(values = c("#00AFBB", "#E7B800")) +
  ggtitle(label = "Line plot for economics data") +
  ylab("Value") +
  xlab("Date") +
  theme(panel.grid.major = element_line(size = 0.5, linetype = 'dashed', colour = "grey"), 
        panel.grid.minor =  element_blank(),
        panel.background = element_blank(), axis.line = element_line(colour = "black"),
        plot.title = element_text(size = 20, face = "bold", hjust = 0.5),
        axis.title.x = element_text(size = 18),
        axis.text.x = element_text(size = 16),
        axis.title.y = element_text(size = 18),
        axis.text.y = element_text(size = 16))

plot1


# Area plot
plot2 <- ggplot(df, aes(x = date, y = value)) + 
  geom_area(aes(color = variable, fill = variable), alpha = 0.2, position = position_dodge(0.8)) +
  theme(legend.title = element_text(size=18), legend.position = "top", legend.text = element_text(size = 16)) +
  scale_color_manual(values = c("#00AFBB", "#E7B800")) +
  scale_fill_manual(values = c("#00AFBB", "#E7B800")) +
  ggtitle(label = "Area chart for economics data") +
  ylab("Value") +
  xlab("Date") +
  theme(panel.grid.major = element_line(size = 0.5, linetype = 'dashed', colour = "grey"), 
        panel.grid.minor =  element_blank(),
        panel.background = element_blank(), axis.line = element_line(colour = "black"),
        plot.title = element_text(size = 20, face = "bold", hjust = 0.5),
        axis.title.x = element_text(size = 18),
        axis.text.x = element_text(size = 16),
        axis.title.y = element_text(size = 18),
        axis.text.y = element_text(size = 16))

plot2
