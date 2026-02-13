academician_Id <- c(111, 222, 333, 444, 555, 666, 777, 888, 999, 112, 113, 114, 115,
                    116, 117, 118, 119, 120, 121, 123, 124, 125, 126)

academician_Name <- c("Rick" , "Dan" , "Michelle" ,"Aaron" , "Frank" , "Abbey" ,"Edward" , "Abel"
                      , "Reuben" , "Abelson","Abrams" , "Ace" , "Jane" , "Mary" , "James" , "Bertie" , "Rachel" ,
                      "Ross" , "Monica", "Chandler", "Phoebe", "Joseph", "Janice" )

title <- c("Dr","Asst","Dr","Prof","Dr","Prof","Prof","Asst","Dr","Inst","Asst",
           "Inst","Dr","Asst","Asst","Asst","Dr","Dr","Prof","Inst","Inst","Dr","Prof")

academician_Salary <- c(6230.3 , 5150.2 , 6110.0 , 7290.0 , 8430.0 , 8500.0 , 9540.0 ,4145.0 ,7410.0 , 6000.0
                        , 4510.0 , 6200.0 , 7500.0 , 4600.0 ,4621.0 ,5400.0 , 7410.0 ,8560.0 , 9740.0, 6870.0 , 5740.0 , 6410.0 ,8245.0)

academician_languageExamScore <- c( 65, 84, 86, 95, 91 , 40 ,35 , 85 , 38, 59 , 81 ,68 , 87, 84, 53
                                    ,94 , 85, 88, 79, 86, 53 , 45, 89)

# Calculate new salaries
salaries <- academician_languageExamScore > 85
new_salaries <- academician_Salary
new_salaries[salaries] <- academician_Salary[salaries] * (1 + 2.5/100)
new_salaries[salaries] 

# Create df
academician_df <- data.frame(
  academician_Id,
  academician_Name,
  title,
  academician_Salary,
  academician_languageExamScore,
  new_salaries
)

academician_df

# Rename columns
names(academician_df) <- c("Academician Id", "Academician Name", "Title", "Academician Salary", "Language Exam Point", "New Salary")
academician_df

# Convert title to factor
is.factor(names(academician_df))
title_factor <- academician_df$Title
title_factor

# Compare means
mean_old_salary <- mean(academician_df$`Academician Salary`)
mean_new_salary <- mean(academician_df$`New Salary`)

# # change
academician_df$`New Salary` > academician_df$`Academician Salary`
nb_of_change <- sum(academician_df$`New Salary` > academician_df$`Academician Salary`)
nb_of_change

# find max salary change
salary_diff <- academician_df$`New Salary` - academician_df$`Academician Salary`
salary_diff_max <- max(salary_diff)
salary_diff_max_idx <- which(salary_diff == salary_diff_max)
salary_diff_max_idx

max_academician <- academician_df[salary_diff_max,]
cat("The highest raise was made to", max_academician$`Academician Name`, "as", salary_diff_max, "$")
