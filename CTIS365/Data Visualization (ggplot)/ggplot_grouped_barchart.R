# This script shows how to use ggplot2 to create a group barchart
# Need stringi package

# Colors in R
# http://www.stat.columbia.edu/~tzheng/files/Rcolor.pdf


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

# create a dataset (Male and Female popultion in CTIS)
Year <- c(rep("2016" , 2) , rep("2017" , 2), rep("2018" , 2) )
Year
Group <- rep(c("M" , "F") , 3)
Group
Population = c(200, 100, 250, 150, 280, 180)
Population
data = data.frame(Year, Group, Population)
data
# We want Male first and then Female in the plot
data$Group <- factor(data$Group , levels = c('F', 'M'))
str(data)


colors <- c("deeppink2", "steelblue2")

plot1 <- ggplot(data, aes(fill = Group, y = Population, x = Year)) + 
  geom_bar(position="dodge", stat="identity", colour="black", width = 0.8) + 
  #theme(legend.position = "top") +
  scale_fill_manual(values = colors) + 
  geom_text(aes(label=..Group..), position = position_dodge(0.8), vjust=-0.2) +
  ggtitle(label = "CTIS Student Population Plot",
          subtitle = "Annual Student Data Based on Gender") +
  ylab("Population") +
  labs(fill = "Gender") +
  theme(panel.grid.major = element_blank(), panel.grid.minor = element_blank(),
        panel.background = element_blank(), axis.line = element_line(colour = "black"),
        plot.title = element_text(size = 20, face = "bold", hjust = 0.5),
        plot.subtitle = element_text(hjust = 0.5),
        legend.position = "top",
        axis.title.x = element_text(size = 18),
        axis.text.x = element_text(size = 16),
        axis.title.y = element_text(size = 18),
        axis.text.y = element_text(size = 16))
plot1
#ggsave("figure1.png", plot = plot1)
#dev.copy(png,'figure1.png')
#dev.off()