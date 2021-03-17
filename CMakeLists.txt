cmake_minimum_required (VERSION 3.10)
project (SAPER)

set ( SOURCES main.cpp MinesweeperBoard.cpp )


add_compile_options(-Wall -Wextra -g)

add_executable(main ${SOURCES} )

set_target_properties(main PROPERTIES
CXX_STANDARD 11
CXX_EXTENSIONS OFF
)