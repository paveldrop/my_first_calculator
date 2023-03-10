#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_dot,SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_AC,SIGNAL(clicked()),this,SLOT(digits_numbers()));
//    connect(ui->pushButton_enter,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_asin,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_acos,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_atan,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_bracketClose,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_bracketOpen,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_pow,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->result_show,SIGNAL(returnPressed()),this,SLOT(on_pushButton_enter_clicked()));
    connect(ui->spinBoxXmin,SIGNAL(valueChanged(int)),this,SLOT(on_pushButton_build_graph_clicked()));
    connect(ui->spinBoxXmin_2,SIGNAL(valueChanged(int)),this,SLOT(on_pushButton_build_graph_clicked()));
    connect(ui->spinBoxXmax,SIGNAL(valueChanged(int)),this,SLOT(on_pushButton_build_graph_clicked()));
    connect(ui->spinBoxYmax,SIGNAL(valueChanged(int)),this,SLOT(on_pushButton_build_graph_clicked()));

 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers() {

    QPushButton *button = (QPushButton *)sender();
    ui->result_show->setText(ui->result_show->text() + button->text());
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->x_data->text().contains('.')))
    ui->x_data->setText(ui->x_data->text() +  '.');
}


void MainWindow::on_pushButton_AC_clicked()
{
    ui->result_show->setText("");
    ui->x_data->setText("");
}


void MainWindow::on_pushButton_enter_clicked()
{
    QString output;
    double result = 0;
    double x_calc;
    QString x_num = ui->x_data->text();
    x_calc = x_num.toDouble();
//    int check = main((char*)ui->result_show->text().toStdString().c_str(), valux, &result);
//    if (!check) {
    result = smart_calc(x_calc, (char*)ui->result_show->text().toStdString().c_str(), &result);
    output = QString::number(result, 'g', 8);
    ui->result_show->setText(output);
//    } else {
//        ui->result_show->setText("incorrect data");
//    }

}


void MainWindow::on_pushButton_build_graph_clicked()
{
    ui->graph->clearGraphs();

//    QString x_num = ui->x_data->text();
//    x_calc = x_num.toDouble();

    double yBegin, yEnd;

    h = 0.1;

    xBegin = ui->spinBoxXmin->value();
    xEnd = ui->spinBoxXmax->value();
    yBegin = ui->spinBoxXmin_2->value();
    yEnd =ui->spinBoxYmax->value();

    ui->graph->xAxis->setRange(xBegin, xEnd);
    ui->graph->yAxis->setRange(yBegin, yEnd);

    countN = (xEnd - xBegin)/h + 2;

    for(X = xBegin; X <= xEnd; X += h) {
        smart_calc(X, (char*)ui->result_show->text().toStdString().c_str(), &Y);
        x.push_back(X);
        y.push_back(Y);
    }
    ui->graph->addGraph();
    ui->graph->graph(0)->addData(x,y);
    ui->graph->replot();
    x.clear();
    y.clear();
}


void MainWindow::on_result_show_returnPressed()
{

}


void MainWindow::on_x_data_editingFinished()
{


}


void MainWindow::on_spinBoxXmin_valueChanged(int arg1)
{
//    on_pushButton_AC_clicked();
}


void MainWindow::on_About_clicked()
{
    about = new about_wind(this);
    about->show();
}

