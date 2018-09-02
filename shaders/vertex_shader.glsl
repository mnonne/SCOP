#version 410 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 color;

out vec3 VertexColor;

uniform mat4 ProjectionMatrix;

uniform mat4 ModelMatrix;

uniform mat4 ViewMatrix;

uniform mat4 MVPMatrix;

void main()
{
	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * position;
	VertexColor = color;
}