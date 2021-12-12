#include "function.h"

void InitBuffer()
{
	glGenVertexArrays(1, &ShapeVAO);
	glGenBuffers(1, &ShapeVBO);

	glBindVertexArray(ShapeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, ShapeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(shapevertices), shapevertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glEnable(GL_DEPTH_TEST);
}

void InitBuffer_card()// 카드 전용 버퍼
{
	glGenVertexArrays(1, &CardVAO);
	glGenBuffers(1, &CardVBO);

	glBindVertexArray(CardVBO);
	glBindBuffer(GL_ARRAY_BUFFER, CardVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Card), Card, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
}

void InitTexture_card() // 카드 전용 텍스트 버퍼
{
	int widthImage, heightImage, numberOfChannel;

	glGenTextures(1, &textures[0]);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load("Move1.jpg", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[1]);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Move2.jpg", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[2]);
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Move3.jpg", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[3]);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Move4.jpg", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glUseProgram(s_Cardprogram);
	int tLocation = glGetUniformLocation(s_Cardprogram, "outTexture");
	glUniform1i(tLocation, 0);
}

void Display()
{
	glm::mat4 transformMatrix = glm::mat4(1.0f);
	glm::vec3 cameraPos = glm::vec3(5.0f, 6.0f, 8.0f); //--- 카메라 위치
	glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f); //--- 카메라 바라보는 방향
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); //--- 카메라 위쪽 방향
	glm::mat4 projection = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);

	unsigned int projectionLocation;
	unsigned int modelLocation;
	unsigned int viewLocation;
	int ambientLocation;
	int lightPosLocation;
	int lightColorLocation;
	int objColorLocation;
	int viewPosition;

	viewLocation = glGetUniformLocation(s_program, "viewTransform");	//---뷰변환행렬
	projectionLocation = glGetUniformLocation(s_program, "projectionTransform");	//---투영변환행렬
	lightPosLocation = glGetUniformLocation(s_program, "lightPos");		//---조명위치
	lightColorLocation = glGetUniformLocation(s_program, "lightColor"); //---조명색깔
	viewPosition = glGetUniformLocation(s_program, "viewPos");	//--- 카메라 위치
	modelLocation = glGetUniformLocation(s_program, "modelTransform");	//---모델변환행렬
	objColorLocation = glGetUniformLocation(s_program, "objectColor"); //---오브젝트색상
	ambientLocation = glGetUniformLocation(s_program, "ambient");	//---빛 세기

	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
	projection = glm::perspective(glm::radians(65.0f), (float)g_window_w / (float)g_window_h, 0.1f, 50.0f);
	projection = glm::translate(projection, glm::vec3(0.0, 0.0, -5.0));

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glUseProgram(s_program);

	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &projection[0][0]);
	glUniform3f(lightPosLocation, 0.0, 3.0, 8.0);
	glUniform3f(lightColorLocation, 1.0, 1.0, 1.0);
	glUniform3f(viewPosition, 0.0, 0.0, 4.0);
	glUniform1f(ambientLocation, 0.3);


	glBindVertexArray(ShapeVAO);
	for (int i = 0; i < mapSize; ++i) {
		for (int j = 0; j < mapSize; ++j) {
			if (j % 2 == i % 2) {
				glUniform3f(objColorLocation, 0.3, 0.3, 0.3);
			}
			else {
				glUniform3f(objColorLocation, 0.8, 0.8, 0.8);
			}

			glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Map[i][j].transform));
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
	}

	for (int i = 0; i < PLAYERNUM; ++i) {
		glUniform3f(objColorLocation, 0.3, 0.3, 0.3);
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Player1[i].transform));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	for (int i = 0; i < PLAYERNUM; ++i) {
		glUniform3f(objColorLocation, 0.8, 0.8, 0.8);
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Player2[i].transform));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	glUseProgram(s_Cardprogram); // 임의로 그려본 카드
	glm::mat4 submodel(1.0f);
	modelLocation = glGetUniformLocation(s_Cardprogram, "modelTransform");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(submodel));

	glBindVertexArray(CardVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glutSwapBuffers();
}


