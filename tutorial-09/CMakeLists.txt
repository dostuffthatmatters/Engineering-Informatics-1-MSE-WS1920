cmake_minimum_required(VERSION 3.13)
project(tutorials C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")




add_executable(sl-list
        tutorial-09/practice_project_singly_linked_list/main.c
        tutorial-09/practice_project_singly_linked_list/list.c)

add_executable(ho-function
        tutorial-09/example_9_1_higher_order_function.c)

add_executable(sl-list-map
        tutorial-09/practice_project_singly_linked_list/main_map.c
        tutorial-09/practice_project_singly_linked_list/list.c
        tutorial-09/practice_project_singly_linked_list/list_map.c)




add_executable(sl-list-boilerplate
        tutorial-09/practice_project_singly_linked_list/main.c
        tutorial-09/practice_project_singly_linked_list/list_boilerplate.c)

add_executable(sl-list-map-boilerplate
        tutorial-09/practice_project_singly_linked_list/main_map.c
        tutorial-09/practice_project_singly_linked_list/list.c
        tutorial-09/practice_project_singly_linked_list/list_map_boilerplate.c)



