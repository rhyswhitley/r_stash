# Accepts a monthly grid.stash output and converts it into a stacked
# raster object. Option available to set sea grid cells from -999 to NA
# for plotting or other general purposes.
#
# Author: Rhys Whitley
# Institution: Macquarie University
# Email: rhys.whitley@mq.edu.au
# License: GPL3

stack.by.mon <- function(dat, flag.to.na=FALSE) {

    # create an empty stack
    mon.stack <- raster::stack()

    # loop through each column that represents a month of the year
    for( i in 3:length(dat) ) {

        # including the lat/lon columns, take a monthly slice from the output
        dat.slice <- dat[, c(1:2, i)]

        # if option is true, set sea cell flagged rows to NA
        if(flag.to.na) {
            dat.slice[dat.slice <= -999] <- NA
        }

        # convert the slice to a raster and add each raster to the stack
        mon.stack <- raster::addLayer(mon.stack, make.map(dat.slice))
    }

    # attach month names for each layer in the stack
    names(mon.stack) <- c("Jan", "Feb", "Mar", "Apr", "May", "Jun",
                          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec")

    # return to user
    return(mon.stack)
}

