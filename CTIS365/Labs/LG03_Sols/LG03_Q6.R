getwd()

mtcars
mpg <- mtcars$mpg
wt <- mtcars$wt
length(mpg)
length(wt)

?plot
plot(
  wt, 
  mpg,
  ylab = "Miles Per Gallon",
  xlab = "Car Weight",
  main = "Scatterplot Example",
  pch = 1)
