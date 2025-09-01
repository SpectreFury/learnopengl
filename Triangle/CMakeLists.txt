add_executable(Triangle src/main.cpp src/glad.c)

target_include_directories(Triangle PRIVATE ../Dependencies/include)
target_link_directories(Triangle PRIVATE ../Dependencies/lib)

target_link_libraries(Triangle glfw3 opengl32)

