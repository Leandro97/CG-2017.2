#ifndef GLWIDGET_H
#define GLWIDGET_H

#include<QGLWidget>
#include <QTimer>

class GLWidget : public QGLWidget{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void mousePressEvent(QMouseEvent *event);

private:
    QTimer timer;
};

    void emptyLines();
    void drawField(void (*reta)(int,int,int,int));
    void setBres(int value);
    void setTam(int value);
    float setColors(float r, float g, float b);
    float getR();
    float getG();
    float getB() ;

#endif // GLWIDGET_H
