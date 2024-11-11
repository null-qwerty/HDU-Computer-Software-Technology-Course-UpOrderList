CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

project(myList)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -g)

include_directories(
    include
)

add_library(myList SHARED
    src/myList.cpp
)

add_library(UpOrderList SHARED
    src/UpOrderList.cpp
)

add_executable(main
    src/main.cpp
)

target_link_libraries(UpOrderList
    myList
)

target_link_libraries(main
    UpOrderList
    myList
)