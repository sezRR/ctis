# Example contains 
# getting the file contents into a list

#reading file alternatives
d <- read.delim("mydata.txt", header=TRUE)
#d <- read.delim("mydata.txt", header=FALSE)
d

data <- read.table("myData.txt",header=TRUE,sep="\t")
data

data1 <- read.table("http://www.ctis.bilkent.edu.tr/ctis361/healthEmployee.txt",header=FALSE,sep="\t")
data1

library("openxlsx")
#to use read.xlsx function install the openxlsx packeage and import library
mydata <- read.xlsx("world_area.xlsx",1)#1 is for number of sheet
mydata


#gets the sheet2 in the excel file
mydata1 <- read.xlsx("people.xlsx",2)
mydata1

#gets the csv file content into a list
mydata2 <- read.csv("temperature.csv")
mydata2
typeof(mydata2)

#detecting missing values
y  <-  c(1,2,3,NA)
y
is.na(y)

mydata1$Age[mydata1$Age==25] <- NA  
mydata1

mydata1$Age[is.na(mydata1$Age)] <- 0   
mydata1

mydata
newData <- na.omit(mydata)
newData

mean(newData$`Area(sqm)`)
y
mean(y)
mean(y, na.rm=TRUE) 

x <- c(0:10, 50)
x
xm <- mean(x)
xm
