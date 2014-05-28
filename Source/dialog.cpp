#include <QString>


#include "dialog.h"
#include "ui_dialog.h"

dialog::dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
}

dialog::~dialog()
{
    delete ui;
}

void dialog::Warning(string title)
{
    ui-> warning -> setText(QString::fromStdString(title));
}

void dialog::Warning(string title, double value)
{
    ui-> warning -> setText(QString::fromStdString(title) + QString::number(value));
}

void dialog::Warning(string title, double value, string title1, double value1)
{
    ui-> warning -> setText(QString::fromStdString(title) + QString::number(value)+QString::fromStdString(title1) + QString::number(value1));
}

void dialog::Warning(string title, double value, string title1, double value1,string title2, double value2)
{
    ui-> warning -> setText(QString::fromStdString(title) + QString::number(value)+QString::fromStdString(title1) + QString::number(value1) + QString::fromStdString(title2) + QString::number(value2));
}

void dialog::Warning(string title, double value, string title1, double value1,string title2, double value2, string title3, double value3)
{
    ui-> warning -> setText(QString::fromStdString(title) + QString::number(value)+QString::fromStdString(title1) + QString::number(value1) + QString::fromStdString(title2) + QString::number(value2) + QString::fromStdString(title3) + QString::number(value3));
}

void dialog::Warning(string title, string title1, double value1, string title2, double value2, string title3, double value3, string title4, double value4, string title5, double value5)
{
    ui-> warning -> setText(QString::fromStdString(title) + QString::fromStdString(title1) + QString::number(value1) + QString::fromStdString(title2) + QString::number(value2) + QString::fromStdString(title3) + QString::number(value3)  + QString::fromStdString(title4) + QString::number(value4) + QString::fromStdString(title5) + QString::number(value5));
}
