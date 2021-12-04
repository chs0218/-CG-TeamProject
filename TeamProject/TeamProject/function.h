#ifndef _function // 헤더파일에 재정의로 인한 오류를 막아줌
#define _function

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "objectManager.h"

#define BOXSIZE 0.5

#define mapSize 20

#define PLAYERNUM 3

float shapevertices[216];

GLfloat cubeDots[][3] = {
	// 육면체
	{-BOXSIZE, BOXSIZE, BOXSIZE},
	{-BOXSIZE, -BOXSIZE, BOXSIZE},
	{BOXSIZE, -BOXSIZE, BOXSIZE},
	{BOXSIZE, BOXSIZE, BOXSIZE},
	{-BOXSIZE, BOXSIZE, -BOXSIZE},
	{-BOXSIZE, -BOXSIZE, -BOXSIZE},
	{BOXSIZE, -BOXSIZE, -BOXSIZE},
	{BOXSIZE, BOXSIZE, -BOXSIZE}
};


GLfloat cubeNormal[][3] = {
	{0.0, 0.0, 1.0},
	{0.0, 0.0, -1.0},
	{1.0, 0.0, 0.0},
	{-1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{0.0, -1.0, 0.0}
};

unsigned int cubeShapeindex[] = {
	// 육면체
	0, 1, 2,
	0, 2, 3,
	4, 6, 5,
	4, 7, 6,
	3, 2, 6,
	3, 6, 7,
	4, 5, 1,
	4, 1, 0,
	4, 0, 3,
	4, 3, 7,
	1, 5, 6,
	1, 6, 2
};

unsigned int cubeNormalindex[] = {
	// 육면체
	0, 0, 0,
	0, 0, 0,
	1, 1, 1,
	1, 1, 1,
	2, 2, 2,
	2, 2, 2,
	3, 3, 3,
	3, 3, 3,
	4, 4, 4,
	4, 4, 4,
	5, 5, 5,
	5, 5, 5
};

GLuint g_window_w = 1400;
GLuint g_window_h = 900;
GLuint ShapeVAO;
GLuint ShapeVBO;

objectManager Map[mapSize][mapSize];

objectManager Player1[PLAYERNUM];
objectManager Player2[PLAYERNUM];

void InitBuffer();
void InitGame();
void Display();
void Reshape(int w, int h);
void TimerFunc(int value);
void Keyboard(unsigned char key, int x, int y);

#endif