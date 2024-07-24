#include <glad/glad.h> // Include GLAD for OpenGL function loading
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <GLFW/glfw3.h>
#include <iostream>   // Include for std::cerr and std::endl

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

GLuint pbo, texture;
int imageWidth, imageHeight, imageChannels;

// Function to load image using stb_image
unsigned char* loadImage(const char* filename) {
  return stbi_load(filename, &imageWidth, &imageHeight, &imageChannels, 0);
}

// Error handling function
static void error_callback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}

void init() {
  // Initialize GLFW
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    exit(1);
  }
  glfwSetErrorCallback(error_callback);

  // Create a GLFW window
  GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "PBO Example", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(1);
  }
  glfwMakeContextCurrent(window);

  // Load OpenGL functions using GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    exit(1);
  }

  // Create PBO
  glGenBuffers(1, &pbo);
  // ... rest of the init function
}

void draw(GLFWwindow* window) { // Pass 'window' as argument
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // Simple quad rendering (modify for your specific rendering needs)
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f, -1.0f);
  // ... rest of the quad rendering
  glEnd();

  glfwSwapBuffers(window);
  glfwPollEvents();
}

int main() {
  init();
  GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "PBO Example", NULL, NULL); // Create window in main

  while (!glfwWindowShouldClose(window)) {
    draw(window); // Pass 'window' to draw function
  }

  glfwTerminate();
  return 0;
}
