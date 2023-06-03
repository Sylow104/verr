FILE(GLOB SRC_C src/*.c)
FILE(GLOB SRC_CPP src/*.cpp)
add_library(tools ${SRC_C} ${SRC_CPP})
target_include_directories(tools PUBLIC include)