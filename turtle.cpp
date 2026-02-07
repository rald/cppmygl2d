#include "turtle.hpp"
#include <cmath>

Turtle::Turtle(double x, double y, double h) {
	this->x=x;
	this->y=y;
	this->h=h;
}

Turtle::~Turtle() {}

double Turtle::d2r(double d) {
	return d * M_PI / 180.0d;
}

void Turtle::move(double d) {
	double nx = d * cos(d2r(h)) + x;
	double ny = d * sin(d2r(h)) + y;
	if(isPenDown) MyGL2D::drawLine(x, y, nx, ny);
	x=nx;
	y=ny;
}

void Turtle::turn(double a) {
	h+=a;
}

void Turtle::jump(double x,double y) {
	this->x=x;
	this->y=y;
}

void Turtle::face(double a) {
	h=a;
}

void Turtle::setPenColor(int r,int g,int b) {
	MyGL2D::setColor(r,g,b);
}
