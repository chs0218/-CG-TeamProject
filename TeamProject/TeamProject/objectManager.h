#ifndef objectManager

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <random>
#include <time.h>

#define mapSize 20
#define CARDNUM 5

enum directionMode { STOP, FRONTUP, BACKUP, LEFTUP, RIGHTUP, FRONTDOWN, BACKDOWN, LEFTDOWN, RIGHTDOWN, FRONT, BACK, LEFT, RIGHT, FALL};

class objectManager { //카드 혹은 장판의 오브젝트 애니매이션을 관리할 클래스
	GLfloat objectRGB[3]{0.0f};
	GLfloat size = 0.5;
	int direction = STOP, x = 0, y = 0, z = 0, dis = 0, frame = 0;
	bool dead = false;
public:
	glm::mat4 transform = glm::mat4(1.0f);

	objectManager();
	~objectManager(){}
	
	void rotateMatrix(GLfloat degree, int base);

	void translateMatrix(GLfloat x, GLfloat y, GLfloat z);

	void scaleMatrix(GLfloat rateX, GLfloat rateY, GLfloat rateZ);

	void changeDirection(int Mode, int Dis);

	void setHeight(int height);

	int getX();
	int getY();
	int getZ();

	bool checkDead();

	void die();

	void setZero();

	void returnPlace();

	void initPlayer(GLfloat BoxSize, int index);

	void move(int frontHeight, int backHeight, int frontfrontHeight, int backbackHeight);
};

class CardManager { //카드 혹은 장판의 오브젝트 애니매이션을 관리할 클래스
	int cardMove[CARDNUM]; //0(비어있음), 1, 2, 3, 4, 5(mapDown), 6(Object warp)
	int cardDirection[CARDNUM];

public:
	glm::mat4 transform[CARDNUM];
	bool DistroyMap;

	CardManager();
	~CardManager() = default;

	void cardInsert(int cardKind, int direction);
	void cardDelete(int index);

	void translateMatrix(int index, GLfloat x, GLfloat y, GLfloat z);
	int getCardMove(int index);
	int getcardDirection(int index);
};



#endif
