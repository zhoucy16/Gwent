#include "field.h"

Field::Field(QString address, QGraphicsScene *scene, QGraphicsItem *parent)
{
    f_pic = QPixmap(address);
}

QRectF Field::boundingRect() const
{
    return QRectF(0, 0, FIELD_WIDTH*SCALE_FILED_WINDOW, FIELD_HEIGHT*SCALE_FILED_WINDOW);
}

void Field::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, FIELD_WIDTH*SCALE_FILED_WINDOW, FIELD_HEIGHT*SCALE_FILED_WINDOW, f_pic, 0, 0, FIELD_WIDTH, FIELD_HEIGHT);
}
