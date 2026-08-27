#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Triangle {
private:
  static constexpr float vertices[] = {
      // positions         // colors
      0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
      0.0f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f  // top
  };

  static constexpr unsigned int indices[] = {0, 1, 2};

  GLuint VBO, VAO, EBO;

public:
  Triangle();
  ~Triangle();

  void draw();
};
