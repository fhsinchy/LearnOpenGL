#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

const unsigned int SCR_HEIGHT = 600;
const unsigned int SCR_WIDTH = 800;

// callback for the glfwSetFramebufferSizeCallback()
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// process keyboard inputs from user
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main() {
	// initialize GLFW
	glfwInit();

	// set OpenGL version and profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create a new GLFW window
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// set the new window as the context
	glfwMakeContextCurrent(window);

	// load the available OpenGL functions
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// make sure that the OpenGL viewport keeps up with window resizes
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	// start rendering triangle
	
	// end rendering triangle

	// render loop
	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		// configure a color to clear the screen with
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

		// clear the screen with the previously set color
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}