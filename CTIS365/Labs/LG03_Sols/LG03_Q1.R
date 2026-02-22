getwd()

duration <- faithful
duration.min <- min(duration$eruptions)
duration.max <- max(duration$eruptions)

duration.seq <- seq(duration.min, duration.max, 0.5)
duration.cut <- cut(duration$eruptions, duration.seq)
duration.cut

duration.freq <- table(duration.cut)
duration.freq

cat("Maximum of the intervals' frequency is", max(duration.freq))
