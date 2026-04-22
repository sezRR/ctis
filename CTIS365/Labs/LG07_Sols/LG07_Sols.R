# Q1

# Q1a
pnorm(1.05)
showPlot(high = 1.05)

# Q1b
pnorm(-0.4)
showPlot(high = -0.4)

# Q1c
1 - pnorm(0.4)
showPlot(type = 2, low = 0.4)

# Q1d
1 - pnorm(-1.2)
showPlot(type = 2, low = -1.2)

# Q2

# Q2a
q2a.zscore <- (55 - 40) / 9
pnorm(q2a.zscore)
showPlot(high = q2a.zscore)

# Q2b
q2b.zscore <- (35 - 40) / 9
pnorm(q2b.zscore)
showPlot(type = 2, low = q2b.zscore)

# Q2c
q3b.zscore.low <- (50 - 40) / 9
q3b.zscore.high <- (70 - 40) / 9

pnorm(q3b.zscore.high) - pnorm(q3b.zscore.low)
showPlot(type = 3, low = q3b.zscore.low, high = q3b.zscore.high)

# Q3

# Q3a
q3a.zscore <- (350 - 420) / 65
pnorm(q3a.zscore)
showPlot(type = 2, low = q3a.zscore)

# Q3b
q3b.zscore.low <- (350 - 420) / 65
q3b.zscore.high <- (500 - 420) / 65
pnorm(q3b.zscore.high) - pnorm(q3b.zscore.low)

showPlot(type = 3, low = q3b.zscore.low, high = q3b.zscore.high)

# Q4
x <- c(0, 3, 2, 5, 0)
y <- c(1, 3, 3, 2, 1)
cor(x, y, method = "spearman")

# Q5
x <- c(2, 5, 1, 3, 4)
y <- c(3, 1, 1, 2, 5)
cor(scale(x), scale(y), method = "pearson")
