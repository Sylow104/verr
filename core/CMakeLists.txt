FILE(GLOB_RECURSE SRC_C src/*.c)
FILE(GLOB_RECURSE SRC_CPP src/*.cpp)
add_library(core ${SRC_C} ${SRC_CPP})
target_include_directories(core PUBLIC include)