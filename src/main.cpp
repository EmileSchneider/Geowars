#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

auto initialize(int width, int height, std::string title) -> GLFWwindow* {
  glewExperimental = true; // Needed for core profile
  if (!glfwInit()) {
    throw std::runtime_error("Failed to initialize GLFW");
  }

  glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  if (!window) {
    glfwTerminate();
    throw std::runtime_error("Failed to create the GLFW window!");
  }

  glfwMakeContextCurrent(window); // Initialize GLEW
  glewExperimental = true;        // Needed in core profile
  if (glewInit() != GLEW_OK) {
    throw std::runtime_error("Failed to initialize GLEW!");
  }

  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  return window;
}

auto main() -> int {
    try {
      GLFWwindow* window = initialize(800, 600, "Geowars");
      // main loop
      while(true);
      
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return -1;
    }

    glfwTerminate();
    return 0;
}
