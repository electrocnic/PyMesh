[![CircleCI](https://circleci.com/gh/PyMesh/PyMesh/tree/master.svg?style=svg)](https://circleci.com/gh/PyMesh/PyMesh/tree/master)
[![Build Status](https://travis-ci.org/PyMesh/PyMesh.svg?branch=master)](https://travis-ci.org/PyMesh/PyMesh)
[![Documentation Status](https://readthedocs.org/projects/pymesh/badge/?version=latest)](https://pymesh.readthedocs.io/en/latest/?badge=latest)


# PyMesh CYGWIN Windows x32/x64

## Build with CYGWIN from source - Instructions !

### Prerequesites

1. Download and install Cygwin from https://cygwin.com/install.html
During the installation there are a lot of packages which are not added by default, even if you check boxes which should add all packages.
Therefore add the libraries (and their latest versions):
1.1 libtool
1.2 make
1.3 m4
1.4 gcc-core
1.5 gcc-g++
1.6 libgcc
1.7 cmake
1.8 mpfr
1.9 libmpfr-devel
1.10 libOpenCL1
1.11 libboost-devel
1.12 python3-devel

![Cygwin package installation libtool](documentation/cygwin_setup_libtool.png?raw=true)
![Cygwin package installation make](documentation/cygwin_setup_make.png?raw=true)
![Cygwin package installation m4](documentation/cygwin_setup_m4.png?raw=true)


### gmp (TODO: re-test without this step and remove eventually, it might not be needed or is not fully documented.)

https://stackoverflow.com/a/52102540/3433137

1. Download gmp from https://gmplib.org/#DOWNLOAD and unpack it to a folder of your choice `SOME/DIR/gmp-6.2.0`
2. Open Cygwin terminal
3. do this: https://stackoverflow.com/a/53217345/3433137 , then copy the built libs *.a to /usr/lib/  DONT WORRY if the complete build fails due to errors, because it is very likely that the necessary libs are built.
	/usr/lib is under your cygwin-installation directory.
4. `cd` into `SOME/DIR/gmp-6.2.0`
5. `export CYGWIN=winsymlinks:nativestrict`
6. `./configure --disable-static --enable-shared`
7. If this did not work look for the reason. A library might be missing (add it with cygwin setup) or you forgot a part of this or other things...
8. When configure worked carry on with this list. (see https://stackoverflow.com/a/52102540/3433137)
9. TODO: Better document this line. Now the final dll should be located in gmp-6.2.0/.libs/cyggmp-10.dll and this is what you need for the cgal thirdparty dependency).

(not needed eventally:
x. `export PATH="/cygdrive/c/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.12.25827/bin/Hostx64/x64:${PATH}"` (or wherever on your system `lib.exe` is located, and choose the correct bit version of the folders))

# PyMesh

1. `cd third_party`
2. `python build.py all`
3. `cd ..`
4. `mkdir build`
5. `cd build`
6. `cmake -DCMAKE_CXX_FLAGS="-fopenmp -std=gnu++0x -Wa,-mbig-obj -O3 -D_POSIX_C_SOURCE=200809L" ..`
7. `make`

`make tests` did not work for me.






### About PyMesh ###

**PyMesh** is a code base developed by Qingnan Zhou for his PhD research at New
York University.  It is a rapid prototyping platform focused on geometry
processing.  **PyMesh** is written with both C++ and Python, where
computational intensive functionalities are realized in C++, and Python is used
for creating minimalistic and easy to use interfaces.

![PyMesh][teaser]
(Model source: [Bust of Sappho](https://www.thingiverse.com/thing:14565))

### Documentation ###

[Latest documentation](http://pymesh.readthedocs.org/en/latest/)

### Quick try ###

Perhaps the easiest way of trying out PyMesh is through
[docker](https://www.docker.com/):

    docker run -it pymesh/pymesh
    Python 3.6.4 (default, Feb 17 2018, 09:32:33)
    [GCC 4.9.2] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import pymesh

For example, to run [meshstat.py](scripts/meshstat.py):

    docker run -it --rm -v `pwd`:/models pymesh/pymesh meshstat.py -x /models/model.obj

This command mounts your current working directory to the `/models` directory
in a docker container and executes the `meshstat.py` script on the mesh file
`model.obj` in the current directory.

### Download Source ###

To retrieve the code:

    git clone https://github.com/PyMesh/PyMesh.git
    cd PyMesh
    git submodule update --init

### Dependencies ###

PyMesh has the following required dependencies:

* [Python](https://www.python.org/) v2.7 and v3.x.
* [NumPy](http://www.numpy.org/) v1.8 or higher
* [SciPy](http://www.scipy.org/) v0.13 or higher
* [nose](http://nose.readthedocs.io/en/latest/) v1.3.7 or higher

The following C++ libraries are required.  They are included in
`$PYMESH_PATH/third_party` directory.

* [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page) v3.2 or higher
* [PyBind11](https://github.com/pybind/pybind11)

PyMesh also has a number of optional dependencies:

* [Carve](https://github.com/qnzhou/carve): A fast, robust constructive solid
  geometry library.
* [CGAL](https://www.cgal.org/): The Computational Geometry Algorithms Library.
* [Clipper](http://www.angusj.com/delphi/clipper.php): An open source freeware
  library for clipping and offsetting lines and polygons.
* [Cork](https://github.com/gilbo/cork): A 3D boolean/CSG library.
* [Draco](https://google.github.io/draco/): An open-source library for
  compressing and decompressing 3D geometric meshes and point clouds
* [Geogram](http://alice.loria.fr/software/geogram/doc/html/index.html): A
  programming library of geometric algorithms
* [libigl](http://igl.ethz.ch/projects/libigl/): A simple C++ geometry
  processing library.
* [MMG](https://www.mmgtools.org/): Robust, open source & multidisciplinary
  software for remeshing.
* [Qhull](http://www.qhull.org/): Engine for convex hulls, Delaunay
  triangulations, Voronoi diagrams computations.
* [Quartet](https://github.com/crawforddoran/quartet): A tetrahedral mesh
  generator that does isosurface stuffing with an acute tetrahedral tile.
* [TBB](https://www.threadingbuildingblocks.org/): Thread building blocks from
  Intel.
* [Tetgen](http://wias-berlin.de/software/tetgen/): Tetrahedral mesh generation
  engine.
* [Triangle](http://www.cs.cmu.edu/~quake/triangle.html): A two-Dimensional
  quality mesh generator and Delaunay triangulator.

All of the optional libraries are included in `$PYMESH_PATH/third_party`
directory.

### Specify Dependency Locations ###

All dependencies are included as git submodules in the `third_party` directory.
It is recommended to build these dependencies directly (see [Build](#Build) section).
However, it is possible to use an existing dependency installed on your system.
If the dependent library is not installed in standard locations
(``/usr/local/``, ``/opt/local``), one needs to set environment variables that
point to the correct directories.  PyMesh check the following environment
variables:

* Eigen: Set ``EIGEN_PATH`` to the directory containing the `eigen3` directory.
* CGAL: Set ``CGAL_PATH`` to the directory containing `UseCGAL.cmake` file.
    * Boost: Set ``BOOST_INC`` to the directory containing boost.
    * GMP: Set ``GMP_INC`` and ``GMP_LIB`` to the directories containing GMP
      header and library.
* libigl: Set ``LIBIGL_PATH`` the ``include`` directory of libigl sources.
* Cork: Set ``CORK_PATH`` to the install directory of Cork.
* Tetgen: Set ``TETGEN_PATH`` to the install directory of Tetgen.
* Triangle: Set ``TRIANGLE_PATH`` to the install directory of Triangle.
* Qhull: Set ``QHULL_PATH`` to the install directory of Qhull.
* Clipper: Set ``CLIPPER_PATH`` to the install directory of Clipper.
* Carve: Set ``CARVE_PATH`` to the install directory of Carve.
* Geogram: Set ``GEOGRAM_PATH`` to the install directory of Geogram.
* Quartet: Set ``QUARTET_PATH`` to the install directory of Quartet.
* Draco: Set ``Draco_PATH`` to the install directory of Draco.
* MMG: Set ``MMG_PATH`` to the install directory of MMG.

### Build ###

Let `$PYMESH_PATH` be the root directory of the repository.
The first step is to compile the optional third party dependencies:

    cd $PYMESH_PATH/third_party
    build.py all

Third party dependencies will be installed in
`$PYMESH_PATH/python/pymesh/third_party` directory.

Now we can build the main project.  It is recommended to build out of source:

    cd $PYMESH_PATH
    mkdir build
    cd build
    cmake ..

To build the PyMesh library:

    make
    make tests

Make sure all unit tests are passed before using the library.

### Install ###

The output of building PyMesh consists a set of C++ libraries and a python
module. Installing the C++ library is currently not available.  However,
installing the python package can be done:

    ./setup.py build # This an alternative way of calling cmake/make
    ./setup.py install

To check PyMesh is installed correctly, run the following python unit tests::

    python -c "import pymesh; pymesh.test()"

Once again, make sure all unit tests are passed, and report any unit test
failures.

### Feedback ###

Thank you for using PyMesh!  Please consider help PyMesh improve by leaving
[feedback]!

[teaser]: docs/_static/pymesh_teaser.jpg
[feedback]: https://docs.google.com/forms/d/e/1FAIpQLSc8YAzx1SL4t3qntzahYd0igPNGyIxw6N8eRs-PloYlwbPaXg/viewform?usp=pp_url
