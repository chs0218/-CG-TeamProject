#version 330
//--- in_Position: attribute index 0 
//--- in_Color: attribute index 1

layout (location = 0) in vec3 in_Position; 

void main(void) 
{
gl_Position =  vec4 (in_Position, 1.0) ;
}