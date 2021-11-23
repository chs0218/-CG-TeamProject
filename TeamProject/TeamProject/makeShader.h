#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>

GLuint vShader;
GLuint fShader;
GLuint s_program;

void checkCompileErrors(unsigned int shader, std::string type);
int MakeVertexShader(const char* vertexPath, int n);
int MakeFragmentShader(const char* fragmentPath, int count);