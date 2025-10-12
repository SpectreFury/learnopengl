add_executable(Texture 
  src/main.cpp
  src/glad.c 
  src/Shader.hpp
  src/Shader.cpp
  src/stb_image.h
  src/stb_image.cpp
)

target_include_directories(Texture PRIVATE ../Dependencies/include)
target_link_directories(Texture PRIVATE ../Dependencies/lib)

target_link_libraries(Texture glfw3 opengl32)

