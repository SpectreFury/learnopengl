add_executable(Coordinates 
  src/main.cpp
  src/glad.c 
  src/Shader.hpp
  src/Shader.cpp
  src/stb_image.h
  src/stb_image.cpp
)

target_include_directories(Coordinates PRIVATE ../Dependencies/include)
target_link_directories(Coordinates PRIVATE ../Dependencies/lib)

target_link_libraries(Coordinates glfw3 opengl32)

