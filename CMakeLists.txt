cmake_minimum_required(VERSION 3.16)

project(cpptest VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

file(GLOB SRC_FILES 
	${PROJECT_SOURCE_DIR}/cpp/*.cpp
)

qt_add_executable(cpptest ${SRC_FILES})

target_include_directories(cpptest PUBLIC ${CURL_INCLUDE_DIRS})
target_link_libraries(cpptest PRIVATE Qt6::Widgets ${CURL_LIBRARIES})

set_target_properties(cpptest PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

find_program(TOOL_WINDEPLOYQT NAMES windeployqt)

add_custom_command(TARGET cpptest POST_BUILD
    COMMAND ${TOOL_WINDEPLOYQT} $<TARGET_FILE:cpptest>
    COMMENT "Running windeployqt..."
)
