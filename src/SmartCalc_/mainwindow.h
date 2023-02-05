#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    double x;
private slots:
    void digits_numbers();

    void on_pushButton_dot_clicked();
    void on_pushButton_AC_clicked();
    void on_pushButton_enter_clicked();
    void on_pushButton_build_graph_clicked();
    void on_result_show_returnPressed();
};
#endif // MAINWINDOW_H
