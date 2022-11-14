#include "awesomeitem.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
AwesomeItem::AwesomeItem(QGraphicsView *graphWidget)
{
    setFlag(ItemIsMovable); //Задание возможности перемещать элемент
    setZValue(-1);  //На всякий случай задание координаты Z
    state=true; //Изначально повёрнут лицевой стороной

}

AwesomeItem::AwesomeItem(QPixmap i, QGraphicsView *graphWidget):AwesomeItem(graphWidget)
{
    img=i;  //Задание изображения
}

QPainterPath AwesomeItem::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, size, size); //Формой элемента является квадрат
    return path;
}

QRectF AwesomeItem::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( 0 - adjust, 0 - adjust, size + 2*adjust, size + 2*adjust);   //Для границ есть небольшой зазор чтобы проще было попасть
}

void AwesomeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen); //Границы у квадрата не будут нарисованы
    if(state){
        painter->setBrush(img);
        }//Если сторона лицевая - рисуется изображение
    if(!state && one_or_two){
        QPixmap k("C:\\Users\\User\\Documents\\QT5lab\\res\\st_krasn.jpg");
        painter->setBrush(k);
        }//Если сторона лицевая - риуется изображение
    if(!state && !one_or_two){
        QPixmap k("C:\\Users\\User\\Documents\\QT5lab\\res\\st_krasn.jpg");
        painter->setBrush(k);
        }
    painter->drawRect(0, 0, size, size);    //Рисуется элемент
}

void AwesomeItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::RightButton){
        state=!state;
        //if(Ui::MainWindow::lineEdit->text().toInt()==1){one_or_two=true;}
        //if(Ui::MainWindow::lineEdit->text().toInt()==2){one_or_two=false;}
        }//Если нажата правая кнопка мыши - перевернуть элемент
    update();
    QGraphicsItem::mousePressEvent(event);
}
