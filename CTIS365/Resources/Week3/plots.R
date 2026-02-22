
#-------------------------ScatterPlots
#We can take only the 2 column that we are going to use
mtcars
input <- mtcars[c('wt','mpg')]
input

# Give the chart file a name.

# Plot the chart for cars with weight between 2.5 to 5 and mileage between 15 and 30.
plot(x = input$wt,y = input$mpg,
     xlab = "Weight",
     ylab = "Milage",
     xlim = c(2.5,5),
     ylim = c(15,30),		 
     main = "Weight vs Milage"
)

#---------------------------Barplot
c<-c(2, 3.5, 5, 7.9, 8.8, 12.3)

x<-sample(c, 100,replace=T)#shuffle vector
x
y<-table(x)#used to quickly create frequency tables
y

b<-barplot(table(x),ylim=c(0,22))



#---------------------------Histograms
faithful
duration <- faithful$eruptions 
duration
hist(duration)# apply the hist function

#improved
colors = c("red", "yellow", "green", "violet", "orange", 
                "blue","pink", "cyan")

hist(duration,    # apply the hist function
     probability = T, #for density plot
          col=colors,     # set the color palette 
          main="Old Faithful Eruptions", # the main title 
          xlab="Duration minutes")       # x-axis label
#
lines(density(duration),              
      lwd = 1, #line thickness              
      col = "yellow",        
      lty = 1)#type of line 

#show the x=3 on the plot
abline(h = 0.2,
       col = "green",
       lwd = 2)#line thickness

#write a text to plot
text(4,0.1,paste("x=3"))#first x, second y value
#----------------Line Graphs
x <- 1:10
y1 <- x*x
y2 <- 2*y1
x
y1
y2

plot(x,y1,type="S")
plot(x,y2,type="b",pch=3,col="red",xlab="x",ylab="y")#pch changes the point type


#--------------------------Line Graph

fall1 <- c(7,12,28,3,41)  # thousand m3

fall2 <- c(14,7,6,19,3)   # thousand m3

# Create a first line
plot(fall1,type = "o",col = "red", xlab = "Month", ylab = "Rain fall", 
     main = "Rain fall chart",ylim = c(0,45))

# Add a second line
lines(fall2, type = "b", col = "blue",pch=12,lty = 4)#pch point type, lty type of line
#Add text to the plot
text( fall1,labels=fall1,
      cex=0.65, pos=3,col="black") #cex for textsize
text( fall2,labels=fall2,
      cex=1.5, pos=2,col="red") #pos is for text position
# Add a legend to the plot
legend("topleft",legend = c("City 1","City 2"),col=c("red","blue"),lty=1:2,cex=0.9)#lty shows the figure of the each city


#--------------------------qplot
library(ggplot2)

qplot(1:10, letters[1:10],size=I(2),color=I("red"))#size make point size bigger

qplot(mpg, wt, data = mtcars)

#ggplot2 package
library(ggplot2)
trees
# geom_bar is designed to make it easy to create bar charts that show
# counts (or sums of weights)
g <- ggplot(trees,aes(x=Height,y=Volume))
g
g1 <- ggplot(trees,aes(x=Height,y=Volume))+geom_point(aes(color='red'))
g1
g2 <- ggplot(trees)+geom_point(data = trees, aes(Height, Volume), colour = 'blue', size = 3)
g2

mpg
g <- ggplot(mpg, aes(class))
g
# Number of cars in each class:
g + geom_bar(color='red')#bar color
g + geom_bar(fill='blue')#bar color
g + geom_bar(aes(fill = manufacturer))



#ggplot

tips <- head(tips)
tips
q <- ggplot(tips, aes(x=total_bill, y=tip/total_bill))
q
q + geom_point() + 
  labs(title="Tips Over Total Bill",x="Total Bill",y="Tip/Total_Bill")

q + geom_point(color='red')