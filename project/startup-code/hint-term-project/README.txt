                       __________________________

                        HOW TO BUILD THE PROJECT

                              Zhitao Gong
                       __________________________





1 HOWTO
=======

  I suppose you are working on a Linux machine.  Otherwise, please
  figure out how to configure the enviroment yourself.

  Start from the project folder, build the project in console from
  scratch.

  1. Create a `build' directory.  Separate building from source code.

     ,----
     | mkdir build && cd build
     `----

  2. Build the whole project with CMake.

     ,----
     | cmake ..
     `----

  3. Go into the `tests/' directory under `build'.

     ,----
     | cd tests
     `----

  4. Run the test.

     ,----
     | ./test-bf
     `----
