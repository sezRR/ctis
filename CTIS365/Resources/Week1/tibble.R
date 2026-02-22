
#Creating a tibbble from an existing dataframe with as_tibble

library(tibble)
data()
newDataFrame <- iris
newDataFrame
newTibble <- as_tibble(newDataFrame)
newTibble
#Creating a new tibble from column vectors with tibble(): 
  
tibble(x = 1:5, y = 1, z = x ^ 2 + y)
data()#see already defined datasets