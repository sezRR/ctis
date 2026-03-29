# Colors
# https://www.datanovia.com/en/blog/ggplot-colors-best-tricks-you-will-love/
# http://www.sthda.com/english/wiki/ggplot2-themes-and-background-colors-the-3-elements
# https://felixfan.github.io/ggplot2-remove-grid-background-margin/
# http://www.cookbook-r.com/Graphs/Bar_and_line_graphs_(ggplot2)/  (good)


# Legend tutorial
# https://www.datanovia.com/en/blog/ggplot-legend-title-position-and-labels/

# Lollipop chart tutorial
# https://www.r-graph-gallery.com/301-custom-lollipop-chart.html
# http://sape.inf.usi.ch/quick-reference/ggplot2/geom_segment

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
str(data)


plot1 <- ggplot(data, aes(y = Fresh_Wt, x = Titanium)) + 
  geom_segment( aes(x = Titanium, xend = Titanium, y = 0, yend = Fresh_Wt), size = 2, color="skyblue") +
 #geom_point(size = 5, color="orange", fill=alpha("orange", 0.3), alpha=0.7, shape=21, stroke=2) + 
 geom_point(size = 8, color="orange") + 
 theme(legend.title = element_text(size=18), legend.position = "top", legend.text = element_text(size = 16)) +
  #coord_flip() +
  geom_text(aes(label=Labels), size = 5, fontface = "bold", vjust = -1.0) +
  ggtitle(label = "Fresh Weight") +
  ylab("Weight (g)") +
  xlab("Titanium (mg/L)") +
  labs(fill = "Titanium") +
  theme( panel.grid.major = element_blank(),     #panel.grid.major = element_line(size = 0.5, linetype = 'solid', colour = "blue"),
        panel.grid.minor =  element_line(size = 0.5, linetype = 'dashed', colour = "grey"),
        panel.background = element_blank(), axis.line = element_line(colour = "black"),
        plot.title = element_text(size = 22, face = "bold", hjust = 0.5),
        plot.subtitle = element_text(hjust = 0.5),
        axis.title.x = element_text(size = 18),
        axis.text.x = element_text(size = 16),
        axis.title.y = element_text(size = 18),
        axis.text.y = element_text(size = 16))

plot1