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

# Convert each vector of data into a monthly raster
make.map <- function(X,i,cres) {
    aumap       <- raster( nrow=695,ncol=822,
                   xmn=112.9,xmx=154,ymn=-43.75,ymx=-9,
                   crs="+proj=longlat +datum=WGS84" )
    coord       <- cellFromXY( aumap, cbind(X[,1],X[,2]))
    aumap[coord]<- X[,i+2]
    return( aumap )
}
# stack monthly climate data into a raster stack for plotting
stack.mon <- function( dat, cres=0.05 ) {
    s <- stack()
    for( i in 1:(ncol(dat)-2) ) {
        cat("Adding layer ",i,"\n")
        r <- make.map(dat,i,cres)
        s <- addLayer( s, r )
    }
    names(s) <- c("Jan","Feb","Mar","Apr","May","Jun",
                  "Jul","Aug","Sep","Oct","Nov","Dec")
    return(s)
}
# stack the outputs from stash into a raster stack for plotting
stack.dat <- function( dat, cres=0.05 ) {
    s <- stack()
    for( i in 1:(length(dat)-2) ) {
        r <- make.map(dat,i,cres)
        s <- addLayer( s, r )
    }
    names(s) <- c("AET","EET","PET","DET","PAR",
                  "MI","Alpha","MAT","MAP","FSUN",
                  "RO","GDD0","GDD5","GDD10","Chill")
    return(s)
}
