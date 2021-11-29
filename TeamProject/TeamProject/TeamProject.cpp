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
#include <time.h>

time_t timer = time(NULL);

std::default_random_engine dre((unsigned int)timer);
std::uniform_int_distribution<> uidRine{ 0 , 19 };
std::uniform_int_distribution<> uidRow{ 0 , 2 };

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

	// shader Program
	s_program = glCreateProgram();
	glAttachShader(s_program, vShader);
	glAttachShader(s_program, fShader);
	glLinkProgram(s_program);
	checkCompileErrors(s_program, "PROGRAM");

	InitVertices();
	InitBuffer();

	for (int i = 0; i < mapSize; ++i) {
		for (int j = 0; j < mapSize; ++j) {
			Map[i][j].translateMatrix(-BOXSIZE * 19 + (j * 2.0 * BOXSIZE), BOXSIZE, -BOXSIZE * 19 + (i * 2.0 * BOXSIZE));
		}
	}

	for (int i = 0; i < PLAYERNUM; ++i) {
		Player1[i].translateMatrix(-BOXSIZE * 19 +  + ((GLfloat)uidRine(dre) * 2.0 * BOXSIZE), BOXSIZE * 3, -BOXSIZE * 19 + ((GLfloat)uidRow(dre) * 2.0 * BOXSIZE));
	}

	for (int i = 0; i < PLAYERNUM; ++i) {
		Player2[i].translateMatrix(-BOXSIZE * 19 + (((GLfloat)uidRine(dre)) * (2 * BOXSIZE)), BOXSIZE * 3, -BOXSIZE * 19 + (((GLfloat)uidRow(dre) + 17) * (2.0 * BOXSIZE)));
	}

	// callback functions
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(25, TimerFunc, 1);

	// freeglut ������ �̺�Ʈ ó�� ����. �����찡 ���������� ���ѷ��� ����.
	glutMainLoop();

	return 0;
}