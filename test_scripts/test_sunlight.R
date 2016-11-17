#!/usr/bin/env Rscript

# load package
library(rstash)

# load example dataset
data(tasclim)

# run sunshine routine
out.list <- sunshine(tasclim$Sol.Rad)

# test sunlight hours output
pdf("~/Repositories/r_stash/figures/tas_sunlight.pdf")
    plot(stack.by.mon(out.list$Sun.Hrs, flag.to.na=TRUE))
dev.off()

# test sunlight hours output
pdf("~/Repositories/r_stash/figures/tas_radtop.pdf")
    plot(stack.by.mon(out.list$Rad.Top, flag.to.na=TRUE))
dev.off()
