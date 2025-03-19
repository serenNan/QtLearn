cmake_minimum_required(VERSION 3.20) # CMake install : https://cmake.org/download/
project(mainwindow LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/usr/local/Qt/Qt6.5.3/6.5.3/gcc_64") # Qt Kit Dir
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS
# aux_source_directory(./src srcs)

set(SOURCE 
    ${CMAKE_SOURCE_DIR}/src/main.cpp 
    ${CMAKE_SOURCE_DIR}/src/mainwindow.cpp 
    ${CMAKE_SOURCE_DIR}/src/widget.cpp 
    ${CMAKE_SOURCE_DIR}/src/dialog.cpp
)

set(INCLUDE 
    ${CMAKE_SOURCE_DIR}/include/dialog.h 
    ${CMAKE_SOURCE_DIR}/include/mainwindow.h 
    ${CMAKE_SOURCE_DIR}/include/widget.h
)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

set(UI_FILES
    ${CMAKE_SOURCE_DIR}/ui/dialog.ui
    ${CMAKE_SOURCE_DIR}/ui/mainwindow.ui
    ${CMAKE_SOURCE_DIR}/ui/widget.ui
)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(${PROJECT_NAME}
    WIN32 
    ${SOURCE}
    ${INCLUDE}
    ${UI_FILES}
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets) # Qt5 Shared Library
