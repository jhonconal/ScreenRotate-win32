#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ZeroMemory(&dm,sizeof(dm));
    dm.dmSize=sizeof(dm);
    setButtonsDisabled(false);//关闭+/-按钮与否
    setTheme(false);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setDisplayOrientation()
{
#if 1
    if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
    {
        // swap height and width
        DWORD dwTemp = dm.dmPelsHeight;
        dm.dmPelsHeight= dm.dmPelsWidth;
        dm.dmPelsWidth = dwTemp;

        // determine new orientaion
        switch (dm.dmDisplayOrientation)
        {
        case DMDO_DEFAULT:
            dm.dmDisplayOrientation = DMDO_270;
            qDebug()<<"###"<<DMDO_DEFAULT;
            break;
        case DMDO_270:
            dm.dmDisplayOrientation = DMDO_180;
            qDebug()<<"###"<<DMDO_270;
            break;
        case DMDO_180:
            dm.dmDisplayOrientation = DMDO_90;
            qDebug()<<"###"<<DMDO_180;
            break;
        case DMDO_90:
            dm.dmDisplayOrientation = DMDO_DEFAULT;
            qDebug()<<"###"<<DMDO_90;
            break;
        default:
            // unknown orientation value
            // add exception handling here
            break;
        }
        qDebug()<<"dm.dmDisplayOrientation: "<<dm.dmDisplayOrientation;
        long lRet = ChangeDisplaySettings(&dm, 0);
        if (DISP_CHANGE_SUCCESSFUL != lRet)
        {
            // add exception handling here
        }
    }
#endif
}

void Widget::setButtonsDisabled(bool disable)
{
    if(disable)
    {
        ui->DownButton->setDisabled(true);
        ui->UpButton->setDisabled(true);
        ui->LeftButton->setDisabled(true);
        ui->RightButton->setDisabled(true);

        ui->MinusButton->setEnabled(true);
        ui->label->setEnabled(true);
        ui->PlusButton->setEnabled(true);
    }
    else
    {
        ui->DownButton->setEnabled(true);
        ui->UpButton->setEnabled(true);
        ui->LeftButton->setEnabled(true);
        ui->RightButton->setEnabled(true);

        ui->MinusButton->setDisabled(true);
        ui->label->setDisabled(true);
        ui->PlusButton->setDisabled(true);
    }
}

void Widget::setTheme(bool enable)
{
    if(enable)
    {
        ui->UpButton->setStyleSheet("border-image: url(:/images/up.png);");
        ui->DownButton->setStyleSheet("border-image: url(:/images/down.png);");
        ui->LeftButton->setStyleSheet("border-image: url(:/images/left.png);");
        ui->RightButton->setStyleSheet("border-image: url(:/images/right.png);");
        ui->PlusButton->setStyleSheet("border-image: url(:/images/rotate_right.png);");
        ui->MinusButton->setStyleSheet("border-image: url(:/images/rotate_left.png);");
    }
    else
    {
        ui->UpButton->setStyleSheet("");
        ui->DownButton->setStyleSheet("");
        ui->LeftButton->setStyleSheet("");
        ui->RightButton->setStyleSheet("");
        ui->PlusButton->setStyleSheet("");
        ui->MinusButton->setStyleSheet("");
    }
}

void Widget::on_UpButton_clicked()
{
    setButtonsDisabled(false);
    ui->DownButton->setDisabled(true);
#ifdef Q_OS_WIN
    if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
    {
        // swap height and width
        DWORD dwTemp = dm.dmPelsHeight;
        dm.dmPelsHeight= dm.dmPelsWidth;
        dm.dmPelsWidth = dwTemp;

        // determine new orientaion
        switch (dm.dmDisplayOrientation)
        {
        case DMDO_DEFAULT:
        case DMDO_270:
        case DMDO_180:
        case DMDO_90:
            dm.dmDisplayOrientation = DMDO_DEFAULT;
            qDebug()<<"UP###"<<DMDO_DEFAULT;
            break;
        default:
            // unknown orientation value
            // add exception handling here
            break;
        }
        qDebug()<<"dm.dmDisplayOrientation: "<<dm.dmDisplayOrientation;
        long lRet = ChangeDisplaySettings(&dm, 0);
        if (DISP_CHANGE_SUCCESSFUL != lRet)
        {
            // add exception handling here
            return;
        }
    }
#else
    system("xrandr -o normal");
#endif
}

void Widget::on_DownButton_clicked()
{
    setButtonsDisabled(false);
    ui->UpButton->setDisabled(true);
#ifdef Q_OS_WIN
    if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
    {
        // swap height and width
        DWORD dwTemp = dm.dmPelsHeight;
        dm.dmPelsHeight= dm.dmPelsWidth;
        dm.dmPelsWidth = dwTemp;

        // determine new orientaion
        switch (dm.dmDisplayOrientation)
        {
        case DMDO_DEFAULT:
        case DMDO_270:
        case DMDO_180:
        case DMDO_90:
            dm.dmDisplayOrientation = DMDO_180;
            qDebug()<<"DOWN###"<<DMDO_180;
            break;
        default:
            // unknown orientation value
            // add exception handling here
            break;
        }
        qDebug()<<"dm.dmDisplayOrientation: "<<dm.dmDisplayOrientation;
        long lRet = ChangeDisplaySettings(&dm, 0);
        if (DISP_CHANGE_SUCCESSFUL != lRet)
        {
            // add exception handling here
            return;
        }
    }
#else
    system("xrandr -o inverted");
#endif
}

