cmake_minimum_required(VERSION 3.10)

# set the project name
project(Lab2)

find_package(OpenCV REQUIRED)


include_directories(${OpenCV_INCLUDE_DIRS})


set(sources "Source/minMaxFunction.h" "Source/minMaxFunction.cpp") 


# add the executable
add_executable(${PROJECT_NAME} Source/mainCode.cpp ${sources})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
