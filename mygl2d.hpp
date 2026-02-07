#ifndef MYGL2D_H
#define MYGL2D_H

#include "glfw.h"

class MyGL2D {
public:
	MyGL2D();
	~MyGL2D();
	void clearScreen(void);
	void setColor(int r, int g, int b);
	void drawPoint(int x, int y);
	void drawLine(int x1, int y1, int x2, int y2);
	void drawRect(int x, int y, int w, int h);
	void fillRect(int x, int y, int w, int h);
	void drawCircle(int cx, int cy, int r);
	void fillCircle(int cx, int cy, int r);
	void drawOval(int cx, int cy, int rx, int ry);
	void fillOval(int cx, int cy, int rx, int ry);
	void drawPolygon(const int* points, int num_points);
	void fillPolygon(const int* points, int num_points);
};



#endif /* MYGL2D_H */

