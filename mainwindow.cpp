#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("RusZin_QT_3lab");
    //Создаётся и привязывается сцена
    scene=new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    //Выбирается изображение
    QString filename = QFileDialog::getOpenFileName(this,"Выбрать изображение", ".","Файлы изображений (*.png *.jpg *.jpeg *.bmp)");    //Диалог открытия файла с изображением
    if(filename != "")
    {
        QImage img(filename); //Открывается изображение из файла
        AwesomeItem* item=new AwesomeItem(QPixmap::fromImage(img.scaled(150,150))); //Создаётся новый элемент
        item->setPos(0,0);  //Задаётся его положение
        scene->addItem(item);   //Добавляется на сцену
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(scene->items().count()>0)    //Если на сцене есть элементы
    {
        QGraphicsItem *it=scene->items().first(); //Берётся последний добавленный
        scene->removeItem(it);  //Удаляется последний добавленный на сцену элемент
        delete it; //Удаляется сам элемент
    }
}
