The STASH R-Package
================================

Description
=====================
Package: rstash

Type: Package

Title: STASH R-Package

Version: 2.0

Date: 2014-06-07

Author: Rhys Whitley, Wang Han

Maintainer: [Rhys Whitley](<Rhys.Whitley@mq.edu.au>)

Description: Determines bioclimatic information based on temperature, precipitation and sunshine hours.

License: GPL (>= 2)

Depends: Rcpp (>= 0.10.3), raster

LinkingTo: Rcpp


Contributors
============
Rhys Whitley, Wang Han



## How to install

This packages requires the latest version of the GCC compilers and libraries
[GCC](http://gcc.gnu.org/) and the [R](cran.r-project.org/) statistical
software package in order to work. In addition to this, you will need your
operating system's developer tools installed. You will also need to install the
[Rcpp](dirk.eddelbuettel.com/code/rcpp.html) package by Dirk Eddelbuettel, so
that R can translate the underlying C++ source code - this can be done through
R's internal package manager. Unfortunately at this stage of development the
package must be compiled through R and is not available as a binary.



### Mac OS X & Linux


You can download the latest version via two methods. Easiest way is to clone the repository to your machine

`$ git clone https://github.com/rhyswhitley/r_stash.git`

or you can download the zip file from the this website. Once you've downloaded the repository you can install the package via two methods:

#### >> Within R software
The easiest way to install the package is by using the devtools package available through CRAN. Type the following in and away you go:

`devtools::install_github("rhyswhitley/r_stash")`

If this fails, then you can try installing the package from the compressed tar.gz file, which you can download above. Using Rstudio or the base R software, click on Packages & Data > Package Installer. From the drop-down menu change CRAN (binaries) to Local Source Package. Click
through to where you've downloaded the package and select the rstash_X.tar.gz
file (the version number X is likely to change frequently at this stage of
development). The R kernel will then print compilation of the package to your screen and you will end up with  binary which will be used by R to do all the fun climate envelope calculations. If you encounter any errors, please see the troubleshooting section below.

#### >> CLI
The other option is to directly compile the source code yourself and link it
with R using the command line. To do this, open your favourite terminal emulator and move to the
repository directory.

`$ cd /wherever/you/downloaded/the/repo/to`

Then install the package using the command:

`$ R CMD INSTALL rstash_X.tar.gz`


### Windows

For Windows users, you will need to install the latest version of [CygWin](https://www.cygwin.com/), 
which will also give you the ability to install the GCC compilers - this is your easiest option. Then follow the guide above.


## Troubleshooting

Some of the errors that we have encountered installing the package (assuming we haven't stuffed up the source code) relates to the default compilers you have installed on your machine. For Linux distributions, this shouldn't be an issue at all, but for OS X there is a problem evident with the latest OS X upgrade to Mavericks, where the native compiler has changed to clang. If you are getting errors relating to incompatibility, this is likely because Rcpp has been built on another OS X compiler (likely gcc but Dirk should have updated to use clang now). However, you can get around this issue by creating a Makevars file in the ~/.R folder (you may need to create these if you already haven't) whereby you can tell R to explicitly use certain compilers when building a package from source. To do so, do the following:
```bash
mkdir ~/.R
vim ~/.R/Makevars
```
and adding the lines
```bash
FC=gfortran
# you can swap gnu variants below for clang and clang++ respectively
CC=gcc
CXX=g++
# you can also set your flags here (for example)
CFLAGS = -g -O0 -Wall
CXXFLAGS += -fopenmp -Wall
```
Now when you build your packages the above compilers will be used. This can be handy if you want to build packages using propriety compilers such as those by intel or compaq.


Have fun!


