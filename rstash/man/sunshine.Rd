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
sunshine(solar.rad)
}
\arguments{
    \item{solar.rad}{is a matrix containing values of total monthly incoming solar
        radiation in units of Mega-joules per meter squared. Each row
        pertains spatial point (or grid cell) and the columns are values for that grid cell
        for the 12 months of the year (January to December). The first two columns denote
        longitude and latitude respectively. }
}
\value{
    \item{Sun.Hrs}{A data.frame of then monthly mean percentage (as a fraction) of hours of sunlight the land-surface
    receives. Units are in percentage values.}
    \item{Rad.Top}{A data.frame of the total radiation present at the top of the atmosphere, determined
    on the orbital geometry of the earth, geographical location and the time-of-year. Units are in
    Mega-joules per meter squared.}

}
\details{
\tabular{ll}{
Package: \tab sunshine\cr
Type: \tab Package\cr
Version: \tab 1.0\cr
Date: \tab 2013-05-08\cr
License: \tab CC0\cr
}
Sunshine is a function that converts monthly measurements of total
solar radiation into a measure of mean monthly fractional hours of sunlight 
incident on the land-surface.
}
\author{
Rhys Whitley, Wang Han
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
load(tasclim)

sun.list <- sunshine(tasclim$Sol.Rad)

}
