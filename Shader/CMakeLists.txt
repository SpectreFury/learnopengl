add_executable(Shader src/main.cpp src/glad.c)

target_include_directories(Shader PRIVATE ../Dependencies/include)
target_link_directories(Shader PRIVATE ../Dependencies/lib)

target_link_libraries(Shader glfw3 opengl32)

