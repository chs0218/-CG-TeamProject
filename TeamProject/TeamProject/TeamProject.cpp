#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "objRead.h"
#include "objRead.cpp"
#include "makeShader.h"
#include "makeShader.cpp"
#include "function.h"
#include "function.cpp"
#include <random>

// Reading Obj file
#define  _CRT_SECURE_NO_WARNINGS

using namespace std;

int main(int argc, char** argv)
{
	// create window using freeglut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(g_window_w, g_window_h);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Black & White");

	//////////////////////////////////////////////////////////////////////////////////////
	//// initialize GLEW
	//////////////////////////////////////////////////////////////////////////////////////
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Unable to initialize GLEW ... exiting" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		std::cout << "GLEW OK\n";
	}
	//////////////////////////////////////////////////////////////////////////////////////
	//// Create shader program an register the shader
	//////////////////////////////////////////////////////////////////////////////////////
	vShader = MakeVertexShader("vertex_object.glsl", 0);
	fShader = MakeFragmentShader("fragment_object.glsl", 0);

	vCardShader = MakeVertexShader("vertex_card.glsl", 0);
	fCardShader = MakeFragmentShader("fragment_card.glsl", 0);

	vObjShader = MakeVertexShader("vertex_texture_object.glsl", 0);
	fObjShader = MakeFragmentShader("fragment_texture_object.glsl", 0);

	// shader Program
	s_program = glCreateProgram();
	glAttachShader(s_program, vShader);
	glAttachShader(s_program, fShader);
	glLinkProgram(s_program);
	checkCompileErrors(s_program, "PROGRAM");

	s_Cardprogram = glCreateProgram();
	glAttachShader(s_Cardprogram, vCardShader);
	glAttachShader(s_Cardprogram, fCardShader);
	glLinkProgram(s_Cardprogram);
	checkCompileErrors(s_Cardprogram, "PROGRAM_card");

	s_Objprogram = glCreateProgram();
	glAttachShader(s_Objprogram, vObjShader);
	glAttachShader(s_Objprogram, fObjShader);
	glLinkProgram(s_Objprogram);
	checkCompileErrors(s_Objprogram, "PROGRAM_obj");

	InitVertices();
	InitTextureVertices();
	InitBuffer();
	InitBuffer_card();
	InitTexture_card();
	InitBuffer_obj();
	InitTexture_obj();
	InitGame();
	
	// callback functions
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(25, TimerFunc, 1);

	// freeglut ������ �̺�Ʈ ó�� ����. �����찡 ���������� ���ѷ��� ����.
	glutMainLoop();

	return 0;
}