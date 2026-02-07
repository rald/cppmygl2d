#include "mygl2d.hpp"
#include "turtle.hpp"

#define GAME_TITLE "Game"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

bool quit=false;

double lastTime=0,currentTime=0,deltaTime=0;

bool inrect(int x,int y,int rx,int ry,int w,int h) {
	return x>=rx && x<=rx+w && y>=ry && y<=ry+h;
}

bool incirc(int x,int y,int cx,int cy,int cr) {
	return (cx-x)*(cx-x) + (cy-y)*(cy-y) < cr*cr;
}

void star(Turtle* turtle,double s) {
	for(int i = 0; i < 5; i++) {
		turtle->move(s);
		turtle->turn(144);
	}
}

void draw() {
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, -1, 1);

	Turtle* turtle = new Turtle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	turtle->setPenColor(255, 255, 0);

	turtle->turn(18);

	star(turtle,100);

	turtle->penUp();
	turtle->move(50);
	turtle->penDown();
	star(turtle,50);

	turtle->penUp();
	turtle->move(25);
	turtle->penDown();
	star(turtle,25);

	glFlush();
	glfwSwapBuffers();
}

void update(double deltaTime) {}

int main(int argc, char** argv) {
	glfwInit();

	glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE,GL_TRUE);
	glfwOpenWindow(SCREEN_WIDTH,SCREEN_HEIGHT,0, 0, 0, 0, 0, 0,GLFW_WINDOW);
	glfwSetWindowTitle(GAME_TITLE);
//	glfwDisable(GLFW_MOUSE_CURSOR);

	draw();

	glfwSleep(5);

/*
	while(!quit) {
		currentTime=glfwGetTime();
		deltaTime=currentTime-lastTime;
		lastTime=currentTime;

//		update(deltaTime);

//		draw();

		glFlush();
		glfwSwapBuffers();
		glfwPollEvents();

		if(glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS) quit = true;
	}
*/


	return 0;
}
