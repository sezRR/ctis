myList <- list(c("Red", "Green", "Black"), matrix(c(1,3,5,7,9,11), nrow = 2), list(c("Python", "PHP", "Java")))
names(myList) <- c("Color", "Odd numbers", "Language(s)")

myList["Color"]
myList["Odd numbers"]
myList$`Language(s)`
myList[[1]]
myList[[2]][1,]
myList[[3]]
myList[[3]][[1]][[2]]
myList[[3]][[1]]
myList[[3]][[1]][[3]]
myList[3]
myList

