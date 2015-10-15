# C wrapper function to determine gridded bioclimatic data
grid.stash <- function( i_temp, i_prec, i_fsun, i_char ){
    RI_temp <- as.matrix( i_temp, rownames.force=F )
    RI_prec <- as.matrix( i_prec, rownames.force=F )
    RI_fsun <- as.matrix( i_fsun, rownames.force=F )
    RI_char <- as.matrix( i_char, rownames.force=F )
    RO_evap <- .Call(   "gridStash", 
                        RI_temp, RI_prec, RI_fsun, RI_char,
                        PACKAGE = "rstash" )
    llen <- length(RO_evap)
    for( i in 1:llen ) {
        RO_evap[[i]] <- as.data.frame( RO_evap[[i]] )
    }
    names(RO_evap[[1]]) <- c("Lon","Lat",   "AET","EET","PET","DET","PAR",
                                            "MI","Alpha","MAT","MAP","FSUN",
                                            "RO","GDD0","GDD5","GDD10","Chill")
    for( i in 2:(llen-1) ) {
        names(RO_evap[[i]]) <- c("Lon","Lat",paste("m",1:12,sep=""))
    }
    return( RO_evap )
}

# C wrapper function to determine point location bioclimatic data
point.stash <- function( i_temp, i_prec, i_fsun, i_mon, i_lat, i_fcap, i_elev ) {
    Rinput  <-  as.matrix(
                    cbind( i_temp, i_prec, i_fsun, i_mon, i_lat, i_fcap, i_elev ),
                rownames.force=F )
    RO_evap <- .Call(   "pointStash",
                        Rinput[,1], Rinput[,2], Rinput[,3], Rinput[,4], Rinput[,5], Rinput[,6], Rinput[,7],
                        PACKAGE = "rstash" )
    return( RO_evap )
}


# C wrapper function to determine fractional sunshine hours for gridded data
sunshine <- function(rad) {
    if( class(rad)=="matrix" | class(rad)=="data.frame" ) {
        X <- as.matrix(rad)
        if( ncol(X)==14 ) {
            sun   <- .Call( "sunshine", X, PACKAGE = "emast" )
            out   <- rapply( sun, as.data.frame, how="list" )
            return(out)
        } else {
        message( "ERROR: The number of columns must not exceed the total months in a year + lat/lon columns" )
        return( NULL )
        }
    } else {
        message( "ERROR: Class must be of the type matrix or data.frame" )
        return( NULL )
    }
}

# function to determine fractional sunshine hours for un-gridded data
sunray <- function(swr,mon,lat) {
    mon2 <- ifelse( mon<1 | mon>12, NA, mon )
    if( !is.na(sum(mon2)) ) {
        Rinput <-   as.matrix(
                        cbind( swr, mon2, lat ),
                    rownames.force=F )
        rtop   <- .Call( "sunray", Rinput[,1], Rinput[,2], Rinput[,3], PACKAGE = "emast" )
        return(rtop)
    } else {
        message("ERROR: months must be between 1 and 12")
        return(NULL)
    }
}

# counts the number of cells in a coordinate direction
count.cells <- function(i.range, res) {
    return((abs(i.range[2]-i.range[1])+res)/res) 
}

# Convert an x-y-x dataset into a raster
make.map  <- function(X) {
    # longitude extent
    x.ext <- range(X[[1]])
    # latitude extent
    y.ext <- range(X[[2]])
    # grid resolution
    res   <- X[[1]][2] - X[[1]][1]
    # number of cells in x/y directions
    num.x <- count.cells(x.ext, res)
    num.y <- count.cells(y.ext, res)
    # create the raster grid based on the above geometry
    aumap       <- raster(nrow=num.y, ncol=num.x,
                   xmn=x.ext[1], xmx=x.ext[2], 
                   ymn=y.ext[1], ymx=y.ext[2],
                   crs="+proj=longlat +datum=WGS84" )
    # retrieve the grid cell coordinates
    coord       <- cellFromXY(aumap, cbind(X[[1]], X[[2]]))
    # now attach data to each coordinate
    aumap[coord]<- X[[3]]
    # return to user
    return(aumap)
}

# stack monthly outputs into a raster stack for plotting
stack.by.mon <- function(dat, na.rm=F) {
    # empty stack
    s <- stack()
    # loop through each column of data
    for( i in 3:length(dat) ) {
        # ignoring the lat/lon, go through each column of data
        dat.slice <- dat[, c(1:2, i)]
        # decide to remove NULL cells
        if(na.rm) {
            dat.slice[dat.slice <= -999] <- NA
        }
        # convert the slice to a raster
        r <- make.map(dat.slice)
        # add each raster to the stack
        s <- addLayer(s, r)
    }
    # attach names for each layer in the stack
    names(s) <- c("Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec")
    # return to user
    return(s)
}

# stack the annual total outputs into a raster stack for plotting
stack.by.out <- function(dat, na.rm=F) {
    s <- stack()
    # loop through each column of data
    for( i in 3:length(dat) ) {
        # ignoring the lat/lon, go through each column of data
        dat.slice <- dat[, c(1:2, i)]
        # decide to remove NULL cells
        if(na.rm) {
            dat.slice[dat.slice <= -999] <- NA
        }
        # convert the slice to a raster
        r <- make.map(dat.slice)
        # add each raster to the stack
        s <- addLayer(s, r)
    }
    names(s) <- c("AET","EET","PET","DET","PAR",
                  "MI","Alpha","MAT","MAP","FSUN",
                  "RO","GDD0","GDD5","GDD10","Chill")
    return(s)
}

