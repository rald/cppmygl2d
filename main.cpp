#include "mygl2d.hpp"

#define GAME_TITLE "Game"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

bool quit=false;

double lastTime=0,currentTime=0,deltaTime=0;

MyGL2D gl;

bool inrect(int x,int y,int rx,int ry,int w,int h) {
	return x>=rx && x<=rx+w && y>=ry && y<=ry+h;
}

bool incirc(int x,int y,int cx,int cy,int cr) {
	return (cx-x)*(cx-x) + (cy-y)*(cy-y) < cr*cr;
}

void update(double deltaTime) {
}

void draw() {
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, -1, 1);

	gl.clearScreen();

	gl.setColor(255,255,255);

	gl.drawPoint(26,25);
	gl.drawLine(56,1,100,50);
	gl.drawRect(110,1,50,50);
	gl.fillRect(165,0,50,50);
	gl.drawCircle(246,26,25);
	gl.fillCircle(301,26,25);

	glFlush();
	glfwSwapBuffers();
}

int main(int argc, char** argv) {
	glfwInit();

	glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE,GL_TRUE);
	glfwOpenWindow(SCREEN_WIDTH,SCREEN_HEIGHT,0, 0, 0, 0, 0, 0,GLFW_WINDOW);
	glfwSetWindowTitle(GAME_TITLE);
//	glfwDisable(GLFW_MOUSE_CURSOR);

	while(!quit) {
		currentTime=glfwGetTime();
		deltaTime=currentTime-lastTime;
		lastTime=currentTime;

		update(deltaTime);

		draw();

		quit = glfwGetKey(GLFW_KEY_ESC) | !glfwGetWindowParam(GLFW_OPENED);
	}

	return 0;
}
