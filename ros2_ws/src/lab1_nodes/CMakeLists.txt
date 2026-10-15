cmake_minimum_required(VERSION 3.8)
project(lab1_nodes)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)

# Component Node

add_library(demo_component SHARED
  src/demo_component.cpp
)

ament_target_dependencies(demo_component
  rclcpp
  rclcpp_components
)

rclcpp_components_register_nodes(
  demo_component
  "lab1_nodes::DemoComponent"
)

install(
  TARGETS demo_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# Lifecycle Node

add_executable(lifecycle_demo
  src/lifecycle_demo.cpp
)

ament_target_dependencies(lifecycle_demo
  rclcpp
  rclcpp_lifecycle
)

install(
  TARGETS lifecycle_demo
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()