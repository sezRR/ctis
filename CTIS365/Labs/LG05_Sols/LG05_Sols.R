# Q1
c <- c(67,34,54,23,45,67,89,60,34,56,99,76,86,32,15)

# Q1a
?scale
c.scale <- scale(c)

# Q1b
c.iqscore <- 100 + (c.scale * 15)
c.iqscore <- as.numeric(c.iqscore)
c.iqscore

result <- data.frame(c, c.scale, c.iqscore)
colnames(result) <- c("test", "Zscores", "IQ")

# Q1c
head(result)

# Q2
countries <- read.csv("countries.csv")
head(countries)

library(dplyr)

# Q2a - Select
?select

countries_selected <- countries %>% 
  select(state, metro, region, income, unemployment, citizens, population, walk)

# Q2b - count
?count

countries_selected.count <- countries_selected %>%
  count(state, wt = population)
countries_selected.count

# Q2c - mutate, count
?mutate

countries_selected.walk <- countries_selected %>% 
  mutate(pop_walk = population * walk / 100) %>%
  count(state, wt = pop_walk, sort = T)
countries_selected.walk

# Q2d - group_by, summarise
?group_by
?summarise

countries_selected.income <- countries_selected %>%
  group_by(state) %>%
  summarise(
    maxUnemployment = max(unemployment),
    averageIncome = mean(income)
  )
countries_selected.income

# Q2e - group_by, summarise
?group_by

countries_selected.incomestate <- countries_selected %>%
  group_by(region, state) %>%
  summarise(
    avgIncome = mean(income)
  )
countries_selected.incomestate

# Q2f

countries_selected.totalpop <- countries_selected %>%
  group_by(state, metro) %>%
  summarise(total_Pop = sum(population))
countries_selected.totalpop
