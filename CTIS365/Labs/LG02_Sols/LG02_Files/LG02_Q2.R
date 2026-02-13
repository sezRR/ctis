data <- read.delim("mydata.txt", header = T)
data

# Find NAs
nb_of_na <- sum(is.na(data))
cat("We have", nb_of_na, "NA")

#
cleaned_data <- na.omit(data)
cleaned_data
