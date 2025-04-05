#pragma once
#include <glad/glad.h>
#include "RenderingData.hpp"
#include <vector>
#include "ShaderBuilder.hpp"

class Renderer
{
public:
	Renderer();
	
	void Draw();

private:

	GLuint vao;
	GLuint vbo;
	GLuint ebo;
	GLuint shaderProgram;
	GLuint drawCommandBuffer;

	unsigned int drawCommandBufferCount = 0;
};