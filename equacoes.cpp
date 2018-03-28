#include "equacoes.h"
#include <algorithm>
#include <math.h>
#include <GL/glut.h>

using namespace std;
const float DEG2RAD = 3.14159/180;

/*
Código utilizado para as funções da reta:
https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm#Line_equation
*/

void eqReta(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    glBegin(GL_POINTS);
    if (dx >= dy)
        retaX(x0, y0, x1, y1);
    else
        retaY(x0, y0, x1, y1);
    glEnd();
}

void retaX(int x0, int y0, int x1, int y1) {
    if (!(x0 < x1)) {
        swap(x0, x1);
        swap(y0, y1);
    }
    double a = (double)(y1-y0)/(x1-x0);
    int y;
    for(int x=x0; x<=x1; x++) {
        y = (y0 + a*(x-x0));
        glVertex2i(x, y);
    }
}

void retaY(int x0, int y0, int x1, int y1) {
    if (!(y0 < y1)) {
        swap(x0, x1);
        swap(y0, y1);
    }
    double a = (double)(x1-x0)/(y1-y0);
    int x;
    for(int y=y0; y<=y1; y++) {
        x = (x0 + a*(y-y0));
        glVertex2i(x, y);
    }
}

/*
Código utilizado para as funções da circunferência:
https://www.opengl.org/discussion_boards/showthread.php/167955-drawing-a-smooth-circle
*/

void circulo(int xc, int yc, int r) {
   glBegin(GL_POINTS);

   for (int i=0; i < 360; i++) {
      float degInRad = i*DEG2RAD;
      glVertex2f(xc + cos(degInRad)*r, yc + sin(degInRad)*r);
   }

   glEnd();
}

void semiCirculo(int xc, int yc, int r, int dir) {
   glBegin(GL_POINTS);

   if(dir == 1) {
       for (int i = 0; i < 90; i++) {
          float degInRad = i*DEG2RAD;
          glVertex2f(xc + cos(degInRad)*r, yc + sin(degInRad)*r);
       }

       for (int i = 270; i < 360; i++) {
          float degInRad = i*DEG2RAD;
          glVertex2f(xc + cos(degInRad)*r, yc + sin(degInRad)*r);
       }
   } else {
       for (int i = 90; i < 270; i++) {
          float degInRad = i*DEG2RAD;
          glVertex2f(xc + cos(degInRad)*r, yc + sin(degInRad)*r);
       }
   }

   glEnd();
}
