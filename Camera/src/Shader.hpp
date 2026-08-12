#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
  GLuint ID;

  Shader(std::string vertexPath, std::string fragmentPath);

  void use();
  void setInt(const char* name, int value);
  void setFloat(const char* name, float value);
  void setMat4(const char* name, glm::mat4 value);
};
