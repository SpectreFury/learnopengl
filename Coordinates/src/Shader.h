#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class Shader {
public:
  GLuint ID;

  Shader(std::string vertexPath, std::string fragmentPath);

  void use();
};
