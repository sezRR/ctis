# Colors
# http://www.stat.columbia.edu/~tzheng/files/Rcolor.pdf
# https://www.datanovia.com/en/blog/ggplot-colors-best-tricks-you-will-love/
# http://www.sthda.com/english/wiki/ggplot2-themes-and-background-colors-the-3-elements
# https://felixfan.github.io/ggplot2-remove-grid-background-margin/
# http://www.cookbook-r.com/Graphs/Bar_and_line_graphs_(ggplot2)/  (good)


# Legend tutorial
# https://www.datanovia.com/en/blog/ggplot-legend-title-position-and-labels/

# The aim of this plot is to see the weight of an aquatic plant that is grown under different pollution
# conditions (nano-particles of Titanium are used here)

# Function to clear console
cat("\014")
# Learn R version
getRversion()
# Clearing all plots
graphics.off()
# To empty an environment
rm(list = ls())

# Including ggplot2 library and gridExtra
library(ggplot2)
library(gridExtra)


# create a dataset
Titanium = c("0", "2", "4", "6", "8", "10")
Titanium
Fresh_Wt = c(2.49, 2.43, 2.04, 2.43, 2.49, 1.75)
Fresh_Wt
Labels = c("2.49a", "2.43a", "2.04ab", "2.43a", "2.49a", "1.75b")   # a, b, and ab are the relationships due to ANOVA
data = data.frame(Titanium, Fresh_Wt, Labels)
data
# We want to define the order of plotting
data$Titanium <- factor(data$Titanium , levels = c("0", "2", "4", "6", "8", "10"))
data
str(data)

cbp1 <- c("cadetblue3", "firebrick2", "darkseagreen3", "darkgoldenrod2", "darkorange2", "orchid4")

plot1 <- ggplot(data, aes(y = Fresh_Wt, x = Titanium, fill = Titanium)) + 
  
  geom_bar(position="dodge", stat="identity", colour="black", width=.7)  +
  
  guides(fill=guide_legend(nrow = 1, byrow = TRUE)) + 
  scale_fill_manual(values = cbp1) +
  geom_text(aes(label=Labels), size = 5, fontface = "bold", vjust = -0.2) +
  ggtitle(label = "Fresh Weight", subtitle = "Plot of XXXX") +
  ylab("Weight (g)") +
  xlab("Titanium (mg/L)") +
  labs(fill = "Titanium") +
  
  theme(panel.grid.major = element_blank(), panel.grid.minor = element_blank(),
        panel.background = element_blank(), axis.line = element_line(colour = "black"),
        plot.title = element_text(size = 22, face = "bold", hjust = 0.5),
        plot.subtitle = element_text(size = 18, hjust = 0.5),
       
        legend.title = element_text(size = 18),
        legend.text = element_text(size = 16),
        legend.position = "top",
        
        axis.title.x = element_text(size = 18),
        axis.text.x = element_text(size = 16),
        
        axis.title.y = element_text(size = 18),
        axis.text.y = element_text(size = 16))

plot1
