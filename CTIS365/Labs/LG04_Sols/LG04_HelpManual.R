#Functions that will be used for the below questions
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

#Q1



#Q2




#Q3

#population
definationalSS <- function(x){
  mean <-mean(x)
  return (sum((x-mean)^2))
}

#sample
computationalSS <- function(x){
  return (sum(x^2) - ((sum(x)^2)/length(x)))
}

N <- length(dataSet$V1)# length of dataSet
N
#population
sdDefitional <- sqrt(definationalSS(dataSet$V1)/N)
sdDefitional
#sample
sdComputational <-sqrt(computationalSS(dataSet$V1)/(N-1))
sdComputational




#Q4


