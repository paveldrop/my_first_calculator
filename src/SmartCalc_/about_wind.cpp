#include "about_wind.h"
#include "ui_about_wind.h"

about_wind::about_wind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::about_wind)
{
    ui->setupUi(this);


    QMovie *movie = new QMovie(":/imageformats/2_668897407815123243.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    movie->start();
}

about_wind::~about_wind()
{
    delete ui;
}