void Reshape(int w, int h)
{
	g_window_w = w;
	g_window_h = h;
	glViewport(0, 0, w, h);
}

void TimerFunc(int value)
{
	for (int i = 0; i < PLAYERNUM; ++i) {
		Player1[i].move();
		Player2[i].move();
	}
	glutTimerFunc(25, TimerFunc, 1);
	glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		Player2[0].changeDirection(FRONTUP, 1);
		break;
	case '2':
		Player2[0].changeDirection(BACKUP, 2);
		break;
	case '3':
		Player2[0].changeDirection(LEFTUP, 3);
		break;
	case '4':
		Player2[0].changeDirection(RIGHTUP, 4);
		break;
	case '5':
		Player2[0].changeDirection(FRONTDOWN, 3);
		break;
	case '6':
		Player2[0].changeDirection(BACKDOWN, 3);
		break;
	case '7':
		Player2[0].changeDirection(LEFTDOWN, 3);
		break;
	case '8':
		Player2[0].changeDirection(RIGHTDOWN, 3);
		break;
	case 'A':
	case 'a':
		Player2[0].changeDirection(FRONT, 3);
		break;
	case 'S':
	case 's':
		Player2[0].changeDirection(BACK, 3);
		break;
	case 'D':
	case 'd':
		Player2[0].changeDirection(LEFT, 3);
		break;
	case 'F':
	case 'f':
		Player2[0].changeDirection(RIGHT, 3);
		break;
	case 'Q':
	case 'q':
		glutLeaveMainLoop();
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void InitVertices()
{
	for (int i = 0; i < 12; ++i)
	{
		shapevertices[18 * i] = cubeDots[cubeShapeindex[3 * i]][0];
		shapevertices[18 * i + 1] = cubeDots[cubeShapeindex[3 * i]][1];
		shapevertices[18 * i + 2] = cubeDots[cubeShapeindex[3 * i]][2];
		shapevertices[18 * i + 3] = cubeNormal[cubeNormalindex[3 * i]][0];
		shapevertices[18 * i + 4] = cubeNormal[cubeNormalindex[3 * i]][1];
		shapevertices[18 * i + 5] = cubeNormal[cubeNormalindex[3 * i]][2];

		shapevertices[18 * i + 6] = cubeDots[cubeShapeindex[3 * i + 1]][0];
		shapevertices[18 * i + 7] = cubeDots[cubeShapeindex[3 * i + 1]][1];
		shapevertices[18 * i + 8] = cubeDots[cubeShapeindex[3 * i + 1]][2];
		shapevertices[18 * i + 9] = cubeNormal[cubeNormalindex[3 * i + 1]][0];
		shapevertices[18 * i + 10] = cubeNormal[cubeNormalindex[3 * i + 1]][1];
		shapevertices[18 * i + 11] = cubeNormal[cubeNormalindex[3 * i + 1]][2];

		shapevertices[18 * i + 12] = cubeDots[cubeShapeindex[3 * i + 2]][0];
		shapevertices[18 * i + 13] = cubeDots[cubeShapeindex[3 * i + 2]][1];
		shapevertices[18 * i + 14] = cubeDots[cubeShapeindex[3 * i + 2]][2];
		shapevertices[18 * i + 15] = cubeNormal[cubeNormalindex[3 * i + 2]][0];
		shapevertices[18 * i + 16] = cubeNormal[cubeNormalindex[3 * i + 2]][1];
		shapevertices[18 * i + 17] = cubeNormal[cubeNormalindex[3 * i + 2]][2];
	}
}

void InitGame()
{
	for (int i = 0; i < mapSize; ++i) {
		for (int j = 0; j < mapSize; ++j) {
			Map[i][j].translateMatrix(-BOXSIZE * 19 + (j * 2.0 * BOXSIZE), BOXSIZE, -BOXSIZE * 19 + (i * 2.0 * BOXSIZE));
		}
	}

	for (int i = 0; i < PLAYERNUM; ++i) {
		Player1[i].initPlayer(BOXSIZE, 0);
	}

	for (int i = 0; i < PLAYERNUM; ++i) {
		Player2[i].initPlayer(BOXSIZE, 1);
	}
}