cmake_minimum_required(VERSION 3.16)

project(MapTests LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Gui)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MapTests tst_maptests.cpp ../../Map.cpp ../../Map.h)
add_test(NAME MapTests COMMAND MapTests)

target_link_libraries(MapTests
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Test
        Qt${QT_VERSION_MAJOR}::Gui
)


include(GNUInstallDirs)
install(TARGETS MapTests
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
