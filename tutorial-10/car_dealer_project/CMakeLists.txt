make_minimum_required(VERSION 3.13)
project(tutorials C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(car_dealer_boilerplate
        car_dealer_main.c
        boilerplate/car_dealer_boilerplate.c)

add_executable(car_dealer_solution
        car_dealer_main.c
        solution/car_dealer_solution.c)
