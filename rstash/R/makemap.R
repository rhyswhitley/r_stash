# Function to accept a flattened 3-dimensional (x, y, z) data;
# where x/y are geospatial coordinates and z is a value of some 
# kind at that coordinate. Flattend data is converted it into a 
# gridded raster map and return to user.
#
# Row length and value difference between rows are used to determine
# the geometry of the raster map. After map has been created, then 
# z-values are added to respective coordinates.
#
# Author: Rhys Whitley
# Institution: Macquarie University
# Email: rhys.whitley@mq.edu.au
# License: GPL3

make.map  <- function(xyz.data) {

    # longitude and latitude extents
    x.ext <- range(xyz.data[[1]])
    y.ext <- range(xyz.data[[2]])

    # grid resolution
    res   <- xyz.data[[1]][2] - xyz.data[[1]][1]

    # number of cells in x/y directions
    num.x <- rstash::count.cells(x.ext, res)
    num.y <- rstash::count.cells(y.ext, res)

    # create the raster grid based on the above geometry
    ras.map <- raster::raster(nrow=num.y, ncol=num.x,
               xmn=x.ext[1], xmx=x.ext[2], 
               ymn=y.ext[1], ymx=y.ext[2],
               crs="+proj=longlat +datum=WGS84")

    # retrieve the grid cell coordinates
    coord <- raster::cellFromXY(ras.map, cbind(xyz.data[[1]], xyz.data[[2]]))

    # now attach data to each coordinate
    ras.map[coord]<- xyz.data[[3]]

    # return to user
    return(ras.map)
}

