#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTableWidget>
#include <QListWidget>
#include <QInputDialog>
#include <QString>
#include <QLocale>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBox->addItem(QIcon(":/new/prefix1/png-clipart-travel-tourism-travel-globe-world.png"), "Traveling");
    ui->lw->addItem("Qwerty");
    //ui->lw = new QListWidget(this);
    ui->lw->addItem("sds");


}

Widget::~Widget()
{
    delete ui;
}
class Tourist{
    QString name, date;
    qreal price;
};

void Widget::on_btnWrite_clicked()
{
    QFile file("/Users/michael/Desktop/QT/Practice2024/lab2TableWidget/Input.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "file is not open");
    }
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void Widget::on_btnRead_clicked()
{
    QFile file("/Users/michael/Desktop/QT/Practice2024/lab2TableWidget/Input.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "file is not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.flush();
    file.close();
}


void Widget::on_btnAdd_clicked()
{
    QString text = QInputDialog::getText(this, "Item", "Enter new Item");
    ui->lw->addItem(text);
    for (int j = 0; j < 3; j++){
        ui->tw->insertColumn(j);
    }
    for (int i = 0; i < 5; i++){
        ui->tw->insertRow(i);
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 3; j++){
            if(j==0){
                qreal price = QInputDialog::getDouble(this, "Price", "Enter new price");
                QString p = QString::number(price);
                QTableWidgetItem *item = new QTableWidgetItem(p);
                ui->tw->setItem(i, j, item);
            }
            else{
                text = QInputDialog::getText(this, "Item", "Enter new Item");
                QTableWidgetItem *item = new QTableWidgetItem(text);
                ui->tw->setItem(i, j, item);
            }
        }
    }
    ui->retranslateUi(this);
}


void Widget::on_btnDelete_clicked()
{
    int num = QInputDialog::getInt(this, "Row", "Enter row number");
    QListWidgetItem *item = ui->lw->takeItem(num);
    ui->lw->removeItemWidget(item);
    delete item;
}

