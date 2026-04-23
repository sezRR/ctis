# Q1
x <- c(8, 3, 6, 3, 9, 5, 7)
y <- c(4, 2, 5, 2, 8, 6, 7)
cor(x, y, method = "spearman")

# Q2
x <- c(12, 7, 15, 10, 9, 14, 6)
y <- c(18, 11, 20, 13, 12, 19, 8)
cor(x, y, method = "pearson")

# Q3
df <- data.frame(c(5, 1, 4, 7, 6, 4, 3, 2), c(10, 4, 5, 11, 15, 6, 5, 0))
colnames(df) <- c("x", "y")

df$`x-mx` <- df$x - mean(df$x)
df$`y-my` <- df$y - mean(df$y)
df$`(x-mx)^2` <- df$`x-mx` ^ 2
df$`(y-my)^2` <- df$`y-my` ^ 2
df$`(x-mx)(y-my)` <- df$`x-mx` * df$`y-my`

df$`ssx` <- sum(df$`(x-mx)^2`)
df$`ssy` <- sum(df$`(y-my)^2`)
df$`sp` <- sum(df$`(x-mx)(y-my)`)

head(df)
