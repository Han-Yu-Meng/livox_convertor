cmake_minimum_required(VERSION 3.14)
project(livox_converter LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(livox_ros_driver2 REQUIRED)
find_package(livox_msg REQUIRED)

fins_add_node(${PROJECT_NAME} SHARED 
  src/nodes.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  livox_msg::livox_msg
)

fins_link_ros_dependencies(${PROJECT_NAME}
  livox_ros_driver2
)
