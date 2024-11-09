cmake_minimum_required(VERSION 3.8)
project(rr_msgs)


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
 add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)  # Ensure this line is included here


# Generate messages and services
rosidl_generate_interfaces(${PROJECT_NAME}
 "msg/ArmJoint.msg"
 "msg/ImageMsg.msg"
 "msg/PointArray.msg"
 "msg/Position.msg"
 "msg/TargetArray.msg"
 "msg/Target.msg"
 "srv/Kinematics.srv" 
 "srv/RobotArmArray.srv" 
 DEPENDENCIES std_msgs geometry_msgs
)




# Testing (optional)
if(BUILD_TESTING)
 find_package(ament_lint_auto REQUIRED)
 set(ament_cmake_copyright_FOUND TRUE)
 set(ament_cmake_cpplint_FOUND TRUE)
 ament_lint_auto_find_test_dependencies()
endif()


# Export dependencies
ament_export_dependencies(rosidl_default_runtime)


ament_package()






# cmake_minimum_required(VERSION 3.8)
# project(rr_msgs)


# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()


# # find dependencies
# find_package(ament_cmake REQUIRED)
# find_package(rclcpp REQUIRED)
# find_package(std_msgs REQUIRED)


# if(BUILD_TESTING)
#   find_package(ament_lint_auto REQUIRED)
#   # the following line skips the linter which checks for copyrights
#   # comment the line when a copyright and license is added to all source files
#   set(ament_cmake_copyright_FOUND TRUE)
#   # the following line skips cpplint (only works in a git repo)
#   # comment the line when this package is in a git repo and when
#   # a copyright and license is added to all source files
#   set(ament_cmake_cpplint_FOUND TRUE)
#   ament_lint_auto_find_test_dependencies()
# endif()


# ament_package()






