#include<bangtal.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
SceneID scene1;
ObjectID pice[10], startButton;

int piceX[9] = { 0, 426, 852, 0, 426, 852, 0,  426, 852 };
int piceY[9] = { 480, 480, 480, 240, 240, 240, 0, 0, 0 };

void change(int init, int fin) {
	srand((unsigned int)time(NULL));
	locateObject(pice[init], scene1, piceX[(rand() + fin) % 9], piceY[(rand() - fin) % 9]);
	locateObject(pice[fin], scene1, piceX[(rand() + init) % 9], piceY[(rand() - init) % 9]);
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	for (int i = 0; i < 9; i++) {
		srand((unsigned int)time(NULL));
		if (object == startButton) {
			locateObject(pice[i], scene1, piceX[(rand() + i) % 9], piceY[(rand() - i) % 9]);
			showObject(pice[9]);
			hideObject(startButton);
		}
		else if (object == pice[i]) {
			change(i, 9);
		}
	}
}


int main() {

	setMouseCallback(mouseCallback);

	scene1 = createScene("sunflowerPuzzle", "background.jpg");
	pice[0] = createObject("1.jpg");
	pice[1] = createObject("2.jpg");
	pice[2] = createObject("3.jpg");
	pice[3] = createObject("4.jpg");
	pice[4] = createObject("5.jpg");
	pice[5] = createObject("6.jpg");
	pice[6] = createObject("7.jpg");
	pice[7] = createObject("8.jpg");
	pice[8] = createObject("9.jpg");
	startButton = createObject("start.jpg");
	pice[9] = createObject("blank.jpg");

	time_t start = time(NULL);
	int sum = 0;
	for (int i = 0; i < 10000; ++i) sum += i;
	printf("sum = %d\n", sum);

	time_t end = time(NULL);
	printf("Time : %1f\n", difftime(end, start));

	for (int i = 0; i < 9; i++) {
		locateObject(pice[i], scene1, piceX[i], piceY[i]);
		showObject(pice[i]);
	}
	locateObject(startButton, scene1, 640, 100);
	showObject(startButton);
	locateObject(pice[9], scene1, piceX[rand() % 9], piceY[rand() % 9]);
	startGame(scene1);
}

