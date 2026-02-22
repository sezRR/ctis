#A data frame is a table or a two-dimensional array-like structure where each column can hold different types of data (numeric, character, etc.).
#Create data frame
n <- c(2, 3, 5) 
s <- c("aa", "bb", "cc") 
b <- c(TRUE, FALSE, TRUE) 
df <- data.frame(n, s, b)       # df is a data frame
#Column names match with variable names
df
nDf <- data.frame(n=8,s="dd",b=FALSE)
rbind(df,nDf)

#To change a dataframe's content that is already exist (open data editor)
fix(df)
df
#To create a dataframe from start by entering data (open data editor)
new_data_frame <- edit(data.frame())
new_data_frame

# Accessing a specific column by name
print(df$n)

#Some built-in functions

dim(df)      #number of columns and rows
nrow(df)     #number of rows
ncol(df)     #number of columns
names(df)    #name of the columns
rownames(df) #name of the rows
str(df)      #content of the data
summary(df)  #summary istatistics of all the columns


#Execute below code to generate three new vectors
Countries_2012_Dataset <- c("Aruba","Afghanistan","Angola","Albania","United Arab Emirates","Argentina","Armenia","Antigua and Barbuda","Australia","Austria")
Codes_2012_Dataset <- c("ABW","AFG","AGO","ALB","ARE","ARG","ARM","ATG","AUS","AUT")
Regions_2012_Dataset <- c("The Americas","Asia","Africa","Europe","Middle East","The Americas","Asia","The Americas","Oceania","Europe")

#Create a data frame that consists from above 3 vectors
df <- data.frame(Countries_2012_Dataset,Codes_2012_Dataset,Regions_2012_Dataset)
df
#Create a new vector 
birthRates <- c(10.244, 35.253, 45.985, 12.877, 11.044, 17.716, 13.308, 16.447, 13.2, 9.4)
df

#Adding new column to a data frame 
#using $ sign
df$birthRates <- birthRates
df
#using double brackets
df[["birthRate"]] <- birthRates
df

#using cbind()
df <- cbind(df,birthRates)
df
#rename the column
names(df)[4] <- "Birth Rates1"
names(df)[5] <- "Birth Rates2"
names(df)[6] <- "Birth Rates3"
df
names(df) <- c("Countries", "Codes", "Regions", "Birth.Rates1","Birth.Rates2","Birth.Rates3")
df

#Adding a new row 
#new row should be a dataframe to add
#new country as new row
Zimbabwe <- data.frame(Countries="Zimbabwe", Codes="ZWE", Regions="Africa", "Birth.Rates1"= 35.715,"Birth.Rates2"=10,"Birth.Rates3"=11)
#or
#Zimbabwe <- data.frame("Zimbabwe","ZWE","Africa",35.715,12.300,36.100)

#combine with the dataframe
df <- rbind(df,Zimbabwe)
df

#Indexing - run below codes look their types
df[["Countries"]]
df["Countries"]
df[[1]]
df[1]
df[,1]
df$Countries

#as an index a vector of boolean or number datas can be used
#boolean vectors
boolVector <- c(T,F,T,T,T,F,T,F,F,T)
df[boolVector,]

#number vector
numVector <- c(1:5)
df[numVector,]
df[numVector,c(1,2,3)]#columns

#sorts the data and returns
sort(df$Birth.Rates1,decreasing=T)
df2 <- df[order(df$Countries),]
df2

#sorts the data and returns the index numbers
order(df$Countries)


#import datas from a file manually
df2 <- read.csv(file.choose()) #create a promt to select a file
df2

#Setting working directory
getwd()


#It will search the file in that working directory
df3 <- read.csv("scores.csv")
head(df3,10)#shows first 6 rows in default

df4 <- read.table("final2.txt", header = FALSE)
df4


