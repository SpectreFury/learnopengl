add_executable(Colors 
  src/main.cpp
  src/glad.c 
  src/Shader.hpp
  src/Shader.cpp
  src/Camera.hpp
  src/Camera.cpp
  src/stb_image.h
  src/stb_image.cpp
)

target_include_directories(Colors PRIVATE ../Dependencies/include)
target_link_directories(Colors PRIVATE ../Dependencies/lib)

target_link_libraries(Colors glfw3 opengl32)

