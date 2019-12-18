make_minimum_required(VERSION 3.13)
project(tutorials C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")


add_executable(list_boilerplate
        list_main.c
        boilerplate/list_boilerplate.c)

add_executable(list_solution
        list_main.c
        solution/list_solution.c)


add_executable(map_boilerplate
        map_main.c
        boilerplate/list_boilerplate.c
        boilerplate/map_boilerplate.c)

add_executable(map_solution
        map_main.c
        solution/list_solution.c
        solution/map_solution.c)
