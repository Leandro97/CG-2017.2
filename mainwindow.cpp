#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<glwidget.h>
#include<bresenham.h>
#include<equacoes.h>

#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_radioButton_clicked() {
    setBres(0);
}

void MainWindow::on_radioButton_2_clicked() {
    setBres(1);
}

void MainWindow::on_rBox_valueChanged(double arg1) {
    setColors(arg1, getG(), getB());
}

void MainWindow::on_gBox_valueChanged(double arg1) {
    setColors(getR(), arg1, getB());
}

void MainWindow::on_bBox_valueChanged(double arg1) {
    setColors(getR(), getG(), arg1);
}

void MainWindow::on_espessura_valueChanged(int value) {
   setTam(value);
}

void MainWindow::on_pushButton_pressed() {
    emptyLines();
}
