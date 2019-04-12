#ifndef FIELD_H
#define FIELD_H

#include <QtWidgets>
#include "global.h"

class Field : public QGraphicsObject
{
    Q_OBJECT

public:
    Field(QString address,  QGraphicsScene *scene, QGraphicsItem *parent = 0);
    virtual ~Field(){}

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    QPixmap f_pic;

};

#endif // FIELD_H
