#Project version minimum
cmake_minimum_required(VERSION 3.16.4)

#Project name
project(APN_SELECTOR VERSION 0.1.0)

add_executable(${PROJECT_NAME} 
"main.c"
"apn_manager.c"
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE 
CMAKE_CURRENT_LIST_DIR
)


target_link_libraries(${PROJECT_NAME} PRIVATE
    curl
)