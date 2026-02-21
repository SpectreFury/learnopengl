add_executable(Transformation 
  src/main.cpp
  src/glad.c 
  src/Shader.hpp
  src/Shader.cpp
  src/stb_image.h
  src/stb_image.cpp
)

target_include_directories(Transformation PRIVATE ../Dependencies/include)
target_link_directories(Transformation PRIVATE ../Dependencies/lib)

target_link_libraries(Transformation glfw3 opengl32)

