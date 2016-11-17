#!/usr/bin/env Rscript

# load the package
library(rstash)

# load the example dataset
data(tasclim)

# create a grid characteristic matrix
# --------------------------------------------------
# add lat/lon coordinates
gchar <- tasclim$Air.Temp[,1:2]
# elevation [constant for testing]
gchar$elev <- 0
# field capacity of bucket water holding capacity [mm]
gchar$fcap <- 140
# initial soil water conditions [set -9999.0 for spinup]
gchar$swc0 <- -9999.0
# --------------------------------------------------

# run model
output <- grid.stash(tasclim$Air.Temp, tasclim$Precip, tasclim$Sun.Hrs, gchar)

# look at the annual total results
ann.total <- stack.by.out(output$annual, flag.to.na=TRUE)
pdf("~/Repositories/R_packages/r_stash/figures/tas_annual.pdf")
    plot(ann.total)
dev.off()

# look at individual monthly results for each bioclimatic mini-output (e.g. actual evaporation)
aet.12mon <- stack.by.mon(output$act.evap, flag.to.na=TRUE)
pdf("~/Repositories/R_packages/r_stash/figures/tas_aet.pdf")
    plot(aet.12mon)
dev.off()

