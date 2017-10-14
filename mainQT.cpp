#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QFont>
#include "rmlib.h"

int main(int argc, char *argv[])
{
    rm_init(0,8875,0,0);
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    QGraphicsRectItem * cache0 = new QGraphicsRectItem();
    QGraphicsRectItem * cache1 = new QGraphicsRectItem();
    QGraphicsRectItem * cache2 = new QGraphicsRectItem();
    QGraphicsRectItem * cache3 = new QGraphicsRectItem();
    QGraphicsRectItem * cache4 = new QGraphicsRectItem();

    cache0->setRect(0,0,200,50);
    cache1->setRect(0,50,200,50);
    cache2->setRect(0,100,200,50);
    cache3->setRect(0,150,200,50);
    cache4->setRect(0,200,200,50);
    cache0->setBrush(QColor(45,0,45,127));
    cache1->setBrush(QColor(45,0,45,127));
    cache2->setBrush(QColor(45,0,45,127));
    cache3->setBrush(QColor(45,0,45,127));
    cache4->setBrush(QColor(45,0,45,127));

    // add the item to the scene
    scene->addItem(cache0);
    scene->addItem(cache1);
    scene->addItem(cache2);
    scene->addItem(cache3);
    scene->addItem(cache4);


    int num = rm_getCN();
    for(int i = num; i > 0; i--){
        std::string key = rm_getCK((i));
        QString kstr = QString::fromStdString(key);
        QGraphicsTextItem *keyt = scene->addText("Key: ");
        keyt->setPos(0, (i-1)*50);
        QGraphicsTextItem *key_T = scene->addText(kstr);
        key_T->setPos(25, (i-1)*50);

        std::string value = rm_getCV((i));
        QString vstr = QString::fromStdString(value);
        QGraphicsTextItem *valuet = scene->addText("Value: ");
        valuet->setPos(0, (i-1)*50+25);
        QGraphicsTextItem *value_T = scene->addText(vstr);
        value_T->setPos(35, ((i-1)*50)+25);
    }

    int num1 = rm_getMN();
    for(int i = 0; i < num1; i++){
        QGraphicsRectItem * main = new QGraphicsRectItem();
        main->setRect(250,50*i,200,50);
        main->setBrush(QColor(0,45,45,127));
        scene->addItem(main);

        std::string key = rm_getMK((num1-i));
        QString kstr = QString::fromStdString(key);
        QGraphicsTextItem *keyt = scene->addText("Key: ");
        keyt->setPos(250, (i*50));
        QGraphicsTextItem *key_T = scene->addText(kstr);
        key_T->setPos(275, i*50);

        std::string value = rm_getMV((num-i));
        QString vstr = QString::fromStdString(value);
        QGraphicsTextItem *valuet = scene->addText("Value: ");
        valuet->setPos(250, (i*50+25));
        QGraphicsTextItem *value_T = scene->addText(vstr);
        value_T->setPos(285, (i*50)+25);
    }
    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();
    return a.exec();
}
