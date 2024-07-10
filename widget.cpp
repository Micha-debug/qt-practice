#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPropertyAnimation>
#include <QVariantAnimation>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPainter>
#include <QInputDialog>
#include <QRandomGenerator>
#include <QTimer>

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
    ui->ballLabel->hide(); // Скрываем шарик при инициализации
    ui->ballLabel_2->setPixmap(ballPixmap);
    ui->ballLabel_2->hide();
    resetTimer = new QTimer(this);
    resetTimer->setSingleShot(true);
    connect(resetTimer, &QTimer::timeout, this, &Widget::resetState);
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
    QPropertyAnimation *ballAnimation = new QPropertyAnimation(ui->glassLabel_2, "geometry");

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
    glassAnimation->setDuration(400);
    glassAnimation->setStartValue(QRect(160, 40, glassPixmap.width(), glassPixmap.height()));
    glassAnimation->setEndValue(QRect(160, -40, glassPixmap.width(), glassPixmap.height()));


    QLabel *ballLabel = ui->ballLabel;//new QLabel(this);
    QPixmap ballPixmap("/Users/michael/Desktop/ball.png");
    ballLabel->setPixmap(ballPixmap);
    ballLabel->setGeometry(QRect(180, 310, ballPixmap.width(), ballPixmap.height()));
    ballAnimation = new QPropertyAnimation(ui->ballLabel, "geometry");
    ballAnimation->setDuration(400);
    ballAnimation->setStartValue(QRect(180, 310, ballPixmap.width(), ballPixmap.height()));
    ballAnimation->setEndValue(QRect(230, 360, ballPixmap.width(), ballPixmap.height()));


    // Соединяем сигнал нажатия кнопки со слотом запуска анимации
    //connect(btnLeft, &QPushButton::clicked, [=]() {
        glassAnimation->start();
    if (randomNumber % 2 == 0){
        ballLabel->show();
        ballAnimation->start();
        connect(glassAnimation, &QPropertyAnimation::finished, this, [this]() {
            resetTimer->start(2000); // 2 seconds
        });
        score++;
    }
    else{
        score = 0;
        ui->lastLabel->setText(QString("Last Score: %1").arg(score));
    }
    connect(glassAnimation, &QPropertyAnimation::finished, this, [this]() {
        resetTimer->start(2000); // 2 seconds
    });
    countLeft++;
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


void Widget::on_btnRight_clicked()
{
    int randomNumber = QRandomGenerator::global()->bounded(100); // Генерирует число от 0 до 99
    QPropertyAnimation *glassAnimation = new QPropertyAnimation(ui->glassLabel_2, "geometry");
    QPropertyAnimation *ballAnimation = new QPropertyAnimation(ui->ballLabel_2, "geometry");

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
    glassLabel->setGeometry(QRect(490, 100, glassPixmap.width(), glassPixmap.height()));

    glassAnimation = new QPropertyAnimation(ui->glassLabel_2, "geometry");
    glassAnimation->setDuration(400);
    glassAnimation->setStartValue(QRect(490, 40, glassPixmap.width(), glassPixmap.height()));
    glassAnimation->setEndValue(QRect(490, -40, glassPixmap.width(), glassPixmap.height()));


    QLabel *ballLabel = ui->ballLabel_2;//new QLabel(this);
    QPixmap ballPixmap("/Users/michael/Desktop/ball.png");
    ballLabel->setPixmap(ballPixmap);
    ballLabel->setGeometry(QRect(490, 310, ballPixmap.width(), ballPixmap.height()));
    ballAnimation = new QPropertyAnimation(ui->ballLabel_2, "geometry");
    ballAnimation->setDuration(400);
    ballAnimation->setStartValue(QRect(490, 310, ballPixmap.width(), ballPixmap.height()));
    ballAnimation->setEndValue(QRect(440, 360, ballPixmap.width(), ballPixmap.height()));


    // Соединяем сигнал нажатия кнопки со слотом запуска анимации
    //connect(btnLeft, &QPushButton::clicked, [=]() {
    glassAnimation->start();
    if (randomNumber % 2 == 1){
        ballLabel->show();
        ballAnimation->start();
        connect(glassAnimation, &QPropertyAnimation::finished, this, [this]() {
            resetTimer->start(2000); // 2 seconds
        });
        score++;
    }
    else{
        score = 0;
        ui->lastLabel->setText(QString("Last Score: %1").arg(score));
    }
    connect(glassAnimation, &QPropertyAnimation::finished, this, [this]() {
        resetTimer->start(2000); // 2 seconds
    });
    countRight++;
}


void Widget::resetState()
{
    ui->ballLabel->hide();
    ui->ballLabel_2->hide();
    //ui->glassLabel->setGeometry(QRect(160, 100, glassPixmap.width(), glassPixmap.height()));
    //ui->glassLabel_2->setGeometry(QRect(490, 100, glassPixmap.width(), glassPixmap.height()));
    if (countRight != 0){
        ui->glassLabel_2->move(490, 40);
    }
    if (countLeft != 0){
        ui->glassLabel->move(160, 40);
    }
    // ui->glassLabel->move(160, 40);
    // ui->glassLabel_2->move(490, 40);
    ui->ballLabel->setGeometry(QRect(180, 310, ballPixmap.width(), ballPixmap.height()));
    ui->ballLabel_2->setGeometry(QRect(490, 310, ballPixmap.width(), ballPixmap.height()));
    ui->scoreLabel->setText(QString("Score: %1").arg(score));
}


void Widget::on_btnTake_clicked()
{
    ui->lastLabel->setText(QString("Last Score: %1").arg(score));
    score = 0;
    ui->scoreLabel->setText(QString("Score: %1").arg(0));
}

