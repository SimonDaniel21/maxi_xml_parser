cmake_minimum_required(VERSION 3.0)

project(maxi_xml_parser)


#sources
file(GLOB app_src src/*.cpp)

#builds
add_executable(maxi_filter ${app_src})

#includes
target_include_directories(maxi_filter
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Compiler options
add_definitions(-g)
add_definitions(-O0)
add_definitions(-Wall)
add_definitions(
    -DDEBUG
)


#librarys