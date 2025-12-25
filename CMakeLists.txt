cmake_minimum_required(VERSION 3.10)
project(GameCLI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(GameCLI
    app/main.cpp
    src/player.cpp
    src/enemy.cpp
    src/field.cpp
    src/game.cpp
)
