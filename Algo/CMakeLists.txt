cmake_minimum_required(VERSION 3.16.3)
project(Algo)


# Homework source directory
set(homework_dir "${CMAKE_SOURCE_DIR}/homeworks")
set(homework_sorting_dir "${CMAKE_SOURCE_DIR}/homeworks/01_sorting")



add_executable(HW_insert_sort ${homework_sorting_dir}/1_insertion_sort.cpp)
