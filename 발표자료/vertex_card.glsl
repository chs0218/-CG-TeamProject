#version 330 core
layout (location = 0) in vec3 in_Position;
layout (location = 1) in vec2 vTexCord;

out vec2 TexCord;

uniform mat4 modelTransform;

void main()
{
	gl_Position = modelTransform * vec4(in_Position, 1.0);
	TexCord = vTexCord;
}