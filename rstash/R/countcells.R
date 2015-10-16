# Counts the number of cells in a coordinate direction, given 
# the limits (range) and step size between vector values (resolution).
#
# Author: Rhys Whitley
# Institution: Macquarie University
# Email: rhys.whitley@mq.edu.au
# License: GPL3

count.cells <- function(i.range, res) {

    # the number of totals cells in a given x/y direction
    n.cells <- (abs(i.range[2] - i.range[1]) + res)/res 

    # return to user
    return(n.cells)

}
