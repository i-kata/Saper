
cmake_minimum_required(VERSION 3.17)
project(SAPER=SFML-ULTIMATE)

set(CMAKE_CXX_STANDARD 14)

add_executable(SAPER-SFML-ULTIMATE main.cpp MinesweeperBoard.cpp MinesweeperBoard.h MSBoardTextView.cpp MSBoardTextView.h MSTextController.h MSTextController.cpp MSSFMLView.cpp MSSFMLView.h)
cmake_minimum_required(VERSION 3.1)
# Proszę zmienić wymaganą wersję CMake na niższą - w zupełności wystarczy 3.1

project(SAPER-SFML-ULTIMATE)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)

# ustawienia SFML-a dla Linuksa/MacOS i Windows - proszę zostawić obie konfiguracje,
# CMake automatycznie użyje właściwej
if (UNIX)
    # proszę nie modyfkować pierwszego wpisu, można dopisać kolejne katalogi
    # pierwszy wpis powinien poprawnie skonfigurować SFML-a dla wszystkich
    # Debianopodobnych dystrybucji
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})

    # czy ktoś używa MacOS ? Co tam trzeba wpisać ?

endif(UNIX)

if (WIN32)
    # próbujemy linkować statycznie (nie trzeba kopiować plików dll do katalogu projektu)
    set( SFML_STATIC_LIBRARIES TRUE )

    # można zmienić katalog na właściwy
    set ( SFML_DIR "C:/cpp/SFML-2.5.1/lib/cmake/SFML")
endif(WIN32)


# to polecenie się wywali, jeśli CMake nie znajdzie SFML-a w jednym ze wskazanych
# wcześniej katalogów - nie ma potrzeby robienia potem if-a dla target_link_libraries
find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(MyApp main.cpp MinesweeperBoard.cpp MinesweeperBoard.h MSBoardTextView.cpp MSBoardTextView.h MSTextController.h MSTextController.cpp MSSFMLView.cpp MSSFMLView.h)


target_link_libraries(MyApp sfml-graphics sfml-audio)

# ABSOLUTNIE I W ŻADNYM WYPADKU nie dodawać wpisu include_directories(${SFML_PATH}/include/SFML/) !!!
# po pierwsze - nie jest potrzebny, po drugie - "dzięki" takim wpisom utrudniacie mi życie
# W kodzie w dyrektywach #include należy obowiązkowo używać konwencji #include <SFML/...>

cmake_minimum_required (VERSION 3.10)
project (SAPER)

set ( SOURCES main.cpp MinesweeperBoard.cpp )


add_compile_options(-Wall -Wextra -g)

add_executable(main ${SOURCES} )

set_target_properties(main PROPERTIES
CXX_STANDARD 11
CXX_EXTENSIONS OFF
)

