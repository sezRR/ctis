showPlot <- function(type = 1, low = 0.0, high = 0.0) {
  # type = 1 -> greater than, use high                        (right side)
  # type = 2 -> less than, use low                            (left side)
  # type = 3 -> between a range, use both low and high        (in-between)
  
  if (type == 1) {
    # Make a curve for normal distribution
    curve(dnorm(x, 0, 1), from = -5, to = 5, xlim=c(-5,5), main='Standard Normal Distribution'
          , xlab = "Z", ylab = "density", col = "red", lwd = 2) 
    x.range <- seq(high, 5.0, 0.005)
    cord.x <- c(high, x.range, 5.0)
    cord.y <- c(0, dnorm(x.range, 0 , 1), 0)
    # Add the right shaded area (check the first and last values in cord.x and cord.y, we need a closed area to create a polygon)
    polygon(cord.x, cord.y, col='gold2')
  }
  else if (type == 2) {
    # Make a curve for normal distribution
    curve(dnorm(x, 0, 1), from = -5, to = 5, xlim=c(-5,5), main='Standard Normal Distribution', 
          xlab = "Z", ylab = "density", col = "red", lwd = 2) 
    x.range <- seq(-5.0, low, 0.005)
    cord.x <- c(-5.0, x.range, low)
    cord.y <- c(0, dnorm(x.range, 0 , 1), 0)
    # Add the left shaded area (check the first and last values in cord.x and cord.y, we need a closed area to create a polygon)
    polygon(cord.x, cord.y, col='lightseagreen')
    
  }
  else {
    # high must be greater than low
    if(high > low) {
      # Make a curve for normal distribution
      curve(dnorm(x, 0, 1), from = -5, to = 5, xlim=c(-5,5), main='Standard Normal Distribution', xlab = "Z", ylab = "density", col = "red", lwd = 2) 
      x.range <- seq(low, high, 0.005)
      cord.x <- c(low, x.range, high)
      cord.y <- c(0, dnorm(x.range, 0 , 1), 0)
      # Add the in-between shaded area (check the first and list values in cord.x and cord.y, we need a closed area to create a polygon)
      polygon(cord.x, cord.y, col='darksalmon')
    }
    else {
      print("High should be greater than low")
    }
  }
}


z.scoresSimpleWay <- function(data) {
  Z <- (data-mean(data))/sd(data)
  return(Z)
}
