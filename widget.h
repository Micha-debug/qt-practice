#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE
// class MovingObjectsWidget : public QWidget {
//     Q_OBJECT
// public:
//     MovingObjectsWidget(QWidget *parent = nullptr);
// protected:
//     void paintEvent(QPaintEvent *event) override;
// private slots:
//     void on_btnLeft_clicked();
// private:
//     QPixmap ballPixmap;
//     QPixmap glassPixmap;
//     QPoint ballPos;
//     QPoint glassPos;
// };

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_btnLeft_clicked();

private:
    Ui::Widget *ui;
    //MovingObjectsWidget *movingObjectsWidget;
    QPixmap ballPixmap;
    QPixmap glassPixmap;
    QPoint ballPos;
    QPoint glassPos;
};
#endif // WIDGET_H
