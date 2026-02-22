#seq(from,to,by) default

a <- seq(5,20)
a
typeof(a)

#seq(from,to,length.out)  //desired length of the sequence
a <- seq(5,20,length.out = 40)#size
a

#seq(from,to,along.with)  //take the length from the length of this argument.
x <- c("a","b","c")
x
a <- seq(5,20,along.with = x)
a

#rep(variable,times)
b <- rep(5,times = 10)
b

#rep(vector,each)
rep(4:8,each=2)


#check the type
is.numeric(a)
is.character(b)

typeof(x)

n <- 4
sqrt(n)

greeting1 <- "Hello"
greeting2 <- "World"

greetings <- paste(greeting1,greeting2)
greetings

cat(greeting1,greeting2)

n
typeof(n)
n <- as.character(n)
n
typeof(n)

a
#mean
aMEAN <- mean(a)
aMEAN


x <- 2.5
y <- 5
z<-x*y
z
typeof(x)
typeof(y)
typeof(z)

x <- T
x
x <- 7

if(x > y)
  print("X is greater") else
  print("Y is greater")
