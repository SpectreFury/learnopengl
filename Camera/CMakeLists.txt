add_executable(Camera 
  src/main.cpp
  src/glad.c 
  src/Shader.hpp
  src/Shader.cpp
  src/stb_image.h
  src/stb_image.cpp
)

target_include_directories(Camera PRIVATE ../Dependencies/include)
target_link_directories(Camera PRIVATE ../Dependencies/lib)

target_link_libraries(Camera glfw3 opengl32)

