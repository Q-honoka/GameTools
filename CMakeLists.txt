cmake_minimum_required(VERSION 3.20)

project(GameTools LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.cpp")

add_executable(
    Example_Vector2D
    "examples/Vector2D/main.cpp"
)

target_include_directories(
    Example_Vector2D
    PRIVATE
    include
)

add_executable(
    Example_TimeManager
    "examples/TimeManager/main.cpp"
    ${SOURCES}
)

target_include_directories (
    Example_TimeManager
    PRIVATE
    include
)

add_executable(
    Example_Collision2D
    "examples/Collision2D/main.cpp"
)

target_include_directories(
    Example_Collision2D
    PRIVATE
    include
)

add_executable(
    Example_InputManager
    "examples/InputManager/main.cpp"
    ${SOURCES}
)

target_include_directories (
    Example_InputManager
    PRIVATE
    include
)
