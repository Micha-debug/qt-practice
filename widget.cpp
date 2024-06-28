#include "widget.h"
#include "ui_widget.h"
#include <QtGlobal>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
int int_result;
double d_number;
int i_number;
long long l_number;
bool is_d = false, is_i = false, is_l = false;
QString str_result;
// void Widget::on_btnBytes_clicked()
// {

// }


// void Widget::on_btnBits_clicked()
// {

// }


void Widget::on_btnType_pressed()
{
    // number = ui->txtNumber->text().toDouble();
    // if (number >= std::numeric_limits<qint8>::min() && number <= std::numeric_limits<qint8>::max()) {
    //     str_result = "qint8";
    // } else if (number >= std::numeric_limits<qlonglong>::min() && number <= std::numeric_limits<qlonglong>::max()) {
    //     str_result = "qlonglong";
    // } else {
    //     str_result = "qreal";
    // }
    d_number = ui->txtNumber->text().toDouble(&is_d);
    i_number = ui->txtNumber->text().toInt(&is_i);
    l_number = ui->txtNumber->text().toLongLong(&is_l);
    if (is_d) str_result = "qreal";
    if (is_l) str_result = "qlonglong";
    if (is_i) str_result = "qint8";
    //ui->txtResult->setText(str_result);
    ui->txtType->setText(str_result);
}


// void Widget::on_btnBytes_pressed()
// {

// }


void Widget::on_btnBits_pressed()
{
    // number = ui->txtNumber->text().toDouble();
    // int_result = sizeof(number)*8;
    d_number = ui->txtNumber->text().toDouble(&is_d);
    i_number = ui->txtNumber->text().toInt(&is_i);
    l_number = ui->txtNumber->text().toLongLong(&is_l);
    if (is_d) int_result = 16*8;
    if (is_l) int_result = 8*8;
    if (is_i) int_result = 4*8;
    ui->txtBits->setText(QString::number(int_result));
}


void Widget::on_btnBytes_pressed()
{
    // number = ui->txtNumber->text().toDouble(&is_d);
    // int_result = sizeof(number);
    d_number = ui->txtNumber->text().toDouble(&is_d);
    i_number = ui->txtNumber->text().toInt(&is_i);
    l_number = ui->txtNumber->text().toLongLong(&is_l);
    if (is_d) int_result = 16;
    if (is_l) int_result = 8;
    if (is_i) int_result = 4;
    ui->txtBytes->setText(QString::number(int_result));
}

