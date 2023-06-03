FILE(GLOB SRC_C src/*.c)
FILE(GLOB SRC_CPP src/*.cpp)
add_library(shared ${SRC_C} ${SRC_CPP})
target_include_directories(shared PUBLIC include)