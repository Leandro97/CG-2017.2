#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_rBox_valueChanged(double arg1);

    void on_gBox_valueChanged(double arg1);

    void on_bBox_valueChanged(double arg1);

    void on_espessura_valueChanged(int value);

    void on_pushButton_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
