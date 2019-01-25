#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#ifdef Q_OS_WIN
#include  "windows.h"
#endif
#include <QString>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void setDisplayOrientation();

    void setButtonsDisabled(bool disable);
    void setTheme(bool enable);

private slots:
    void on_UpButton_clicked();

    void on_DownButton_clicked();

    void on_LeftButton_clicked();

    void on_RightButton_clicked();

    void on_PlusButton_clicked();

    void on_MinusButton_clicked();

private:
    Ui::Widget *ui;
#ifdef Q_OS_WIN
    DEVMODE dm;
#endif
};

#endif // WIDGET_H
