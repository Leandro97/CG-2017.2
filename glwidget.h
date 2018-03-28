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
    void setR(float value);
    void setG(float value);
    void setB(float value) ;

#endif // GLWIDGET_H
