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
    connect(ui->pushButton_AC,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_enter,SIGNAL(clicked()),this,SLOT(digits_numbers()));
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
//    if(!(ui->result_show->text().contains('.')))
//    ui->result_show->setText(ui->result_show->text() +  '.');

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
    double x;
    x = 0;
//    int check = main((char*)ui->result_show->text().toStdString().c_str(), valux, &result);
//    if (!check) {
    result = smart_calc(x, (char*)ui->result_show->text().toStdString().c_str(), result);
    output = QString::number(result, 'g', 8);
    ui->result_show->setText(output);
//    } else {
//        ui->result_show->setText("incorrect data");
//    }

}


void MainWindow::on_pushButton_build_graph_clicked()
{
    if(!(ui->result_show->text().contains('.')))
    ui->result_show->setText(ui->result_show->text() +  '.');
}


void MainWindow::on_result_show_returnPressed()
{

}

