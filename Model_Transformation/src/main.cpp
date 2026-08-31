#include "Shader.hpp"
#include "Triangle.hpp"
#include "Square.hpp"
#include "Math.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window =
      glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Triangle", NULL, NULL);
  if (!window) {
    std::cout << "Error creating GLFW window" << std::endl;
    glfwTerminate();
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // Shader

  Shader shaderProgram("E:/Programming/learnopengl/Model_Transformation/src/Shader.vert",
                    "E:/Programming/learnopengl/Model_Transformation/src/Shader.frag");

  // Triangle triangle;
  Square square;


  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    processInput(window);

    shaderProgram.use();

    mat4 model = create_identity();

    // vec3 translation = {0.5f, 0.0f, 0.0f};
    // vec3 scale = {0.5f, 0.5f, 0.5f};

    // model = create_translation_matrix(model, translation);
    // model = create_scale_matrix(model, scale);
    model = create_z_rotation_matrix(model, 10 * glfwGetTime());

    shaderProgram.setMat4("model", model);

    // triangle.draw();
    square.draw();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}
