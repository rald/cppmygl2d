#include "mygl2d.hpp"
#include <cmath>

MyGL2D::MyGL2D() {}

MyGL2D::~MyGL2D() {}

void MyGL2D::clearScreen(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void MyGL2D::setColor(int r, int g, int b) {
	glColor3ub(r, g, b);
}

void MyGL2D::drawPoint(int x, int y) {
    glPointSize(1);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void MyGL2D::drawLine(int x1, int y1, int x2, int y2) {
  glBegin(GL_LINES);
  glVertex2i(x1, y1);
  glVertex2i(x2, y2);
  glEnd();
}

void MyGL2D::drawRect(int x, int y, int w, int h) {
  glBegin(GL_LINE_LOOP);
  glVertex2i(x, y);
  glVertex2i(x + w, y);
  glVertex2i(x + w, y + h);
  glVertex2i(x, y + h);
  glEnd();
}

void MyGL2D::fillRect(int x, int y, int w, int h) {
  glBegin(GL_QUADS);
  glVertex2i(x, y);
  glVertex2i(x + w, y);
  glVertex2i(x + w, y + h);
  glVertex2i(x, y + h);
  glEnd();
}

void MyGL2D::drawCircle(int cx, int cy, int r) {
  glBegin(GL_LINE_LOOP);
  int num_segs = 100;
  for (int i = 0; i < num_segs; ++i) {
    float theta = 2.0f * 3.1415926f * (float)(i) / (float)(num_segs);
    int x = (int)(round(cx + r * cos(theta)));
    int y = (int)(round(cy + r * sin(theta)));
    glVertex2i(x, y);
  }
  glEnd();
}

void MyGL2D::fillCircle(int cx, int cy, int r) {
  glBegin(GL_TRIANGLE_FAN);
  glVertex2i(cx, cy);  // Center of the circle
  int num_segs = 100;  // Number of segments for smoothness
  for (int i = 0; i <= num_segs; ++i) {
    float theta = 2.0f * 3.1415926f * (float)(i) / (float)(num_segs);
    int x = (int)(round(cx + r * cos(theta)));
    int y = (int)(round(cy + r * sin(theta)));
    glVertex2i(x, y);
  }
  glEnd();
}

void MyGL2D::drawOval(int cx, int cy, int rx, int ry) {
  glBegin(GL_LINE_LOOP);
  int num_segs = 100;
  for (int i = 0; i < num_segs; ++i) {
    float theta = 2.0f * 3.1415926f * (float)(i) / (float)(num_segs);
    int x = (int)(round(cx + rx * cos(theta)));
    int y = (int)(round(cy + ry * sin(theta)));
    glVertex2i(x, y);
  }
  glEnd();
}

void MyGL2D::fillOval(int cx, int cy, int rx, int ry) {
  glBegin(GL_TRIANGLE_FAN);
  glVertex2i(cx, cy);  // Center
  int num_segs = 100;
  for (int i = 0; i <= num_segs; ++i) {
    float theta = 2.0f * 3.1415926f * (float)(i) / (float)(num_segs);
    int x = (int)(round(cx + rx * cos(theta)));
    int y = (int)(round(cy + ry * sin(theta)));
    glVertex2i(x, y);
  }
  glEnd();
}

void MyGL2D::drawPolygon(const int* points, int num_points) {
  if (num_points < 3) return; // Need at least 3 points to draw polygon outline
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < num_points; ++i) {
    glVertex2i(points[2*i], points[2*i + 1]);
  }
  glEnd();
}

void MyGL2D::fillPolygon(const int* points, int num_points) {
  if (num_points < 3) return; // Need at least 3 points to fill polygon
  glBegin(GL_TRIANGLE_FAN);
  for (int i = 0; i < num_points; ++i) {
    glVertex2i(points[2*i], points[2*i + 1]);
  }
  glEnd();
}
