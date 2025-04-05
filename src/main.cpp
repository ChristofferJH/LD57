#include "main.hpp"

//openGL error callback in debug mode
#ifndef NDEBUG
void __stdcall
MessageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
		type, severity, message);
}
#endif



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
	glEnable(GL_DEPTH_TEST);

	Renderer renderer;

	while (!glfwWindowShouldClose(window))
	{
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		const float ratio = width / (float)height;

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		renderer.Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	};




	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
