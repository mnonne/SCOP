#version 410 core

in vec3 VertexColor;

out vec3 FragCol;

void main()
{
	FragCol = VertexColor;
}