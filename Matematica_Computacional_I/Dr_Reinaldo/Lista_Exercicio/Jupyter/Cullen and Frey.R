library("fitdistrplus") #Package
library(rio) #Package

#Setting directory of the file
setwd("./data")

#Choosing the file 
f <- data.table::fread(file = "./out.dat")

#trace("descdist",edit=TRUE)

plotdist(f$V10, histo = TRUE, demp = TRUE) #empirical density and cumulative distribuition

descdist(f$V30, boot = 1000) #Cullen and Frey graph

#summary statistics
a <- f$V30
fw <- fitdist(a, "weibull")
fy <- fitdist(f$V30, "gamma")
fw <- fitdist(f$V30, "lnorm")
fw <- fitdist(f$V30, "beta")

summary(fy)

summary(fw)

