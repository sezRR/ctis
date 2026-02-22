# if statement
#create a random number to variable x and
#check if x is greater than 1 or not
x <- runif(11, min=0, max=100)
x
typeof(x)
data()
x <- 3
if(x>1){
  answer <- "Greater than 1"
  answer
}

#if -else statement
#same code,if it not greater than one
# show appropriate msg
if(x>1){
  answer <- "Greater than 1"
  answer
}else{
  answer <- "NOT Greater than 1"
  answer
}
  
#if-elseif statement
if(x>1){
  answer <- "Greater than 1"
  answer
}else if(x == 0){
  answer <- "it is 0"
  answer
}else{
  answer <- "NOT Greater than 1"
  answer
}

#ifelse statement

ifelse(x>0,"Greater than 0","Not Greater than 0")

#OR

ifelse(x>0,"Greater than 0",
       ifelse(x<0,"Not greater than 0","Equal to 0"))


#Finding a variable inside of a column or a vector
#Use match() function for it, this function will return the index of the searched variable 

#have a character vector
chrVector <- c("D","B","C","C","D","D","A","B")

#find the first index of "A" appears in the vector
match(c("A"),chrVector) # A appears in the 7th index

#find "A" and "B" in the vector
match(c("A","B"),chrVector) # A and B appear in the 7th and 2nd indexes
 

#if we have a vector like the below one and find all indexes that "A" appears:
chrVector <- c("A","B","A","C","A","D","A","B")
 
chrVector%in%"A"
 #result: TRUE FALSE  TRUE FALSE  TRUE FALSE  TRUE FALSE
 #This usage is more appropriate

 #If you are sure all the data are unique match function can be used
 