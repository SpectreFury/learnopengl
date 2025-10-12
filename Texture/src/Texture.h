#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.hpp"

class Texture {
public:
  unsigned int ID;

  Texture(const char *texturePath);

  void use(Shader& shader, const char* uniform, int offset);
};
