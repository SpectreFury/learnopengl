add_executable(Windows src/main.cpp src/glad.c)

target_include_directories(Windows PRIVATE ../Dependencies/include)
target_link_directories(Windows PRIVATE ../Dependencies/lib)

target_link_libraries(Windows glfw3 opengl32)

