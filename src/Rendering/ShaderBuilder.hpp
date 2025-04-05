#pragma once
#include "../../lib/glad/glad.h"
#include <vector>
#include <fstream>

enum class ShaderType
{
	VertexShader,
	FragmentShader
};

class ShaderBuilder
{
public:

	GLuint static BuildShader(char* path, ShaderType type)
	{
		GLuint shader = {};
		if (type == ShaderType::VertexShader)
		{
			shader = glCreateShader(GL_VERTEX_SHADER);
		}
		if (type == ShaderType::FragmentShader)
		{
			shader = glCreateShader(GL_FRAGMENT_SHADER);
		}

		auto shaderSourceText = LoadShader(path);
		const GLchar* shaderSource = shaderSourceText.data();

		glShaderSource(shader, 1, &shaderSource, 0);
		glCompileShader(shader);

		return shader;

	};

private:

	static std::vector<char> LoadShader(const char* path)
	{
		std::ifstream file(path);


		if (!file) {
			return std::vector<char>{0};
		}

		int fileLength = 0;
		GLchar c;
		std::vector<char> shaderContents;


		while (file.get(c))
		{
			fileLength++;
			shaderContents.push_back(c);
		}
		file.close();

		shaderContents.push_back('\0');
		return shaderContents;
	};
};