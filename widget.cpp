#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPropertyAnimation>
#include <QVariantAnimation>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPainter>
#include <QRandomGenerator>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QPixmap ballPixmap("/Users/michael/Desktop/ball.png");
    QPixmap glassPixmap("/Users/michael/Desktop/naperstok_2.png");
    // QPoint ballPos;
    // QPoint glassPos;
    // connect(btnLeft, &QPushButton::clicked, this, &Widget::on_btnLeft_clicked);
    // movingObjectsWidget = new MovingObjectsWidget(this); // Создание экземпляра MovingObjectsWidget
    // movingObjectsWidget->setGeometry(0, 0, this->width(), this->height()); // Размещение в главном окне
    ui->setupUi(this);
    //QPixmap pix("/Users/michael/Desktop/naperstok_2.png");
    int w = ui->glassLabel->width();
    int h = ui->glassLabel->height();
    int w2 = ui->glassLabel_2->width();
    int h2 = ui->glassLabel_2->height();
    ui->glassLabel->setPixmap(glassPixmap.scaled(w,h, Qt::KeepAspectRatio));
    ui->glassLabel_2->setPixmap(glassPixmap.scaled(w2,h2, Qt::KeepAspectRatio));
    ui->ballLabel->setPixmap(ballPixmap);
    ui->ballLabel->setVisible(false); // Скрываем шарик при инициализации
    // ui->glassLabel->setPixmap(pix.scaled(171,211, Qt::KeepAspectRatio));
    // ui->ballLabel->setPixmap(pix.scaled(171,211, Qt::KeepAspectRatio));
}

Widget::~Widget()
{
    delete ui;
}

// MovingObjectsWidget::MovingObjectsWidget(QWidget *parent) : QWidget(parent) {


// };

void Widget::on_btnLeft_clicked()
{
    int randomNumber = QRandomGenerator::global()->bounded(100); // Генерирует число от 0 до 99
    QPropertyAnimation *glassAnimation = new QPropertyAnimation(ui->glassLabel, "geometry");
    QPropertyAnimation *ballAnimation = new QPropertyAnimation(ui->ballLabel, "geometry");

    // Устанавливаем параметры анимации
    // glassAnimation->setDuration(1000); // продолжительность в миллисекундах
    // glassAnimation->setStartValue(QPoint(0, 0)); // начальная позиция
    // glassAnimation->setEndValue(QPoint(0, -100)); // конечная позиция

    // ballAnimation->setDuration(1000);
    // ballAnimation->setStartValue(QPoint(0, 0));
    // ballAnimation->setEndValue(QPoint(50, 50));
    QLabel *glassLabel = new QLabel(this);
    QPixmap glassPixmap("/Users/michael/Desktop/naperstok_2.png");
    glassLabel->setPixmap(glassPixmap);
    glassLabel->setGeometry(QRect(160, 100, glassPixmap.width(), glassPixmap.height()));

    glassAnimation = new QPropertyAnimation(ui->glassLabel, "geometry");
    glassAnimation->setDuration(2000);
    glassAnimation->setStartValue(QRect(160, 40, glassPixmap.width(), glassPixmap.height()));
    glassAnimation->setEndValue(QRect(160, -100, glassPixmap.width(), glassPixmap.height()));




    // Соединяем сигнал нажатия кнопки со слотом запуска анимации
    //connect(btnLeft, &QPushButton::clicked, [=]() {

   //if(randomNumber % 2 == 0){
        QLabel *ballLabel = new QLabel(this);
        QPixmap ballPixmap("/Users/michael/Desktop/ball.png");
        ballLabel->setPixmap(ballPixmap);
        ballLabel->setGeometry(QRect(200, 300, ballPixmap.width(), ballPixmap.height()));
        //ballLabel->show();

        ballAnimation = new QPropertyAnimation(ui->ballLabel, "geometry");
        ballAnimation->setDuration(2000);
        ballAnimation->setStartValue(QRect(200, 300, ballPixmap.width(), ballPixmap.height()));
        ballAnimation->setEndValue(QRect(250, 350, ballPixmap.width(), ballPixmap.height()));
        ballLabel->setVisible(true);
        glassAnimation->start();
        ballAnimation->start();
   //}
    // else{
    //     glassAnimation->start();
    // }
        //});
    // QPixmap pix("/Users/michael/Desktop/naperstok_2.png");
    // QGraphicsScene *scene = new QGraphicsScene(this);
    // QGraphicsPixmapItem *pixmapItem = scene->addPixmap(pix);

    // // Создание QGraphicsView для отображения сцены
    // QGraphicsView *view = new QGraphicsView(scene, this);
    // view->setSceneRect(pix.rect());

    // // Настройка анимации вращения
    // QVariantAnimation *rotationAnimation = new QVariantAnimation(this);
    // rotationAnimation->setDuration(2000);
    // rotationAnimation->setStartValue(0);
    // rotationAnimation->setEndValue(-40);

    // connect(rotationAnimation, &QVariantAnimation::valueChanged, this, [=](const QVariant &value){
    //     // Вращение pixmapItem
    //     QTransform transform;
    //     transform.translate(pixmapItem->boundingRect().center().x(), pixmapItem->boundingRect().center().y());
    //     transform.rotate(value.toReal());
    //     transform.translate(-pixmapItem->boundingRect().center().x(), -pixmapItem->boundingRect().center().y());
    //     pixmapItem->setTransform(transform);
    // });

    // // Запуск анимации
    // rotationAnimation->start();

    // QVariantAnimation *animation = new QVariantAnimation;
    // animation->setDuration(1000); // продолжительность в миллисекундах
    // animation->setStartValue(0.0f);
    // animation->setEndValue(-40.0f); // новое положение
    // QPixmap pix("/Users/michael/Desktop/naperstok_2.png");
    // QTransform t;
    // QPixmap rotatedPixmap = pix.transformed(t, Qt::SmoothTransformation);
    // connect(animation, &QVariantAnimation::valueChanged, [=](const QVariant &value){
    //     qDebug()<<value;
    //     QTransform t;
    //     t.rotate(value.toReal());
    //     ui->glassLabel->setPixmap(pix.transformed(t, Qt::SmoothTransformation));
    //     //QPixmap rotatedPixmap = pix.transformed(t, Qt::SmoothTransformation);
    //     });
    // // Установка размера QLabel достаточно большим, чтобы вместить вращаемый QPixmap
    // int maxDimension = qMax(rotatedPixmap.width(), rotatedPixmap.height());
    // ui->glassLabel->setMinimumSize(maxDimension, maxDimension);

    // // Центрирование QPixmap в QLabel
    // QPoint center((ui->glassLabel->width() - rotatedPixmap.width()) / 2, (ui->glassLabel->height() - rotatedPixmap.height()) / 2);
    // ui->glassLabel->setPixmap(rotatedPixmap);
    // ui->glassLabel->move(center);
    // animation->start();

    // QLabel *ballLabel = new QLabel(this);
    // QPixmap ballPixmap("/Users/michael/Desktop/ball.png");
    // ballLabel->setPixmap(ballPixmap);
    // ballLabel->setGeometry(QRect(200, 300, ballPixmap.width(), ballPixmap.height()));
    // ballLabel->show();
}

