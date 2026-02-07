#ifndef MYGL2D_H
#define MYGL2D_H

#include "glfw.h"

class MyGL2D {
public:
	MyGL2D();
	~MyGL2D();
	static void clearScreen(void);
	static void setColor(int r, int g, int b);
	static void drawPoint(int x, int y);
	static void drawLine(int x1, int y1, int x2, int y2);
	static void drawRect(int x, int y, int w, int h);
	static void fillRect(int x, int y, int w, int h);
	static void drawCircle(int cx, int cy, int r);
	static void fillCircle(int cx, int cy, int r);
	static void drawOval(int cx, int cy, int rx, int ry);
	static void fillOval(int cx, int cy, int rx, int ry);
	static void drawPolygon(const int* points, int num_points);
	static void fillPolygon(const int* points, int num_points);
};

#endif /* MYGL2D_H */

