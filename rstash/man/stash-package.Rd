    \name{grid.stash}
    \alias{gridstash}
    \alias{grid.stash}
    \docType{package}
    \title{Gridded Climate STASH}
    \description{
    Determines gridded bioclimatic information from mean monthly temperature,
    total monthly precipitation and the fraction of monthly sunshine hours.
    }
    \usage{
    grid.stash( i_temp, i_prec, i_srad, i_char )
    }
    \arguments{
        \item{i_temp}{A raster,matrix or dataframe of gridded mean monthly temperature in degrees Celsius. For matrix and dataframe class, the first
            column is a measure of longitude, and the second is latitude. The
            proceeding 12 columns are measurements of mean temperature for each
            month of the year.}
        \item{i_prec}{A raster,matrix or dataframe of gridded total monthly precipitation in millimeters. For matrix and dataframe class, the first
            column is a measure of longitude, and the second is latitude. The
            proceeding 12 columns are measurements of total precipitation for each
            month of the year.}
        \item{i_srad}{A raster,matrix or dataframe of gridded monthly fractional sunlight hours. For matrix and dataframe class, the first
            column is a measure of longitude, and the second is latitude. The
            proceeding 12 columns are measurements of fractional sunlight hours for
            each month of the year. This can be determined from the sunshine
            function.} 
        \item{i_char}{A raster, matrix or dataframe of the grid cell characteristics. For matrix and dataframe class, the first two
            columns relate to longitude and latitude respectively, while the third
            column is the elevation, the fourth column is the soil-water field capacity (bucket depth), and the fourth column is the initial
            soil water depth for the beginning of the year (set to -9999.0 for spinup).} 

    Note : i_temp, i_prec and i_srad have to be of same class (either raster or matrix/dataframe). i_char doesn't have to be of same class as them.
    
    }
    \details{
    \tabular{ll}{
    Package: \tab rstash\cr
    Type: \tab Package\cr
    Version: \tab 2.0\cr
    Date: \tab 2014-04-28\cr
    License: \tab GPL (>= 2)\cr
    }
    Gridded Climate Stash is an adaptation of the process-based PeatStash model published by
    Gallego-Sala et al. (2010); an evolution itself on the original Stash model
    developed by Sykes et al. (1996). The purpose of ClimStash is to calculate
    bioclimatic information from gridded spatial maps of long-term monthly
    precipitation (PPT), temperature (MAT) and the fraction of possible sunshine
    hours (fSun; inversely related to cloud cover). This version of the Stash model
    goes a step further by including elevation in determining gridded bioclimatic
    products. Outputs from the program include spatial maps of actual, equilibrium
    and potential evapotranspiration (AET, EET and PET respectively) moisture index
    (EET/PPT), the Prentice Cramer coefficient or alpha (AET/EET), growing degrees
    days for reference temperatures at 0, 5 and 10 degrees Celsius (GDD0, GDD5 and
    GDD10 respectively) and the fraction of absorbed radiation used in plant
    production (fAPAR).

    Determination of bioclimatic products is related to a supply and demand regime
    between the soil and atmosphere, whereby the water-balance of a site (or grid)
    must remain in a steady-state paradigm, i.e. the change in soil water storage
    at the beginning and at the end of the year is equal to zero. The program
    maintains a loop to reach steady-state conditions, where the hydrological
    supply and demand functions work to alter the initial soil water conditions
    towards steady-state conditions. The program allows 40 attempts to reach this
    condition, after which the grid cell is flagged and the last outputs are
    returned. Soil field capacity is therefore a major parameter in determining the
    product outcomes and should be selected carefully for the land-surface being
    modelled. As a point of reference though, a global value of 150 mm is usually
    used.

    The underlying code has been written in an object-oriented framework using C++
    in conjunction with the seminal Rcpp package developed by
    \href{dirk.eddelbuettel.com\code}{Dirk Eddelbuettel} and Romain Francois. The
    development of this package is part of a major work belonging to the ecosystem
    Modelling And Scaling infrasTructure (e-MAST) as part of the Terrestrial
    Ecosystem Research Network. All who wish to help develop this package are
    welcome to do so and may contact the package maintainer for access to the git
    repository.
    }
    \author{
    Rhys Whitley, Wang Han
    Maintainer: Rhys Whitley <Rhys.Whitley@mq.edu.au>
    }
    \references{
    Gallego-Sala AV, Clark JM, House JI, Orr HG, Prentice IC, Smith P, Farewell T,
    Chapman SJ (2010) Bioclimatic envelope model of climate change impacts on
    blanket peatland distribution in Great Britain. Climate Research, 45, 151-162.

    Sykes MT, Prentice IC, Cramer W (1996) A bioclimatic model for the potential 
    distributions of north European tree species under present and future climates.
    Journal of Biogeography, 23, 203-233.

    Prentice IC, Sykes MT, Cramer W (1993) A simulation model for the transient effects
    of climate change on forest landscapes. Ecological Modelling, 65, 51-70.
    }
    \keyword{ bioclimate }
    \seealso{
    %%~~ Optional links to other man pages, e.g. ~~
    %%~~ \code{\link[<pkg>:<pkg>-package]{<pkg>}} ~~
    }
    \examples{
    library(emast)

    # wave function to synthesise an arbitrary time-series for each of the variables
    wave <- function(x,a=1e3,b=2e2,k=0.53,p=1.5) a+b*sin(x*k+p)
    mons <- 1:12

    # modified by unit values for specific climate inputs
    # mean monthly temperature
    t_tair  <- wave(mons, a=20, b=30, k=0.52)
    # total monthly precipitation
    t_ppt   <- wave(mons, k=0.50, p=4.75)
    # mean monthly sunshine hours
    t_sun   <- wave(mons, k=0.54)/1.5e3

    # geo-coord is 140 deg E x -30 deg N
    cells   <- 1e3
    latlon  <- t( array( c(140,-30), c(2,cells) ) )
    # elevation 10 m above sea-level and field capacity 150 mm
    g_char  <- cbind( latlon, t( array( c(10,150), c(2,cells) ) ) )
    # create a matrix that repeats the wave functions foe each cell
    g_tair  <- cbind( latlon, t(array( rep(t_tair,cells), c(12,cells) ) ) )
    g_ppt   <- cbind( latlon, t(array( rep(t_ppt,cells) , c(12,cells) ) ) )
    g_sun   <- cbind( latlon, t(array( rep(t_sun,cells) , c(12,cells) ) ) )

    # do calc and time it
    tim <- system.time( bio_out <- grid.stash( g_tair, g_ppt, g_sun, g_char ) ); tim
    }

