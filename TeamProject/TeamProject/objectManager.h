#ifndef objectManager

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <random>
#include <time.h>

enum directionMode { STOP, FRONTUP, BACKUP, LEFTUP, RIGHTUP, FRONTDOWN, BACKDOWN, LEFTDOWN, RIGHTDOWN, FRONT, BACK, LEFT, RIGHT };

class objectManager { //카드 혹은 장판의 오브젝트 애니매이션을 관리할 클래스
	GLfloat objectRGB[3]{0.0f};
	GLfloat size = 0.5;
	int direction = STOP, x = 0, y = 0, z = 0, frame = 0;
public:
	glm::mat4 transform = glm::mat4(1.0f);

	objectManager();
	~objectManager(){}
	
	void rotateMatrix(GLfloat degree, int base);

	void translateMatrix(GLfloat x, GLfloat y, GLfloat z);

	void scaleMatrix(GLfloat rateX, GLfloat rateY, GLfloat rateZ);

	void changeDrection(int Mode);

	void setZero();

	void returnPlace();

	void initPlayer(GLfloat BoxSize, int index);

	void move();
};

#endif
