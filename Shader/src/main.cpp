#include "Shader.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window =
      glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Shader", NULL, NULL);

  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

  Shader shader("E:/Programming/learnopengl/Shader/src/Shader.vert",
                "E:/Programming/learnopengl/Shader/src/Shader.frag");

  float vertices[] = {
      0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, // top right
      0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom left
      -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 1.0f  // top left
  };

  unsigned int indices[] = {
      // note that we start from 0!
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  GLuint VAO;
  glGenVertexArrays(1, &VAO);

  GLuint VBO;
  glGenBuffers(1, &VBO);

  GLuint EBO;
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindVertexArray(0);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.5, 0.2, 0.5, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    shader.use();

    shader.setInt("offset", 0);
    glBindVertexArray(VAO);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}
