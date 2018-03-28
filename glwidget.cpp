#include "glwidget.h"
#include<GL/glut.h>
#include<bresenham.h>
#include<equacoes.h>
#include <vector>
#include <utility>
#include<QMouseEvent>
//#include <tuple>

int bres, xp, yp, xu, yu, tam = 1, c = 0;
float color[3] = {1,1,1};
bool firstClick = true;
bool newDraw = false;
std::vector<std::tuple<int,int,int,int>> lines;

GLWidget::GLWidget(QWidget *parent):
    QGLWidget(parent) {
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(5);
}

void setBres(int value) {
    bres = value;
}

void setTam(int value) {
    tam = value;
}

float setColors(float r, float g, float b) {
    color[0] = r;
    color[1] = g;
    color[2] = b;
    return 1;
}

float getR() {
    return color[0];
}

float getG() {
    return color[1];
}

float getB() {
    return color[2];
}

void drawField(void (*reta)(int,int,int,int), void (*circ)(int,int,int), void (*semiCirc)(int,int,int,int)) {
        //Whole field
        reta(60,280,480,280);
        reta(480,80,480,280);
        reta(60,80,480,80);
        reta(60,80,60,280);

        //Left Area
        semiCirc(100, 180, 90, 1);
        reta(60,270,110,270);
        reta(60,210,130,210);
        reta(60,150,130,150);
        reta(130,210,130,150);
        reta(60,90,110,90);
        circ(130, 180, 30);

        //Middle line
        reta(270,80,270,280);
        circ(270, 180, 30);

        //Right Area
        semiCirc(440, 180, 90, -1);
        reta(440,270,480,270);
        reta(410,210,480,210);
        reta(410,150,480,150);
        reta(410,210,410,150);
        reta(440,90,480,90);
        circ(410, 180, 30);

        for(int i =0; i < lines.size(); i++) {
            reta(std::get<0>(lines[i]), std::get<1>(lines[i]), std::get<2>(lines[i]), std::get<3>(lines[i]));
        }
        glFlush();

}

void emptyLines() {
    lines.clear();
}

void GLWidget::initializeGL() {
glClearColor(0,0,0,1);
gluOrtho2D(0, 640, 0, 480);
glViewport(0, 0, 640, 480);
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(tam);
    glColor3f(color[0], color[1], color[2]);

    if(bres == 0) {
        drawField(eqReta, circulo, semiCirculo);
    } else {
        drawField(bresenhamReta, bresenhamCirculo, bresenhamSemiCirculo);
    }

}

void GLWidget::mousePressEvent(QMouseEvent *event) {
    if(firstClick) {
        xp = event->x();
        yp = 360 - event->y();
        firstClick = false;
    } else {
        xu = event->x();
        yu = 360 - event->y();

        newDraw = true;
        firstClick = true;
    }

    if(newDraw) {
        lines.push_back(std::tuple<int, int, int, int>(xp,yp,xu,yu));
        newDraw = false;
    }
}
