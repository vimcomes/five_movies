cmake_minimum_required(VERSION 3.23)
project(five_movies)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)

add_executable(five_movies main.cpp)
target_link_libraries(five_movies PRIVATE nlohmann_json::nlohmann_json)
