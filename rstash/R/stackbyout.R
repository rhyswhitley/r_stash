# Accepts the total annual grid.stash output and converts it into a stacked
# raster object. Option available to set sea grid cells from -999 to NA
# for plotting or other general purposes.
#
# Author: Rhys Whitley
# Institution: Macquarie University
# Email: rhys.whitley@mq.edu.au
# License: GPL3

stack.by.out <- function(dat, flag.to.na=FALSE) {

    # create an empty stack
    out.stack <- raster::stack()
    
    # labels for output
    total.labels <- c("act.evap", "equ.evap", "pot.evap", "del.evap",
                      "photo.abs", "moist.index", "alpha.index", "temp.air",
                      "precip", "sun.hours", "run.off", "grow.deg0", "grow.deg5",
                      "grow.deg10", "chill.day")

    # loop through each column of data that represent the annual total/mean 
    # of some quantity
    for( i in 3:length(dat) ) {

        # including the lat/lon columns, take a slice of information from the output
        dat.slice <- dat[, c(1:2, i)]

        # if option is true, set sea cell flagged rows to NA
        if(flag.to.na) {
            dat.slice[dat.slice <= -999] <- NA
        }

        # convert the slice to a raster and add each raster to the stack
        out.stack <- raster::addLayer(out.stack, make.map(dat.slice))
    }

    # add header information to each layer in the stack
    names(out.stack) <- total.labels

    # return to user
    return(out.stack)
}

