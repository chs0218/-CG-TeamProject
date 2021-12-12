#ifndef _function // 헤더파일에 재정의로 인한 오류를 막아줌
#define _function

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "objectManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define BOXSIZE 0.5

#define CARDSIZE 0.1

#define PLAYERNUM 3

float shapevertices[216];

GLfloat Card[] = {
	-CARDSIZE, CARDSIZE, 0, 0, 1,
	CARDSIZE, CARDSIZE, 0, 1, 1,
	-CARDSIZE, -CARDSIZE, 0, 0, 0,
	CARDSIZE, CARDSIZE, 0, 1, 1,
	-CARDSIZE, -CARDSIZE, 0, 0, 0,
	CARDSIZE, -CARDSIZE, 0, 1, 0,
};

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

GLfloat textureST[][2] = {
	{0.0, 0.0},
	{1.0, 0.0},
	{0.0, 1.0},
	{1.0, 1.0},
	{0.5, 1.0}
};

unsigned int textureindex[] = {
	// 육면체
	2, 0, 1,
	2, 1, 3
};

float texturevertices[72];

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
	7, 6, 5,
	7, 5, 4,
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

GLuint g_window_w = 1600;
GLuint g_window_h = 900;
GLuint ShapeVAO;
GLuint ShapeVBO;

GLuint ObjVAO;
GLuint ObjVBO;
GLuint ObjTexVBO;

GLuint CardVAO;
GLuint CardVBO;

unsigned int textures[16];
unsigned int objtextures[6];

objectManager Map[mapSize][mapSize];

objectManager Player1[PLAYERNUM];
objectManager Player2[PLAYERNUM];

CardManager Card1;
CardManager Card2;

int currentPlayer = 0;
int turn = 0;
int Player1Score = 0;
int Player2Score = 0;
bool MoveTime = false;

void Drawtext();
void InitBuffer();
void InitVertices();
void InitTextureVertices();
void InitGame();
void Display();
void Reshape(int w, int h);
void TimerFunc(int value);
void Keyboard(unsigned char key, int x, int y);
void InitBuffer_obj();
void InitTexture_obj();
void InitBuffer_card();
void InitTexture_card();
void change_card();
void check_collision();
#endif