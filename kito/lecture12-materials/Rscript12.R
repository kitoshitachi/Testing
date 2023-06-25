# p44
cm1 = read.csv( file.choose() )

# p45
cm1

# p46
hist(cm1$LOC)

plot(density(cm1$LOC))

# p48
hist(cm1$LOC[cm1$LOC < 200])

# p50
plot(density(cm1$LOC))

plot(density(log(cm1$LOC)))

# p52
mean(cm1$LOC)
median(cm1$LOC)

mean(cm1$CC)
median(cm1$CC)

# p53
cm1$LOC[cm1$BUG==1]

# p54
mean(cm1$LOC[cm1$BUG==1])
median(cm1$LOC[cm1$BUG==1])

mean(cm1$LOC[cm1$BUG==0])
median(cm1$LOC[cm1$BUG==0])
