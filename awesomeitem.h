#ifndef AWESOMEITEM_H
#define AWESOMEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include "mainwindow.h"
class AwesomeItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos) //Для более удобного задания координат используется макрос, создающий геттер и сеттер
public:
    AwesomeItem(QGraphicsView *graphWidget = nullptr);
    AwesomeItem(QPixmap i, QGraphicsView *graphWidget = nullptr);
    QPainterPath shape() const override;    //Определение формы элемента
    QRectF boundingRect() const override;   //Определение границ элемента
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;    //Собственно рисование элемента
    QString choice(QString k);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override; //Обработка нажатия мышью

private:
    bool state; //Текущее состояние
    bool one_or_two;
    QPixmap img;    //Подключённое изображение
    int size=150;   //Размер элемента
};

#endif // AWESOMEITEM_H
