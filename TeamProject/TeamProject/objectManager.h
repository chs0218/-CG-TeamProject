#ifndef objectManager

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum directionMode { STOP, UP, DOWN, FRONT, BACK, LEFT, RIGHT };

class objectManager { //ī�� Ȥ�� ������ ������Ʈ �ִϸ��̼��� ������ Ŭ����
	
	GLfloat objectRGB[3]{0.0f};
	GLfloat direction = STOP;
public:
	glm::mat4 transform = glm::mat4(1.0f);

	objectManager();
	~objectManager(){}
	
	void rotateMatrix(GLfloat degree, int base);

	void translateMatrix(GLfloat x, GLfloat y, GLfloat z);

	void scaleMatrix(GLfloat rateX, GLfloat rateY, GLfloat rateZ);

	void changeDrection(int Mode);


};

#endif
