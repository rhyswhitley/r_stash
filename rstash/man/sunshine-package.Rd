\name{sunshine}
\alias{sun}
\alias{sunshine}
\docType{package}
\title{
Fractional Sunshine Hours
}
\description{
This radiation function is taken from the Biome4 model developed Jed
Kaplan and Colin Prentice. The function determines the total amount of
radiation at the top of the atmosphere and the fraction of monthly sunlight
hours given a gridded data-set of incoming solar short-wave radiation.
}
\usage{
sunshine( rad )
}
\arguments{
    \item{rad}{is a matrix containing incoming solar radiation, where each row
        pertains to a grid cell and the columns are values for that grid cell
        for the 12 months of the year. The first column is a measure of
        longitude, and the second is latitude. The proceeding 12 columns
        are measurements of solar radiation for each month of the year.}
    \item{output}{Optional. What type of output should be returned. Possible values are: "raster" 
            and "dataframe". Default is raster.}
}
\details{
\tabular{ll}{
Package: \tab sunshine\cr
Type: \tab Package\cr
Version: \tab 1.0\cr
Date: \tab 2013-05-08\cr
License: \tab GPL (>= 2)\cr
}
Sunshine is a package that converts monthly measurements of direct solar radiation into
a measure of the number of fractional hours of sunlight, a required inputs used in the
clim.stash calculation routine.
}
\author{
Rhys Whitley, Wang Han, Bradley Evans
Maintainer: Rhys Whitley <Rhys.Whitley@mq.edu.au>
}
\references{
}
\keyword{ sunshine }
\seealso{
%%~~ Optional links to other man pages, e.g. ~~
%%~~ \code{\link[<pkg>:<pkg>-package]{<pkg>}} ~~
}
\examples{
}
