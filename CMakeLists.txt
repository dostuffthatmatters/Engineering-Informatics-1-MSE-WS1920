cmake_minimum_required(VERSION 3.13)
project(tutorial-repository C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")



add_executable(10_car_dealer_boilerplate
        tutorial-10/car_dealer_project/car_dealer_main.c
        tutorial-10/car_dealer_project/boilerplate/car_dealer_boilerplate.c)

add_executable(10_car_dealer_solution
        tutorial-10/car_dealer_project/car_dealer_main.c
        tutorial-10/car_dealer_project/solution/car_dealer_solution.c)

add_executable(11_tree_dfs_boilerplate
        tutorial-11/tree_project/dfs_main.c
        tutorial-11/tree_project/tree/tree.c
        tutorial-11/tree_project/boilerplate/dfs_boilerplate.c)

add_executable(11_tree_dfs_solution
        tutorial-11/tree_project/dfs_main.c
        tutorial-11/tree_project/tree/tree.c
        tutorial-11/tree_project/solution/dfs_solution.c)

add_executable(11_tree_bfs_boilerplate
        tutorial-11/tree_project/bfs_main.c
        tutorial-11/tree_project/tree/tree.c
        tutorial-11/tree_project/boilerplate/bfs_boilerplate.c)

add_executable(11_tree_bfs_solution
        tutorial-11/tree_project/bfs_main.c
        tutorial-11/tree_project/tree/tree.c
        tutorial-11/tree_project/solution/bfs_solution.c)


add_executable(12_bubble_sort_boilerplate
        tutorial-12/exercise_12_02_bubble_sort_boilerplate.c)

add_executable(12_bubble_sort_solution
        tutorial-12/exercise_12_02_bubble_sort_solution.c)


add_executable(12_merge_sort_boilerplate
        tutorial-12/exercise_12_04_merge_sort_boilerplate.c)

add_executable(12_merge_sort_solution
        tutorial-12/exercise_12_04_merge_sort_solution.c)


add_executable(12_binary_search_boilerplate
        tutorial-12/exercise_12_05_binary_search_boilerplate.c)

add_executable(12_binary_search_solution
        tutorial-12/exercise_12_05_binary_search_solution.c)