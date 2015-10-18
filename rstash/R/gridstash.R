# C wrapper function to determine gridded hydrology and bioclimatic data
#
# Author: Rhys Whitley
# Institution: Macquarie University
# Email: rhys.whitley@mq.edu.au
# License: GPL3

grid.stash <- function(temp.air, precip, sun.hours, grid.chars) {

    # inputs must conform to these data class types
    class.types <- c("matrix", "data.frame")

    # column requirement
    req.col = 14

    # month labels
    month.labels <- c("Jan", "Feb", "Mar", "Apr", "May", "Jun",
                      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec")

    total.labels <- c("act.evap", "equ.evap", "pot.evap", "del.evap",
                      "photo.abs", "moist.index", "alpha.index", "temp.air",
                      "precip", "sun.hours", "run.off", "grow.deg0", "grow.deg5",
                      "grow.deg10", "chill.day")

    # check if inputs meet class type requirements
    if(class(temp.air)%in%class.types | 
       class(precip)%in%class.types |
       class(sun.hours)%in%class.types 
       ) {

        # check if there are the correct number of columns
        if(ncol(temp.air)==req.col | 
           ncol(precip)==req.col | 
           ncol(sun.hours)==req.col
           ) {

            # convert to matrix type
            RI_temp <- as.matrix(temp.air, rownames.force=F)
            RI_prec <- as.matrix(precip, rownames.force=F)
            RI_fsun <- as.matrix(sun.hours, rownames.force=F)
            RI_char <- as.matrix(grid.chars, rownames.force=F)

            # pass SEXP datatypes as inputs to C++ shared object [gridStash] - call function
            RO_evap <- .Call(   "gridStash", 
                                RI_temp, RI_prec, RI_fsun, RI_char,
                                PACKAGE = "rstash" )

            # determine the number of outputs returned from C++ SO
            llen <- length(RO_evap)

            # loop through all outputs and convert from matrix to dataframe type
            for(i in 1:llen) {
                RO_evap[[i]] <- as.data.frame(RO_evap[[i]])
            }

            # add headers to to the annual totals dataframe
            names(RO_evap[[1]]) <- c("Lon", "Lat", total.labels)
            # add headers to to the monthly outputs dataframes
            for(i in 2:(llen-1)) {
                names(RO_evap[[i]]) <- c("Lon", "Lat", month.labels)
            }

            # return back to user
            return(RO_evap)

        } else {
            message( "ERROR: The number of columns must not exceed the total months in a year + lat/lon columns" )
            return(NULL)
        } # end column requirement check

    } else {
        message( "ERROR: Class must be of the type matrix or data.frame" )
        return(NULL)
    } # end data-type check
}
