\docType{data}
\name{tasclim}
\alias{tasclim}
\title{Tasmania 1970-2000 Average Climate}
\format{A list of 5 data.frames containing monthly information on: \code{Air.Temp}, 
  \code{Precip}, \code{Sol.Rad} and \code{Sun.Hrs} for the Tasmanian land-surface.}
\usage{
tasclim
}
\description{
    A list of 5 data.frames containing information on climate over the Tasmanian land-surface
    at a spatial resolution of 0.05 degrees (5km). Monthly mean air temperature (Air.Temp) is in units of
    degrees Celsius, monthly total precipitation (Precip) is in units of millimetres, monthly total solar radiation (Sol.Rad) is
    in units of Mega-joules per meter squared, and mean monthly percentage hours of sunlight (Sun.Hrs) is
    in percentage units. In each data.frame the row represents a grid space (or location), while columns
    from 3+ onwards [3:14] represent the value of the quantity from the months of January to December. Geospatial
    coordinates of longitude and latitude are represented by the first two columns [1:2] respectively. 
}
     
\source{
    The dataset is an aggregated product determined from the ANUCLIM climate datasets created and maintained by 
    M. F. Hutchinson at the Fenner School of Environment and Society, Australian National University, 
    Canberra (\href{http://fennerschool.anu.edu.au/}{http://fennerschool.anu.edu.au/}). Any use of this
    dataset that is to be published should reference this source.
}
\keyword{datasets}
