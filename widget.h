#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    //void on_btnBytes_clicked();

    //void on_btnBits_clicked();

    //void on_btnType_clicked();

    void on_btnBytes_pressed();

    void on_btnBits_pressed();

    void on_btnType_pressed();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
