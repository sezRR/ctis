#get the factor
blood <- c("A","B","AB","0","A","B","AB")
blood_factor <- factor(blood)
blood_factor

#reorder level names
blood_factor2 <- factor(blood, level=c("A","B","AB","0"))
blood_factor2
#change level names
blood_factor3 <- factor(blood)
levels(blood_factor3) <- c("BT_0","BT_A","BT_AB","BT_B")
blood_factor3

#ordered factor
tshirt <- c("M", "L", "S", "S", "L", "M", "L", "M")

tshirt_factor <- factor(tshirt, ordered = TRUE,
                        levels = c("S", "M", "L"))
tshirt_factor

tshirt_factor[1] < tshirt_factor[2]





