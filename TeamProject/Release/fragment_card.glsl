#version 330 core

in vec2 TexCord;

uniform sampler2D outTexture;

out vec4 FlagColor;

void main()
{
	FlagColor = texture(outTexture, TexCord);
}