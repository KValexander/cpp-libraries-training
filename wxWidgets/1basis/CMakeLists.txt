cmake_minimum_required(VERSION 3.23.0)

project(main)

set(WX_PATH "${CMAKE_SOURCE_DIR}/../wxWidgets")

set(WX_INCLUDE_DIRS "${WX_PATH}/include")

file(GLOB_RECURSE WX_LIBRARIES "${WX_PATH}/lib/gcc1120_x64_dll/*.a")
# set(WX_LIBRARIES "${WX_PATH}/lib/gcc1120_x64_dll/libwxbase31u.a;${WX_PATH}/lib/gcc1120_x64_dll/libwxbase31ud.a;")

include_directories(
	${CMAKE_SOURCE_DIR}/src
	${WX_INCLUDE_DIRS}
)

file(GLOB_RECURSE SOURCE "src/*.cpp" "src/*.hpp" "src/*.h")
add_executable(main
	${SOURCE}
)

target_link_libraries(main
	${WX_LIBRARIES}
)

add_custom_target(link_dll ALL COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/../wxWidgets/dll ${CMAKE_BINARY_DIR})
add_custom_target(link_assets ALL COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets)
