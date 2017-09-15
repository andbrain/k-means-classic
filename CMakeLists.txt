cmake_minimum_required(VERSION 3.5.0)
project(clustering)
include_directories(include)

#Set debug flag
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

#Can manually add the sources using the set command as follows:
set(SOURCES kmeans.cpp ) 
list(APPEND SOURCES cpp/par.cpp)
list(APPEND SOURCES cpp/util.cpp)
list(APPEND SOURCES cpp/kmeans_d.cpp)
list(APPEND SOURCES cpp/kmeans_s.cpp)
list(APPEND SOURCES cpp/distance_reader.cpp)

#However, the file(GLOB...) allows for wildcard additions:
#file(GLOB_RECURSE SOURCES "cpp/*.cpp")
add_executable(clustering ${SOURCES})
#Set name of executable
set_target_properties(clustering PROPERTIES OUTPUT_NAME kmeans.out PREFIX "")
target_compile_features(clustering PRIVATE cxx_range_for)