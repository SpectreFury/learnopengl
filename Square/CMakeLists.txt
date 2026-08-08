add_executable(Square src/main.cpp src/glad.c)

target_include_directories(Square PRIVATE ../Dependencies/include)
target_link_directories(Square PRIVATE ../Dependencies/lib)

target_link_libraries(Square glfw3 opengl32)

