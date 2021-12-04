#include "objectManager.h"

time_t timer = time(NULL);

std::default_random_engine dre((unsigned int)timer);
std::uniform_int_distribution<> uidRine{ 0 , 19 };
std::uniform_int_distribution<> uidRow{ 0 , 2 };

objectManager::objectManager() {
	transform = glm::mat4(1.0f);
}

void objectManager::rotateMatrix(GLfloat degree, int base) {//base 어떤 축 기준 회전? -> 1 = x축, 2 = y축, 3 = z축
	glm::mat4 rt(1.0f);

	if (base == 1) {
		rt = glm::rotate(rt, (GLfloat)glm::radians(degree), glm::vec3(1.0f, 0.0f, 0.0f));
	}
	else if (base == 2) {
		rt = glm::rotate(rt, (GLfloat)glm::radians(degree), glm::vec3(0.0f, 1.0f, 0.0f));
	}
	else if (base == 3) {
		rt = glm::rotate(rt, (GLfloat)glm::radians(degree), glm::vec3(0.0f, 0.0f, 1.0f));
	}

	transform = rt * transform;
}

void objectManager::translateMatrix(GLfloat x, GLfloat y, GLfloat z) {
	glm::mat4 tr(1.0f);

	tr = glm::translate(tr, glm::vec3(x, y, z));

	transform = tr * transform;
}

void objectManager::scaleMatrix(GLfloat rateX, GLfloat rateY, GLfloat rateZ) {
	glm::mat4 sc(1.0f);

	sc = glm::scale(sc, glm::vec3(rateX, rateY, rateZ));

	transform = sc * transform;
}

void objectManager::changeDrection(int Mode) {
	if(direction == STOP)
		direction = Mode;
}

void objectManager::initPlayer(GLfloat BoxSize, int index) {

	// 주석 해제시 랜덤한 위치
	/*if (index == 0)
	{
		x = uidRine(dre);
		y = 0;
		z = uidRow(dre);
		size = BoxSize;
		translateMatrix(-BoxSize * 19 + ((GLfloat)x * 2.0 * BoxSize), BoxSize * 3, -BoxSize * 19 + ((GLfloat)z * 2.0 * BoxSize));

	}
	else
	{
		x = uidRine(dre);
		y = 0;
		z = uidRow(dre) + 17;
		size = BoxSize;
		translateMatrix(-BoxSize * 19 + ((GLfloat)x * 2.0 * BoxSize), BoxSize * 3, -BoxSize * 19 + ((GLfloat)z * 2.0 * BoxSize));
	}*/

	// 중앙 위치(객체 이동 테스트하기 위함)
	x = 10;
	y = 0;
	z = 10;
	size = BoxSize;
	translateMatrix(-BoxSize * 19 + ((GLfloat)x * 2.0 * BoxSize), BoxSize * 3, -BoxSize * 19 + ((GLfloat)z * 2.0 * BoxSize));
}

void objectManager::setZero() {
	translateMatrix(size * 19 - ((GLfloat)x * 2.0 * size), -size * (3 + 2 * y), size * 19 - ((GLfloat)z * 2.0 * size));
}

void objectManager::returnPlace() {
	translateMatrix(-size * 19 + ((GLfloat)x * 2.0 * size), size * (3 + 2 * y), -size * 19 + ((GLfloat)z * 2.0 * size));
}

void objectManager::move() {

	switch (direction)
	{
	case STOP:
		break;
	case FRONTUP:
		if (frame < 36)
		{
			setZero();
			translateMatrix(size, -size, size);
			rotateMatrix(-5.0, 1);
			translateMatrix(-size, size, -size);
			returnPlace();
			frame += 1;
		}
		else
		{
			frame = 0;
			direction = STOP;
			y += 1;
			z -= 1;
		}
		break;
	case BACKUP:
		if (frame < 36)
		{
			setZero();
			translateMatrix(size, -size, -size);
			rotateMatrix(5.0, 1);
			translateMatrix(-size, size, size);
			returnPlace();
			frame += 1;
		}
		else
		{
			frame = 0;
			direction = STOP;
			y += 1;
			z += 1;
		}
		break;
	case LEFTUP:
		if (frame < 36)
		{
			setZero();
			translateMatrix(size, -size, size);
			rotateMatrix(5.0, 3);
			translateMatrix(-size, size, -size);
			returnPlace();
			frame += 1;
		}
		else
		{
			frame = 0;
			direction = STOP;
			x -= 1;
			y += 1;
		}
		break;
	case RIGHTUP:
		if (frame < 36)
		{
			setZero();
			translateMatrix(-size, -size, size);
			rotateMatrix(-5.0, 3);
			translateMatrix(size, size, -size);
			returnPlace();
			frame += 1;
		}
		else
		{
			frame = 0;
			direction = STOP;
			x += 1;
			y += 1;
		}
		break;
	case FRONTDOWN:
		if (frame < 36)
		{
			setZero();
			translateMatrix(size, size, size);
			rotateMatrix(-5.0, 1);
			translateMatrix(-size, -size, -size);
			returnPlace();
			frame += 1;
		}
		else
		{
			frame = 0;
			direction = STOP;
			y -= 1;
			z -= 1;
		}
		break;
	case BACKDOWN:
		if (frame < 36)
		{
			setZero();
			translateMatrix(size, size, -size);
			rotateMatrix(5.0, 1);
			translateMatrix(-size, -size, size);
			returnPlace();
			frame += 1;
		}
		else
		{
			frame = 0;
			direction = STOP;
			y -= 1;
			z += 1;
		}
		break;
	case LEFTDOWN:
		if (frame < 36)
		{
			setZero();
			translateMatrix(size, size, size);
			rotateMatrix(5.0, 3);
			translateMatrix(-size, -size, -size);
			returnPlace();
			frame += 1;
		}
		else
		{
			frame = 0;
			direction = STOP;
			x -= 1;
			y -= 1;
		}
		break;
	case RIGHTDOWN:
		if (frame < 36)
		{
			setZero();
			translateMatrix(-size, size, size);
			rotateMatrix(-5.0, 3);
			translateMatrix(size, -size, -size);
			returnPlace();
			frame += 1;
		}
		else
		{
			frame = 0;
			direction = STOP;
			x += 1;
			y -= 1;
		}
		break;
	case FRONT:
		if (frame < 18)
		{
			setZero();
			translateMatrix(size, size, size);
			rotateMatrix(-5.0, 1);
			translateMatrix(-size, -size, -size);
			returnPlace();
			frame += 1;
		}
		else
		{
			frame = 0;
			direction = STOP;
			z -= 1;
		}
		break;
	case BACK:
		if (frame < 18)
		{
			setZero();
			translateMatrix(size, size, -size);
			rotateMatrix(5.0, 1);
			translateMatrix(-size, -size, size);
			returnPlace();
			frame += 1;
		}
		else
		{
			frame = 0;
			direction = STOP;
			z += 1;
		}
		break;
	case LEFT:
		if (frame < 18)
		{
			setZero();
			translateMatrix(size, size, size);
			rotateMatrix(5.0, 3);
			translateMatrix(-size, -size, -size);
			returnPlace();
			frame += 1;
		}
		else
		{
			frame = 0;
			direction = STOP;
			x -= 1;
		}
		break;
	case RIGHT:
		if (frame < 18)
		{
			setZero();
			translateMatrix(-size, size, size);
			rotateMatrix(-5.0, 3);
			translateMatrix(size, -size, -size);
			returnPlace();
			frame += 1;
		}
		else
		{
			frame = 0;
			direction = STOP;
			x += 1;
		}
		break;
	default:
		break;
	}
}