#ifndef ABOUT_WIND_H
#define ABOUT_WIND_H

#include <QMainWindow>
#include <QMovie>

namespace Ui {
class about_wind;
}

class about_wind : public QMainWindow
{
    Q_OBJECT

public:
    explicit about_wind(QWidget *parent = nullptr);
    ~about_wind();

private:
    Ui::about_wind *ui;

    QMovie mo;
    double m;
};

#endif // ABOUT_WIND_H
