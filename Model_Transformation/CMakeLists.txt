add_executable(Model_Transformation 
  src/main.cpp
  src/glad.c 
  src/Shader.hpp
  src/Shader.cpp
  src/Triangle.hpp
  src/Triangle.cpp
  src/Math.h
  src/Math.cpp

)

target_include_directories(Model_Transformation PRIVATE ../Dependencies/include)
target_link_directories(Model_Transformation PRIVATE ../Dependencies/lib)

target_link_libraries(Model_Transformation glfw3 opengl32)

