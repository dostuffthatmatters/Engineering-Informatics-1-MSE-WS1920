cmake_minimum_required(VERSION 3.13)
project(tutorial-repository C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")



add_executable(car_dealer_boilerplate
        tutorial-10/car_dealer_project/car_dealer_main.c
        tutorial-10/car_dealer_project/boilerplate/car_dealer_boilerplate.c)

add_executable(car_dealer_solution
        tutorial-10/car_dealer_project/car_dealer_main.c
        tutorial-10/car_dealer_project/solution/car_dealer_solution.c)

