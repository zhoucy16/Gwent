#ifndef CARD_H
#define CARD_H

#include <QtWidgets>
#include "global.h"
#include <time.h>

typedef enum{Cu, Ag, Au, LEADER} LEVEL;
typedef enum{IN_DECK_A, IN_DECK_B, CHOOSING, IN_HAND, ON_A, ON_B, IN_CEMETERY_A, IN_CEMETERY_B} STATE;
typedef enum{NEUTRAL, MONSTER} TYPE;
typedef enum{A, B, A_B, A_1, A_2, A_3, B_1, B_2, B_3} POSITION;

class Card : public QGraphicsObject
{
    Q_OBJECT

public:
    Card(int id, int x, int y, int w, int h, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    Card(Card *card, int x, int y, int w, int h, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    virtual ~Card(){}

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

public:
    void m_readJSON(QString address);

public slots:

signals:
    void c_isMoving(QPointF &pos);
    void c_isClicked(Card *card);
    void c_isHovered(Card *card);
    void c_isNotHovered();

public:
    int c_ID;
    QString c_name, c_description, c_name_cn;
    QPixmap c_pic_S, c_pic_L, c_pic_oppsite;
    TYPE c_type;
    LEVEL c_level;
    STATE c_state;
    POSITION c_position;
    uint c_power_orignal, c_power_base, c_power_current, c_shield;
    int c_pos_x, c_pos_y, c_width, c_height;
    QPointF beforePos, releasePos;
    double beforeTime, releaseTime;
};

#endif // CARD_H
