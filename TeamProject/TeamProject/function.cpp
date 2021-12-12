#include "function.h"
#include <random>

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
	unsigned char* data = stbi_load("Front-1.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[1]);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Front-2.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[2]);
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Front-3.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[3]);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Front-4.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[4]);
	glBindTexture(GL_TEXTURE_2D, textures[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Back-1.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[5]);
	glBindTexture(GL_TEXTURE_2D, textures[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Back-2.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[6]);
	glBindTexture(GL_TEXTURE_2D, textures[6]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Back-3.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[7]);
	glBindTexture(GL_TEXTURE_2D, textures[7]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Back-4.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[8]);
	glBindTexture(GL_TEXTURE_2D, textures[8]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Left-1.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[9]);
	glBindTexture(GL_TEXTURE_2D, textures[9]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Left-2.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[10]);
	glBindTexture(GL_TEXTURE_2D, textures[10]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Left-3.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[11]);
	glBindTexture(GL_TEXTURE_2D, textures[11]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Left-4.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[12]);
	glBindTexture(GL_TEXTURE_2D, textures[12]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Right-1.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[13]);
	glBindTexture(GL_TEXTURE_2D, textures[13]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Right-2.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[14]);
	glBindTexture(GL_TEXTURE_2D, textures[14]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Right-3.png", &widthImage, &heightImage, &numberOfChannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenTextures(1, &textures[15]);
	glBindTexture(GL_TEXTURE_2D, textures[15]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("Right-4.png", &widthImage, &heightImage, &numberOfChannel, 0);
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
	modelLocation = glGetUniformLocation(s_Cardprogram, "modelTransform");


	for (int i = 0; i < CARDNUM; ++i) {
		int cardMove = Card1.getCardMove(i);
		int cardDirection = Card1.getcardDirection(i);
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Card1.transform[i]));
		glBindVertexArray(CardVAO);
		glActiveTexture(GL_TEXTURE0);
		if (cardMove != 0) {
			glBindTexture(GL_TEXTURE_2D, textures[(cardDirection - 9) * 4 + cardMove - 1]);
			glDrawArrays(GL_TRIANGLES, 0, 6);
		}

		cardMove = Card2.getCardMove(i);
		cardDirection = Card2.getcardDirection(i);
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Card2.transform[i]));
		glBindVertexArray(CardVAO);
		glActiveTexture(GL_TEXTURE0);
		if (cardMove != 0) {
			glBindTexture(GL_TEXTURE_2D, textures[(cardDirection - 9) * 4 + cardMove - 1]);
			glDrawArrays(GL_TRIANGLES, 0, 6);
		}
	}
	

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
		Player1[i].move(Map[Player1[i].getZ() - 1][Player1[i].getX()].getY(), Map[Player1[i].getZ() + 1][Player1[i].getX()].getY(), Map[Player1[i].getZ() - 2][Player1[i].getX()].getY(), Map[Player1[i].getZ() + 2][Player1[i].getX()].getY());
		Player2[i].move(Map[Player2[i].getZ() - 1][Player2[i].getX()].getY(), Map[Player2[i].getZ() + 1][Player2[i].getX()].getY(), Map[Player2[i].getZ() - 2][Player2[i].getX()].getY(), Map[Player2[i].getZ() + 2][Player2[i].getX()].getY());
	}

	if (turn % 5 == 0) {
		Card2.DistroyMap = true;
	}
	else if (turn % 5 == 1) {
		Card1.DistroyMap = true;
	}

	glutTimerFunc(25, TimerFunc, 1);
	glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y)
{
	time_t timer = time(NULL);

	std::default_random_engine dreCard((unsigned int)timer);
	std::uniform_int_distribution<> uid_card{ 1, 4 };
	std::uniform_int_distribution<> uid_cardDirection{ FRONT, FALL };

	int uid_dis = uid_card(dreCard);
	int uid_dir = uid_cardDirection(dreCard);

	switch (key)
	{
	case '1': // 플레이어를 선택하고 이동 벽면 충돌 못함
		if (turn % 2 == 0) {
			if (MoveTime) {
				if (uid_dir == FALL)
					uid_dir = FRONT;
				Card2.cardInsert(uid_dis, uid_dir);
				Player2[currentPlayer].changeDirection(Card2.getcardDirection(0), Card2.getCardMove(0));
				Card2.cardDelete(0);
				turn++;

			}
		}
		else {
			if (MoveTime) {
				if (uid_dir == FALL)
					uid_dir = BACK;
				Card1.cardInsert(uid_dis, uid_dir);
				Player1[currentPlayer].changeDirection(Card1.getcardDirection(0), Card1.getCardMove(0));
				Card1.cardDelete(0);
				turn++;
			}
		}
		
		MoveTime = false; // 플레이어 오브젝트 선택 -> true -> 카드선택 -> 움직임 -> false
	case '2':
		if (turn % 2 == 0) {
			if (MoveTime) {
				if (uid_dir == FALL)
					uid_dir = FRONT;
				Card2.cardInsert(uid_dis, uid_dir);
				Player2[currentPlayer].changeDirection(Card2.getcardDirection(1), Card2.getCardMove(1));
				Card2.cardDelete(1);
				turn++;
			}
		}
		else {
			if (MoveTime) {
				if (uid_dir == FALL)
					uid_dir = BACK;
				Card1.cardInsert(uid_dis, uid_dir);
				Player1[currentPlayer].changeDirection(Card1.getcardDirection(1), Card1.getCardMove(1));
				Card1.cardDelete(1);
				turn++;
			}
		}
		MoveTime = false;
		break;
	case '3':
		if (turn % 2 == 0) {
			if (MoveTime) {
				if (uid_dir == FALL)
					uid_dir = FRONT;
				Card2.cardInsert(uid_dis, uid_dir);
				Player2[currentPlayer].changeDirection(Card2.getcardDirection(2), Card2.getCardMove(2));
				Card2.cardDelete(2);
				turn++;
			}
		}
		else {
			if (MoveTime) {
				if (uid_dir == FALL)
					uid_dir = BACK;
				Card1.cardInsert(uid_dis, uid_dir);
				Player1[currentPlayer].changeDirection(Card1.getcardDirection(2), Card1.getCardMove(2));
				Card1.cardDelete(2);
				turn++;
			}
		}
		MoveTime = false;
		break;
	case '4':
		if (turn % 2 == 0) {
			if (MoveTime) {
				if (uid_dir == FALL)
					uid_dir = FRONT;
				Card2.cardInsert(uid_dis, uid_dir);
				Player2[currentPlayer].changeDirection(Card2.getcardDirection(3), Card2.getCardMove(3));
				Card2.cardDelete(3);
				turn++;
			}
		}
		else {
			if (MoveTime) {
				if (uid_dir == FALL)
					uid_dir = BACK;
				Card1.cardInsert(uid_dis, uid_dir);
				Player1[currentPlayer].changeDirection(Card1.getcardDirection(3), Card1.getCardMove(3));
				Card1.cardDelete(3);
				turn++;
			}
		}
		MoveTime = false;
		break;
	case '5':
		if (turn % 2 == 0) {
			if (MoveTime) {
				if (uid_dir == FALL)
					uid_dir = FRONT;
				Card2.cardInsert(uid_dis, uid_dir);
				Player2[currentPlayer].changeDirection(Card2.getcardDirection(4), Card2.getCardMove(4));
				Card2.cardDelete(4);
				turn++;
			}
		}
		else {
			if (MoveTime) {
				if (uid_dir == FALL)
					uid_dir = BACK;
				Card1.cardInsert(uid_dis, uid_dir);
				Player1[currentPlayer].changeDirection(Card1.getcardDirection(4), Card1.getCardMove(4));
				Card1.cardDelete(4);
				turn++;
			}
		}
		MoveTime = false;
		break;
	case '6': // 이상하게 버그남
		if (turn % 2 == 0) {
			if (Card2.DistroyMap) {
				int x;
				int y;
				std::cin >> x >> y;
				Map[y][x].changeDirection(FALL, 99);
				turn++;
			}
		}
		else {
			if (Card2.DistroyMap) {
				int x;
				int y;
				std::cin >> x >> y;
				Map[y][x].changeDirection(FALL, 99);
				turn++;
			}
		}
		break;
	case 'A':
	case 'a': // 처음 플레이어 선택
		MoveTime = true;
		currentPlayer = 0; // 현재 플래이서 선택 넘버
		break;
	case 'S':
	case 's':
		MoveTime = true;
		currentPlayer = 1;
		break;
	case 'D':
	case 'd':
		MoveTime = true;
		currentPlayer = 2;
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
	int height = 0;
	time_t timer = time(NULL);

	std::default_random_engine dreCard((unsigned int)timer);
	std::uniform_int_distribution<> uid_card{ 1, 4 };
	std::uniform_int_distribution<> uid_cardDirection{ FRONT, FALL };

	std::default_random_engine dre((unsigned int)timer);
	std::uniform_int_distribution<> uidHeight{ -1, 1 };

	for (int i = 0; i < mapSize; ++i) {
		for (int j = 0; j < mapSize; ++j) {
			Map[i][j].translateMatrix(-BOXSIZE * 19 + (j * 2.0 * BOXSIZE), BOXSIZE * (1 + 2 * height), -BOXSIZE * 19 + (i * 2.0 * BOXSIZE));
			Map[i][j].setHeight(height);
		}
		if (i > 2 && i < mapSize - 2)
		{
			if (height > 1)
				height -= 1;
			else if (height < -1)
				height += 1;
			else
				height += uidHeight(dre);
		}
	}
	for (int i = 0; i < PLAYERNUM; ++i) {
		Player1[i].initPlayer(BOXSIZE, 0);
		Player1[i].setHeight(Map[Player1[i].getZ()][Player1[i].getX()].getY());
		Player1[i].translateMatrix(0, BOXSIZE * 2 * Map[Player1[i].getZ()][Player1[i].getX()].getY(), 0);
	}

	for (int i = 0; i < PLAYERNUM; ++i) {
		Player2[i].initPlayer(BOXSIZE, 2);
		Player2[i].setHeight(Map[Player2[i].getZ()][Player2[i].getX()].getY());
		Player2[i].translateMatrix(0, BOXSIZE * 2 * Map[Player2[i].getZ()][Player2[i].getX()].getY(), 0);
	}

	for (int i = 0; i < CARDNUM; ++i) {
		Card2.translateMatrix(i, -0.9 + CARDSIZE * i * 2, -0.9, 0.0);
		Card1.translateMatrix(i, 0.9 - CARDSIZE * i * 2, 0.9, 0.0);
	}

	int uid_dis = uid_card(dreCard);
	int uid_dir = uid_cardDirection(dreCard);

	for (int i = 0; i < CARDNUM; ++i) {
		uid_dis = uid_card(dreCard);
		uid_dir = uid_cardDirection(dreCard);

		if (uid_dir == FALL)
			uid_dir = BACK;

		Card1.cardInsert(uid_dis, uid_dir);

		uid_dis = uid_card(dreCard);
		uid_dir = uid_cardDirection(dreCard);

		if (uid_dir == FALL)
			uid_dir = FRONT;

		Card2.cardInsert(uid_dis, uid_dir);
	}
}