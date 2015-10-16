# C wrapper function to determine fractional sunshine hours determined from
# incident solar radiation from the atmosphere
#
# Author: Rhys Whitley
# Institution: Macquarie University
# Email: rhys.whitley@mq.edu.au
# License: GPL3

sunshine <- function(solar.rad) {

    # inputs must conform to these data class types
    class.types <- c("matrix", "data.frame")

    # column requirement
    req.col = 14

    # month labels
    month.labels <- c("Jan", "Feb", "Mar", "Apr", "May", "Jun",
                      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec")

    # check if inputs meet class type requirements
    if(class(solar.rad)%in%class.types) {

        # check if there are the correct number of columns
        if(ncol(solar.rad)==req.col) {

            # convert to matrix type
            RI.Rad <- as.matrix(solar.rad)

            # pass SEXP datatypes as inputs to C++ shared object [sunshine] - call function
            RO.sun.mat   <- .Call("sunshine", RI.Rad, PACKAGE="rstash")

            # convert from matrix type to dataframe type
            RO.sun.df <- rapply(RO.sun.mat, as.data.frame, how="list")

            # add headers to to the monthly outputs dataframes
            for(i in 1:length(RO.sun.df)) {
                names(RO.sun.df[[i]]) <- c("Lon", "Lat", month.labels)
            }

            # return to user
            return(RO.sun.df)

        } else {
            # echo error to user
            message( "ERROR: The number of columns must not exceed the total months in a year + lat/lon columns" )
            return(NULL)
        } # end column requirement check

    } else {
        # echo error to user
        message( "ERROR: Class must be of the type matrix or data.frame" )
        return(NULL)
    } # end data-type check
}


