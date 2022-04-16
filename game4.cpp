#include <bangtal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

TimerID timer;
SceneID room;
ObjectID startButton, endButton;
ObjectID picture[16];
bool numbers[8], two = false, dob[16];
int q = 20;
int r[16] = {1,8,3,5,3,6,1,2,7,2,5,4,4,6,7,8};
int X[16] = { 0,0,0,0,200,200,200,200,400,400,400,400,600,600,600,600 };
int Y[16] = { 0,200,400,600,0,200,400,600, 0,200,400,600, 0,200,400,600 };


ObjectID createObject(const char* image, SceneID scene, int x, int y, bool show) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);

	if (show == true) {
		showObject(object);
	}
	return object;
}

void play() {

	for (int i = 0;i < 8;++i) {
		for(int a=15;a>7;--a){
		int t = r[i];
		r[i] = r[a];
		r[a] = t;
		}
	}
}

void to(int i) {
	char filename[25];
	sprintf_s(filename, "%d.png", r[i]);
	picture[i] = createObject(filename, room, X[i], Y[i], true);
	dob[i] = true;
	if (q == 20) {
		q = i; 
	}
}

void go(int c) {
	if ((q != 20)) {
        if ((r[q] == r[c])&&(c!=q)) {
			char filename[25];
			sprintf_s(filename, "%d.png", r[c]);
			picture[c] = createObject(filename, room, X[c], Y[c], true);
			int z;
			z = r[q] - 1;
			numbers[z] = true;
			q = 20;
		}
		else {
			dob[q] = false;
			dob[c] = false;
			hideObject(startButton);
			picture[q] = createObject("0.png", room, X[q], Y[q], true);
			picture[c] = createObject("0.png", room, X[c], Y[c], true);
			q = 20;
		}
	}
		
		if ((numbers[0] == true) && (numbers[1] == true) && (numbers[2] == true) && (numbers[3] == true) &&
			(numbers[4] == true) && (numbers[5] == true) && (numbers[6] == true) && (numbers[7] == true)) {
			
			startButton = createObject("restart.png", room, 380, 400, true);
			endButton = createObject("end.png", room, 380, 350, true);
			showMessage("성공~~~");
		}
}

void startGame() {
	hideObject(endButton);
	hideObject(startButton);

	play();
	two = true;
	for (int i = 0;i < 16;++i) {
		dob[i] = false;
		picture[i] = createObject("0.png", room, X[i], Y[i], true);
	}
	for (int i = 0;i< 8;++i) {
		numbers[i] = false;
	}

}


void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == startButton) {
		startGame();
	}
	else if (object == endButton) {
		endGame();
	}
	else if (object == picture[0]) {
		two = !two;
		to(0);
		if (two == true) {
			go(0);
		}
	}
	else if (object == picture[1]) {
		two = !two;
		to(1);
		if (two == true) {
			go(1);
		}
	}
	else if (object == picture[2]) {
		two = !two;
		to(2);
		if (two == true) {
			go(2);
		}
	}
	else if (object == picture[3]) {
		two = !two;
		to(3);
		if (two == true) {
			go(3);
		}
	}
	else if (object == picture[4]) {
		two = !two;
		to(4);
		if (two == true) {
			go(4);
		}
	}
	else if (object == picture[5]) {
		two = !two;
		to(5);
		if (two == true) {
			go(5);
		}
	}
	else if (object == picture[6]) {
		two = !two;
		to(6);
		if (two == true) {
			go(6);
		}
	}
	else if (object == picture[7]) {
		two = !two;
		to(7);
		if (two == true) {
			go(7);
		}
	}
	else if (object == picture[8]) {
		two = !two;
		to(8);
		if (two == true) {
			go(8);
		}
	}
	else if (object == picture[9]) {
		two = !two;
		to(9);
		if (two == true) {
			go(9);
		}
	}
	else if (object == picture[10]) {
		two = !two;
		to(10);
		if (two == true) {
			go(10);
		}
	}
	else if (object == picture[11]) {
		two = !two;
		to(11);
		if (two == true) {
			go(11);
		}
	}
	else if (object == picture[12]) {
		two = !two;
		to(12);
		if (two == true) {
			go(12);
		}
	}
	else if (object == picture[13]) {
		two = !two;
		to(13);
		if (two == true) {
			go(13);
		}
	}
	if (object == picture[14]) {
		two = !two;
		to(14);
		if (two == true) {
			go(14);
		}
	}
	else if (object == picture[15]) {
		two = !two;
		to(15);
		if (two == true) {
			go(15);
		}
	}
}

int main() {
	setMouseCallback(mouseCallback);

	room = createScene("room", "배경.png");
	startButton = createObject("start.png", room, 380, 400, true);
	endButton = createObject("end.png", room, 380, 350, true);

	for (int i = 0;i < 16;++i) {
		picture[i] = createObject("0.png", room, X[i], Y[i], false);
	}

	startGame(room);
}