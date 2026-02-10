# A R script to learn how to read xls/xlsx file
# Learn how to save and restore data in R Data Format

# Useful Links
# http://www.sthda.com/english/wiki/reading-data-from-excel-files-xls-xlsx-into-r
# http://www.sthda.com/english/wiki/saving-data-into-r-data-format-rds-and-rdata

# Function to clear console
cat("\014")
# Learn R version
getRversion()
# Clearing all plots
graphics.off()
# To empty an environment
rm(list = ls())
# Prints version information about R, OS and attached packages
sessionInfo(package = NULL)

library(readxl)

# Setting the path
getwd()
setwd("D:/MyWork/MyTeaching/Fall 2022-2023/CTIS 365/RScripts")

# xlsx file
data <- read_excel("file1.xlsx")

# xls file
#data <- read_excel("file1.xls")

data
str(data)

# Converting tibble to a data frame (if required)
df <- as.data.frame(data)
str(df)

# Converting the Year column to a factor
data$Year <- as.factor(data$Year)
str(data)

# Save data object to a file
saveRDS(data, file = "mData.rds")

# Empty the environment
rm(list = ls())

# Restore the data object
data <- readRDS(file = "mData.rds")   # can use a different object name as well
str(data)