void Widget::on_LeftButton_clicked()
{
    setButtonsDisabled(false);
    ui->RightButton->setDisabled(true);
#ifdef Q_OS_WIN
    if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
    {
        // swap height and width
        DWORD dwTemp = dm.dmPelsHeight;
        dm.dmPelsHeight= dm.dmPelsWidth;
        dm.dmPelsWidth = dwTemp;

        // determine new orientaion
        switch (dm.dmDisplayOrientation)
        {
        case DMDO_DEFAULT:
        case DMDO_270:
        case DMDO_180:
        case DMDO_90:
            dm.dmDisplayOrientation = DMDO_270;
            qDebug()<<"LEFT###"<<DMDO_270;
            break;
        default:
            // unknown orientation value
            // add exception handling here
            break;
        }
        qDebug()<<"dm.dmDisplayOrientation: "<<dm.dmDisplayOrientation;
        long lRet = ChangeDisplaySettings(&dm, 0);
        if (DISP_CHANGE_SUCCESSFUL != lRet)
        {
            // add exception handling here
            return;
        }
    }
#else
    system("xrandr -o left");
#endif
}

void Widget::on_RightButton_clicked()
{
    setButtonsDisabled(false);
    ui->LeftButton->setDisabled(true);
#ifdef Q_OS_WIN
    if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
    {
        // swap height and width
        DWORD dwTemp = dm.dmPelsHeight;
        dm.dmPelsHeight= dm.dmPelsWidth;
        dm.dmPelsWidth = dwTemp;

        // determine new orientaion
        switch (dm.dmDisplayOrientation)
        {
        case DMDO_DEFAULT:
        case DMDO_270:
        case DMDO_180:
        case DMDO_90:
            dm.dmDisplayOrientation = DMDO_90;
            qDebug()<<"RIGHT###"<<DMDO_90;
            break;
        default:
            // unknown orientation value
            // add exception handling here
            break;
        }
        qDebug()<<"dm.dmDisplayOrientation: "<<dm.dmDisplayOrientation;
        long lRet = ChangeDisplaySettings(&dm, 0);
        if (DISP_CHANGE_SUCCESSFUL != lRet)
        {
            // add exception handling here
            return;
        }
    }
#else
    system("xrandr -o right");
#endif
}

void Widget::on_MinusButton_clicked()
{
    if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
    {
        // swap height and width
        DWORD dwTemp = dm.dmPelsHeight;
        dm.dmPelsHeight= dm.dmPelsWidth;
        dm.dmPelsWidth = dwTemp;

        // determine new orientaion
        switch (dm.dmDisplayOrientation)
        {
        case DMDO_DEFAULT:
            dm.dmDisplayOrientation = DMDO_270;
            qDebug()<<"###"<<DMDO_DEFAULT;
            ui->label->setText("270");
            break;
        case DMDO_270:
            dm.dmDisplayOrientation = DMDO_180;
            qDebug()<<"###"<<DMDO_180;
            ui->label->setText("180");
            break;
        case DMDO_180:
            dm.dmDisplayOrientation = DMDO_90;
            qDebug()<<"###"<<DMDO_90;
            ui->label->setText("90");
            break;
        case DMDO_90:
            dm.dmDisplayOrientation = DMDO_DEFAULT;
            qDebug()<<"###"<<DMDO_DEFAULT;
            ui->label->setText("0");
            break;
        default:
            // unknown orientation value
            // add exception handling here
            break;
        }
        qDebug()<<"dm.dmDisplayOrientation: "<<dm.dmDisplayOrientation;
        long lRet = ChangeDisplaySettings(&dm, 0);
        if (DISP_CHANGE_SUCCESSFUL != lRet)
        {
            // add exception handling here
            return;
        }
    }
}

void Widget::on_PlusButton_clicked()
{
    if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
    {
        // swap height and width
        DWORD dwTemp = dm.dmPelsHeight;
        dm.dmPelsHeight= dm.dmPelsWidth;
        dm.dmPelsWidth = dwTemp;

        // determine new orientaion
        switch (dm.dmDisplayOrientation)
        {
        case DMDO_DEFAULT:
            dm.dmDisplayOrientation = DMDO_90;
            qDebug()<<"###"<<DMDO_90;
            ui->label->setText("90");
            break;
        case DMDO_270:
            dm.dmDisplayOrientation = DMDO_DEFAULT;
            qDebug()<<"###"<<DMDO_DEFAULT;
            ui->label->setText("0");
            break;
        case DMDO_180:
            dm.dmDisplayOrientation = DMDO_270;
            qDebug()<<"###"<<DMDO_270;
            ui->label->setText("270");
            break;
        case DMDO_90:
            dm.dmDisplayOrientation = DMDO_180;
            qDebug()<<"###"<<DMDO_180;
            ui->label->setText("180");
            break;
        default:
            // unknown orientation value
            // add exception handling here
            break;
        }
        qDebug()<<"dm.dmDisplayOrientation: "<<dm.dmDisplayOrientation;
        long lRet = ChangeDisplaySettings(&dm, 0);
        if (DISP_CHANGE_SUCCESSFUL != lRet)
        {
            // add exception handling here
        }
    }
}
