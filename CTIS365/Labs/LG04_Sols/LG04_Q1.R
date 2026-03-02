# Q1

vector <- c(26, 23, 24, 29, 31, 28, 32, 21, 32, 29, 25, 33, 27, 34)

vector.mean <- mean(vector)
vector.median <- median(vector)

library(DescTools)
vector.mode <- Mode(vector)

# instead of using DescTools package
findMode <- function(x){ 
  ta <- table(x)
  tam <- max(ta)
  if (all(ta == tam))
    mod <- NA
  else if(is.numeric(x))
    mod <- as.numeric(names(ta)[ta == tam])
  else
    mod <- names(ta)[ta == tam]
  return(mod)
}

vector.mode <- findMode(vector)
