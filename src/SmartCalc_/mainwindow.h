#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "about_wind.h"

extern "C" {
    #include "../smartcalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double xBegin, xEnd, h, X, Y, value_x;
    int countN;

    QVector<double> x, y;

    about_wind *about;


private slots:
    void digits_numbers();

    void on_pushButton_dot_clicked();
    void on_pushButton_AC_clicked();
    void on_pushButton_enter_clicked();
    void on_pushButton_build_graph_clicked();
    void on_result_show_returnPressed();
    void on_x_data_editingFinished();
    void on_spinBoxXmin_valueChanged(int arg1);
    void on_About_clicked();
};
#endif // MAINWINDOW_H
