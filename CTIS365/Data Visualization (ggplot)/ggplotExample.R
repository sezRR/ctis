# This script shows how to use ggplot2
# Need stringi package

# Function to clear console
cat("\014")
# Learn R version
getRversion()
# Clearing all plots
graphics.off()
# To empty an environment
rm(list = ls())

# Including ggplot2 library
library(ggplot2)

# Motor Trend Car Road Tests (mtcars). This data is from the 1974 Motor Trend US 
# magazine, and comprises fuel consumption and 10 aspects of automobile design 
# and performance for 32 automobiles (1973--74 models).
mtcars     # This dataframe is part of R
str(mtcars)

# 1. Data layer
# The code will not show anything
ggplot(data = mtcars)

# 2. Aesthetic layer
# The code will define the data to be used to plot a graph/chart 
# Again nothing will be plotted yet
ggplot(data = mtcars, aes(x = mpg, y = wt))   # x and y refers to data from the "data" parameter

# 3. Geometrics layer
# Now we will get a plot
ggplot(data = mtcars, aes(x = mpg, y = wt)) +
  geom_point()      # scatterplot or scatter plot


# Another plot
# Now we will get a plot
ggplot(data = mtcars, aes(x = mpg, y = wt)) + 
geom_point( aes(col = factor(cyl)) )    # using aesthetic to color the data points


# Please also check other available geom_

# 4. Facets layer
# y ~ x in R means that the left hand is the dependent variable, the right 
# hand is the independent variable
# Facets (here gears 3, 4 and 5 will be used for the grid)
ggplot(data = mtcars, aes(x = mpg, y = wt)) +
  geom_point() +
  facet_grid(gear ~ .)   # # facets equal to the levels of variable distributed vertically

# Another plot
ggplot(data=mtcars, aes(x = mpg, y = wt)) +
  geom_point() +
  facet_grid(. ~ gear)   # facets equal to the levels of variable distributed horizontally

# Another plot
ggplot(data = mtcars, aes(x = mpg, y = wt)) + 
  geom_point() + 
  facet_wrap( ~ gear, ncol = 2)  # the point plot on gears in two columns format

# Another plot
# The following outcome shows that the weight and mileage are plotted against 
# the cylinder and number of gears
ggplot(data = mtcars, aes(x = mpg, y = wt)) + 
  geom_point() + 
  facet_grid(gear ~ cyl)   # plots every combination of gear and cyl (gear y-axis and cyl on x-axis)

# 5. Statistics layer
# The below code is using stat_smooth to help the eye in seeing patterns in the 
# presence of overplotting by putting a shadow under the plot
ggplot(data = mtcars, aes(x = mpg, y = wt)) + 
  geom_point() + 
  facet_grid(gear ~ .) + 
  stat_smooth()

# 6. Coordinates layer
# It is often used to apply limit on x-axis or y-axis to play 
# with x vs y ratio and hence customize the visual as needed
ggplot(data = mtcars, aes(x = mpg, y = wt)) + 
  geom_point() + 
  facet_grid(gear ~ .) + 
  stat_smooth() + 
  coord_cartesian(xlim = c(13, 30))   # polar coordinates and spherical projection also exist

# 7. Theme layer
# Themes allows us to enrich our data presentation with appropriate use of 
# labels, positions, fonts, colors, etc.
ggplot(data = mtcars, aes(x = mpg, y = wt)) + 
  geom_point() + 
  facet_grid(gear ~ .) + 
  stat_smooth() + 
  coord_cartesian(xlim = c(13, 30)) +
  theme_linedraw()
