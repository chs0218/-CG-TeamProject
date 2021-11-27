#include "objectManager.h"

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
	direction = Mode;
}