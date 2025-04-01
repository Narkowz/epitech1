cmake_minimum_required(VERSION 3.27)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp src/*.hpp)
add_executable(MyGKrellm ${sources})
target_compile_features(MyGKrellm PRIVATE cxx_std_17)
target_link_libraries(MyGKrellm PRIVATE sfml-graphics)
find_package(Curses REQUIRED)
target_link_libraries(MyGKrellm PRIVATE ${CURSES_LIBRARIES})
target_include_directories(MyGKrellm PRIVATE ${CURSES_INCLUDE_DIR})
