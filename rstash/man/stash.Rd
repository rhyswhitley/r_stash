    \name{grid.stash}
    \alias{gridstash}
    \alias{grid.stash}
    \docType{package}
    \title{Gridded Climate STASH}
    \description{
    Determines gridded hydrology, energy and other bioclimatic information from mean monthly temperature,
    total monthly precipitation and the fraction of monthly sunshine hours.
    }
    \usage{
    grid.stash(temp.air, precip, sun.hours, grid.chars)
    }
    \arguments{
        \item{temp.air}{Matrix or dataframe of gridded mean monthly temperature
            in degrees Celsius. For matrix and dataframe class, the first
            column is a measure of longitude, and the second is latitude. The
            proceeding 12 columns are measurements of mean temperature for each
            month of the year.}
        \item{precip}{Matrix or dataframe of gridded total monthly
            precipitation in millimeters. For matrix and dataframe class, the
            first column is a measure of longitude, and the second is latitude.
            The proceeding 12 columns are measurements of total precipitation
            for each month of the year.}
        \item{sun.hours}{Matrix or dataframe of gridded monthly fractional
            sunlight hours. For matrix and dataframe class, the first column is
            a measure of longitude, and the second is latitude. The proceeding
            12 columns are measurements of fractional sunlight hours for each
            month of the year. This can be determined from the sunshine
            function.} 
        \item{grid.chars}{Matrix or dataframe of the grid cell characteristics.
            For matrix and dataframe class, the first two columns relate to
            longitude and latitude respectively, while the third column is the
            elevation, the fourth column is the soil-water field capacity
            (bucket depth), and the fifth column is the initial soil water
            depth for the beginning of the year. If initial conditions are
            unknown, then the model can initiated to perform a spin-up of 40
            cycles to determine the steady-state water balance for the grid
            cell} 
    }
    \details{
    \tabular{ll}{
    Package: \tab rstash\cr
    Type: \tab Package\cr
    Version: \tab 2.0\cr
    Date: \tab 2014-04-28\cr
    License: \tab GPL-3\cr
    }
    The STAtic SHell (STASH) model is simple process-based model that
    determines bioclimatic controls on vegetation first published by Sykes et
    al. (1996). The STASH model uses gridded climate data in the form of
    monthly precipitation (precip), air temperature (temp.air) and the fraction
    of possible sunshine hours (sun.hours; inversely related to cloud cover) to
    determine spatial estimates of the water and energy budget, and indices on
    aridity and conditions for plant growth. The determination of these
    bioclimatic products is driven by a simple bucket model operating on a
    water supply and demand regime between the soil and atmosphere. The
    solution to this bucket model is achieved by iteration (spin-up), such that
    steady-state conditions for the water-balance, i.e. the change in soil
    water storage at the beginning and at the end of the year is equal to zero.
    The program maintains a loop to reach steady-state conditions, where the
    hydrological supply and demand functions work to alter the initial soil
    water conditions towards steady-state conditions. The program allows 40
    attempts to reach this condition, after which the grid cell is flagged and
    the last outputs are returned. Soil field capacity is therefore a major
    parameter in determining the outputs and should be selected carefully for
    the land-surface being modelled. As a point of reference though, a global
    value of 150 mm is usually used.

    The underlying code has been written in an object-oriented framework using C++
    in conjunction with the seminal Rcpp package developed by
    \href{dirk.eddelbuettel.com\code}{Dirk Eddelbuettel} and Romain Francois.

    }
    \value{
    Output is of a type list, containing 14 data frames whose first two columns
    are the latitude and longitude of the grid cell, and all following columns
    represent the monthly values of each quantity (Jan - Feb). Exception to
    this is the annual and swc.init data frames:
        \item{act.evap}{Monthly total actual evaporation (millimeters).}
        \item{equ.evap}{Monthly total equilibrium evaporation (millimeters).}
        \item{pot.evap}{Monthly total potential evaporation in (millimeters).}
        \item{del.evap}{Monthly climate water deficit, described as
            the difference between monthly total actual and potential
            evaporation (millimeters).}
        \item{photo.abs}{Monthly total absorbed
            photosynthetically active radiation (mols per meter
            squared).}
        \item{run.off}{Monthly runoff or overland flow (millimeters)}.
        \item{moist.index}{The monthly mean moisture index: the ratio
            of actual evaporation to precipitation (unitless)}.
        \item{alpha.index}{The monthly Prentice-Cramer coefficient: the ratio
            of actual to equilibrium evaporation (unitless)}.
        \item{chill.day}{Monthly total days below 0 degrees Celsius (days).}
        \item{grow.deg0}{Monthly total growing days above 0 degrees Celsius (days).}
        \item{grow.deg5}{Monthly total growing days above 5 degrees Celsius (days).}
        \item{grow.deg10}{Monthly total growing days above 10 degrees Celsius (days).}
        \item{annual}{Annual mean or total aggregations of the above quantities
            given by column.}
        \item{swc.init}{The final steady-state value of soil water content that
            can be used to run the model for a following year (millimeters).}
    }
    \author{
    Rhys Whitley, Wang Han
    Maintainer: Rhys Whitley <Rhys.Whitley@mq.edu.au>
    }
    \references{
    Davis TW, Prentice IC, Stocker BD, Whitley, RW, Wang H, Evans BJ, Gallego-Sala, AV
    Sykes MT, Cramer, W (2015) The STASH simple process-based bioclimatic model
    of radiation, evapotranspiration and plant-available moisture.

    Gallego-Sala AV, Clark JM, House JI, Orr HG, Prentice IC, Smith P, Farewell T,
    Chapman SJ (2010) Bioclimatic envelope model of climate change impacts on
    blanket peatland distribution in Great Britain. Climate Research, 45, 151-162.

    Sykes MT, Prentice IC, Cramer W (1996) A bioclimatic model for the potential 
    distributions of north European tree species under present and future climates.
    Journal of Biogeography, 23, 203-233.

    Prentice IC, Sykes MT, Cramer W (1993) A simulation model for the transient effects
    of climate change on forest landscapes. Ecological Modelling, 65, 51-70.
    }
    \keyword{bioclimate}
    \seealso{
    %%~~ Optional links to other man pages, e.g. ~~
    %%~~ \code{\link[<pkg>:<pkg>-package]{<pkg>}} ~~
    }
    \examples{
    # load the package
    library(rstash)

    # load the example dataset
    data(tasclim)

    ## [not run] -- test the inputs look right
    #rain.input <- stack.by.mon(tasclim$PPT, na.rm=T)
    #plot(rain.input)

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
    plot(ann.total)

    # look at individual monthly results for each bioclimatic mini-output (e.g. actual evaporation)
    aet.12mon <- stack.by.mon(output$act.evap, flag.to.na=TRUE)
    plot(aet.12mon)
    }

