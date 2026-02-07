#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "mygl2d.hpp"

class Turtle {
private:
	double x, y, h;
	bool isPenDown = true;
	double d2r(double d);
public:
	Turtle(double x,double y,double h = -90);
	~Turtle();
	void move(double d);
	void turn(double a);
	void jump(double i, double j);
	void face(double a);
	void setPenColor(int r, int g, int b);
};

#endif
