#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Square {
private:
  static constexpr float vertices[] = {
       0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
       0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
      -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 
      -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f 
  };

  static constexpr unsigned int indices[] = {
      0, 1, 3,
      1, 2, 3 
  };

  GLuint VBO, VAO, EBO;

public:
  Square();
  ~Square();

  void draw();
};

