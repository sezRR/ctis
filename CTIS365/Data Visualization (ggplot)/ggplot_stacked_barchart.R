# This script shows how to use ggplot2 to create stacked barchart and percent stacked barchart

# Colors in R
# http://www.stat.columbia.edu/~tzheng/files/Rcolor.pdf

# Barcharts in R
# https://r-graphics.org/chapter-bar-graph

# dplyr tutorial
# http://rpubs.com/coleeagland/dplyrtutorialforjohnandjenn


# Function to clear console
cat("\014")
# Learn R version
getRversion()
# Clearing all plots
graphics.off()
# To empty an environment
rm(list = ls())

# Including ggplot2 library
library(ggplot2)


Year <- c(rep(c("2006-07", "2007-08", "2008-09", "2009-10"), each = 4))
Category <- c(rep(c("A", "B", "C", "D"), times = 4))
Frequency <- c(168, 259, 226, 340, 216, 431, 319, 368, 423, 645, 234, 685, 166, 467, 274, 251)

data <- data.frame(Year, Category, Frequency)
data$Year <- factor(data$Year , levels = c("2006-07", "2007-08", "2008-09", "2009-10"))
data

colors <- c("slateblue2", "palevioletred1", "springgreen3", "yellow3")

plot1 <- ggplot(data, aes(x = Year, y = Frequency,  fill = Category)) + 
  geom_bar(stat="identity", colour="black", width = 0.8) + 
  theme(legend.title = element_text(size=18), legend.position = "top", legend.text = element_text(size = 16)) +
  scale_fill_manual(values = colors) + 
  geom_text(aes(label=Frequency), stat="identity", size = 5, hjust = 0.5, position = position_stack(vjust = 0.5)) +
  ggtitle(label = "Stacked Bar Chart",
          subtitle = "Year vs Frequency") +
  ylab("Frequency") +
  labs(fill = "Category") +
  theme(panel.grid.major = element_blank(), panel.grid.minor = element_blank(),
        panel.background = element_blank(), axis.line = element_line(colour = "black"),
        plot.title = element_text(size = 20, face = "bold", hjust = 0.5),
        plot.subtitle = element_text(hjust = 0.5),
        axis.title.x = element_text(size = 18),
        axis.text.x = element_text(size = 16),
        axis.title.y = element_text(size = 18),
        axis.text.y = element_text(size = 16))
plot1


###################################################################################################
# Percent stacked barchart (We will compute the percentages using dplyr package)
###################################################################################################
library(dplyr)


# The group_by() function tells dplyr that future operations should operate on the data frame as though it
# were split up into groups, on the Year column. The mutate() function tells it to calculate a new column, 
# dividing each row's Frequency value by the sum of the Frequency column within each group.


df <- data %>%
  dplyr::group_by(Year) %>%
  dplyr::mutate(Percent_frequecy = round( Frequency/sum(Frequency) * 100 , digits = 1))
df

plot2 <- ggplot(df, aes(x = Year, y = Percent_frequecy, fill = Category)) +
  geom_bar(stat="identity", colour="black", width = 0.8) + 
  #theme(legend.title = element_text(size=18), legend.position = "top", legend.text = element_text(size = 16)) +
  scale_fill_manual(values = colors) + 
  geom_text(aes(label = paste0(Percent_frequecy, "%", sep = "")), size = 5, hjust = 0.5, position = position_stack(vjust = 0.5)) +
  ggtitle(label = "Percent Stacked Bar Chart",
          subtitle = "Year vs Percentage") +
  ylab("Percentage") +
  labs(fill = "Category") +
  theme(panel.grid.major = element_blank(), panel.grid.minor = element_blank(),
        panel.background = element_blank(), axis.line = element_line(colour = "black"),
        
        plot.title = element_text(size = 20, face = "bold", hjust = 0.5),
        plot.subtitle = element_text(size = 16, hjust = 0.5),
        
        legend.title = element_text(size=18),
        legend.text = element_text(size = 16),
        legend.position = "top", 
        
        axis.title.x = element_text(size = 18),
        axis.text.x = element_text(angle = 90, hjust = 1, size = 16),
        
        axis.title.y = element_text(size = 18),
        axis.text.y = element_text(size = 16))

plot2


x <- 1:10
library(moments)
skewness(x)
round(kurtosis(x), digits = 2)


