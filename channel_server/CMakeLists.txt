FILE(GLOB_RECURSE SRC_C src/*.c)
FILE(GLOB_RECURSE SRC_CPP src/*.cpp)
add_executable(channel_server ${SRC_C} ${SRC_CPP})
target_include_directories(channel_server PRIVATE include)
target_link_libraries(channel_server PUBLIC sqlite3)
target_link_libraries(channel_server PUBLIC core)
target_link_libraries(channel_server PUBLIC shared)
add_subdirectory(tests)