#pragma once
#include "Renderer.hpp"


Renderer::Renderer()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	//square of 4 vertices and 4 uv coordinates
	std::vector<glm::vec2> vertices{
	glm::vec2(0,0), glm::vec2(1,0), glm::vec2(1,1), glm::vec2(0,1),	glm::vec2(0,0), glm::vec2(1,0), glm::vec2(1,1), glm::vec2(0,1)
	};

	//indices, 2 triangles
	std::vector<unsigned int> indices{ 0,1,2,0,2,3 };

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) *4, &vertices.data()[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, &indices.data()[0], GL_STATIC_DRAW);

	//position  x-z, 2 floats
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, position)));
	glEnableVertexAttribArray(0);
	//uvs, 2 floats
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, texcoord)));
	glEnableVertexAttribArray(1);

	shaderProgram = glCreateProgram();
	ShaderBuilder::BuildShader("res/shaders/sprite.vert", ShaderType::VertexShader);

	ShaderBuilder::BuildShader("res/shaders/sprite.frag", ShaderType::FragmentShader);

	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);


	glGenBuffers(1, &drawCommandBuffer);

	glBindBuffer(GL_DRAW_INDIRECT_BUFFER, drawCommandBuffer);
	glBufferData(GL_DRAW_INDIRECT_BUFFER, sizeof(DrawElementsIndirectCommand) * COMMANDBUFFERCOUNT, nullptr, GL_DYNAMIC_DRAW);

};

void Renderer::Draw()
{
	glUseProgram(shaderProgram);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBindBuffer(GL_DRAW_INDIRECT_BUFFER, drawCommandBuffer);
	glMultiDrawElementsIndirect(GL_TRIANGLES, GL_UNSIGNED_INT, nullptr, drawCommandBufferCount, 0);
};