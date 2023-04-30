cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)

include(CTest)
enable_testing()

# add_executable(demo main.cpp Static.cpp)

set ( PRJ_SRC_LIST )
set ( PRJ_LIBRARIES )
set ( PRJ_INCLUDE_DIRS )

set ( MY_GLFW "C:/Users/jingwz/A-devs/pj-cpp/demo-cpp-01/dep" )

file ( GLOB root_header_files "${CMAKE_SOURCE_DIR}/*.h" )
file ( GLOB root_src_files "${CMAKE_SOURCE_DIR}/*.cpp" )

set ( MY_GLFW_INC "${MY_GLFW}/include" )
set ( MY_GLFW_LIB "${MY_GLFW}/lib/libglfw3.a" )

list ( APPEND PRJ_INCLUDE_DIRS . )
list ( APPEND PRJ_INCLUDE_DIRS ${MY_GLFW_INC} )

list ( APPEND PRJ_SRC_LIST ${root_src_files} )
list ( APPEND PRJ_LIBRARIES ${MY_GLFW_LIB} )

add_executable ( ${PROJECT_NAME} ${PRJ_SRC_LIST} )

target_include_directories ( ${PROJECT_NAME}
	PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries ( ${PROJECT_NAME} 
        PRIVATE 
        ${PRJ_LIBRARIES}
)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
