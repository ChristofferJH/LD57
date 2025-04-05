#include "main.hpp"

int main(int argc, char* args[])
{

	glfwInit();
	GLFWwindow* window;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	window = glfwCreateWindow(640, 480, "test", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		std::cout<<"failed creating window"<<std::endl;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glfwSwapInterval(1);


	while (!glfwWindowShouldClose(window))
	{
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		const float ratio = width / (float)height;

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	};




	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
