#Method 1
#Creating a vector by getting datas from keyboard; scan()
#To stop press enter twice

a <- scan()
a

#Method 2
#Creating a Vector; c()
x <- c(1,4,6,7,3,4,14,8,9,1)
x
y <- c(1,"a",1,3.5)
y
c(x,y)
z <- c(x,y,"67",34)
z
typeof(y)

#Method 3
#creating a vector; seq() = sequence of 1:15
thirdvector <- seq(from = 1, to = 7, by=4)
thirdvector


#Method 4
v <- rep(y, times = 5)
#creating a vector; rep() replicate
v

#Conbine 2 vectors
v1 <- seq(1,7,2)
v2 <- seq(9,15,2)
v3 <- c(v1,v2)
v3
sumV3 <- sum(v3)
sumV3
v4 <- v1 * v2
v4
vector1 <- c(1,2,12,3,52,32,21,33,8,11,19)
vector1
newvector <- vector1[1:3] # first 3 variables
newvector
ind <- c(-1,-3,-8)
vector1[ind] #variables in the specified indexes

vector1[-5] #all variables except the  one in the 5th index

newvector <- vector1[-(1:3)] #all variables except the first three index
newvector
#logical variables as index

logicalIndex <- c(F,T,F,F,T) #created a logical vector.
#Even if the size does not match, 
#it will take the variables in the index which is True
vector1
vector1[logicalIndex]


#Lets find the variables that is greater than 10
indx <- vector1 > 10 #if the variable is greater than 10 the logical variable will be True otherwise False
vector1[indx] # get the variables greater than 10 by using the logical vector as index

vector1[vector1>30] #variables that is greater than the 30
countOver30 <- sum(vector1>30)
countOver30
vector1[vector1 == 12 | vector1 > 30] #variables that is greater than 30 or equal to 12

vector1[vector1 > 7 & vector1 < 12] #variables that is greater than 7 and smaller than 12

getwd()


#Reading a vector from a file
ChrVector <- scan("final.txt", character())
ChrVector
NumVector <- scan("midterm.txt", numeric())
NumVector

