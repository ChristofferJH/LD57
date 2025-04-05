#pragma once
#include <../../lib/glm/glm/glm.hpp>

const unsigned int COMMANDBUFFERCOUNT = 10;

struct Vertex
{
	glm::vec2 position;
	glm::vec2 texcoord;
};

struct DrawElementsIndirectCommand
{
    GLuint   count;
    GLuint   instanceCount;
    GLuint   firstIndex;
    GLuint   baseVertex;
    GLuint   baseInstance;
};
