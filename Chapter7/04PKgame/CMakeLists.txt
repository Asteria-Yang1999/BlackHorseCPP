cmake_minimum_required(VERSION 3.23)
project(04PKgame)

set(CMAKE_CXX_STANDARD 14)

add_executable(04PKgame main.cpp Weapon.h Knife.h Knife.cpp DragonSword.h DragonSword.cpp Shero.h Shero.cpp Monster.h Monster.cpp)
