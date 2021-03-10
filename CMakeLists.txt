cmake_minimum_required (VERSION 3.10)
project (SAPER)
set ( SOURCES main.cpp )
add_compile_options(-Wall -Wextra -g)
set_target_properties(main PROPERTIES
CXX_STANDARD 11
CXX_EXTENSIONS OFF