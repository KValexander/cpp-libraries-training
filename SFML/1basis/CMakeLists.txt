cmake_minimum_required(VERSION 3.23.0)

project(main)

set(SFML_PATH "${CMAKE_SOURCE_DIR}/../SFML")

set(SFML_INCLUDE_DIRS "${SFML_PATH}/include")
set(SFML_LIBRARIES "${SFML_PATH}/lib/libsfml-graphics.a;${SFML_PATH}/lib/libsfml-main.a;${SFML_PATH}/lib/libsfml-system.a;${SFML_PATH}/lib/libsfml-window.a;${SFML_PATH}/lib/libsfml-audio.a;${SFML_PATH}/lib/libsfml-network.a;")

include_directories(
	${CMAKE_SOURCE_DIR}/src
	${SFML_INCLUDE_DIRS}
)

file(GLOB_RECURSE SOURCE "src/*.cpp" "src/*.hpp")
add_executable(main
	${SOURCE}
)

target_link_libraries(main
	${SFML_LIBRARIES}
)

add_custom_target(link_assets ALL COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets)
add_custom_target(link_bin ALL COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/../SFML/bin ${CMAKE_BINARY_DIR})