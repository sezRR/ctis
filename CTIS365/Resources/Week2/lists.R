#lists
list("Rsome times",193,23)
song <- list("Rsome times",193,23)
song
is.list(song)

#converting list to a vector
unlist(song)


#add name
names(song) <- c("title","duration","track")
song

song2 <- list(title="Rsome times",duration="193",track="23")
song2
is.list(song["title"])
typeof(song[["title"]])

# [  vs. [[
song[1]

song[[1]]

song[c(1, 3)]

song[[1]][[1]]

song[[c(2, 1)]]

#list in list
songs <- list(track1=song,track2=song2)
songs

# $ and extending
song$duration

friends <- c("Kurt", "Florence", "Patti", "Dave")
song$sent <- friends
song

# Create a list containing a vector, a matrix and a list.
list_data <- list(c("Jan","Feb","Mar"), matrix(c(3,9,5,1,-2,8), nrow = 2), list("green",12.3))
list_data
# Give names to the elements in the list.
names(list_data) <- c("Months", "A_Matrix", "A list")
list_data
# Access the first element of the list.
print(list_data[1])

# Access the thrid element. As it is also a list, all its elements will be printed.
print(list_data[3])

# Access the thrid element. As it is also a list,get its second element.
print(list_data[[3]][[2]])

# Access the list element using the name of the element.
print(list_data$A_Matrix)

# Add element at the end of the list
list_data[4] <- "new data"
list_data
# Add element at the end of the list in the list.
list_data[[3]][[3]] <- "New element"
list_data

# Final
print(list_data)

list1 <- list(c(1,3,6,5,4,7,96,25,14),c(2.3,6.1,8.4,9.4,1.2),c("apple","cherry","kiwi","orange"))
list1
max <- lapply(list1, max)
min <- lapply(list1,min)
max
min




