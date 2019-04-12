#include "card.h"

Card::Card(int id, int x, int y, int w, int h, QGraphicsScene *scene, QGraphicsItem *parent) : QGraphicsObject(parent)
{
    switch (id)
    {
    case 0:
        m_readJSON(address_0);
        break;
    case 1:
        m_readJSON(address_1);
        break;
    case 2:
        m_readJSON(address_2);
        break;
    case 3:
        m_readJSON(address_3);
        break;
    case 4:
        m_readJSON(address_4);
        break;
    case 5:
        m_readJSON(address_5);
        break;
    case 6:
        m_readJSON(address_6);
        break;
    case 7:
        m_readJSON(address_7);
        break;
    case 8:
        m_readJSON(address_8);
        break;
    case 9:
        m_readJSON(address_9);
        break;
    case 10:
        m_readJSON(address_10);
        break;
    case 11:
        m_readJSON(address_11);
        break;
    case 12:
        m_readJSON(address_12);
        break;
    case 13:
        m_readJSON(address_13);
        break;
    case 14:
        m_readJSON(address_14);
        break;
    case 15:
        m_readJSON(address_15);
        break;
    case 16:
        m_readJSON(address_16);
        break;
    case 17:
        m_readJSON(address_17);
        break;
    case 18:
        m_readJSON(address_18);
        break;
    case 19:
        m_readJSON(address_19);
        break;
    case 20:
        m_readJSON(address_20);
        break;
    case 21:
        m_readJSON(address_21);
        break;
    case 22:
        m_readJSON(address_22);
        break;
    case 23:
        m_readJSON(address_23);
        break;
    case 24:
        m_readJSON(address_24);
        break;
    case 25:
        m_readJSON(address_25);
        break;
    case 26:
        m_readJSON(address_26);
        break;
    case 27:
        m_readJSON(address_27);
        break;
    case 28:
        m_readJSON(address_28);
        break;
    case 29:
        m_readJSON(address_29);
        break;
    case 30:
        m_readJSON(address_30);
        break;
    case 31:
        m_readJSON(address_31);
        break;
    case 32:
        m_readJSON(address_32);
        break;
    case 33:
        m_readJSON(address_33);
        break;
    case 34:
        m_readJSON(address_34);
        break;
    default:
        break;
    }
    c_pos_x = x;
    c_pos_y = y;
    c_width = w;
    c_height = h;
    this->setAcceptHoverEvents(true);
}

Card::Card(Card *card, int x, int y, int w, int h, QGraphicsScene *scene, QGraphicsItem *parent) : QGraphicsObject(parent)
{
    c_ID = card->c_ID;
    c_name = card->c_name;
    c_pic_S = card->c_pic_S;
    c_pic_L = card->c_pic_L;
    c_type = card->c_type;
    c_level = card->c_level;
    c_power_orignal = card->c_power_orignal;
    c_power_base = card->c_power_base;
    c_power_current = card->c_power_current;
    c_position = card->c_position;
    c_description = card->c_description;
    c_name_cn = card->c_name_cn;
    c_pos_x = x;
    c_pos_y = y;
    c_width = w;
    c_height = h;
    this->setAcceptHoverEvents(true);
}

QRectF Card::boundingRect() const
{
    return QRectF(c_pos_x, c_pos_y, c_width, c_height);
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(c_pos_x, c_pos_y, c_width, c_height,
                        c_pic_L, 0, 0, CARD_L_WIDTH, CARD_L_HEIGHT);
}

void Card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos(event->scenePos().x() - beforePos.x(), event->scenePos().y() - beforePos.y());
    beforePos = event->scenePos();
    emit c_isMoving(pos);
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    beforePos = event->scenePos();
    beforeTime = (double)clock();
}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    releasePos = event->scenePos();
    releaseTime = (double)clock();
    if(releaseTime - beforeTime < SHORT_TIME)
    {
        emit c_isClicked(this);
    }
}

void Card::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    emit c_isHovered(this);
}

void Card::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    emit c_isNotHovered();
}

void Card::m_readJSON(QString address)
{
    QFile file(address);
    file.open(QIODevice::ReadOnly);

    QByteArray json = file.readAll();
    file.close();

    QJsonDocument jsDoc;
    jsDoc = QJsonDocument::fromJson(json);

    if(jsDoc.isObject())
    {
        QJsonObject obj = jsDoc.object();

        if(obj.contains("ID"))
        {
            QJsonValue value_1 = obj["ID"];
            if(value_1.isDouble())
            {
                c_ID = value_1.toInt();
            }
        }
        if(obj.contains("name_en"))
        {
            QJsonValue value_2 = obj["name_en"];
            if(value_2.isString())
            {
                c_name = value_2.toString();
            }
        }
        if(obj.contains("pic_S"))
        {
            QJsonValue value_3 = obj["pic_S"];
            if(value_3.isString())
            {
                c_pic_S = QPixmap(value_3.toString());
            }
        }
        if(obj.contains("pic_L"))
        {
            QJsonValue value_4 = obj["pic_L"];
            if(value_4.isString())
            {
                c_pic_L = QPixmap(value_4.toString());
            }
        }
        if(obj.contains("type"))
        {
            QJsonValue value_5 = obj["type"];
            if(value_5.isDouble())
            {
                c_type = (TYPE)value_5.toInt();
            }
        }
        if(obj.contains("level"))
        {
            QJsonValue value_6 = obj["level"];
            if(value_6.isDouble())
            {
                c_level = (LEVEL)value_6.toInt();
            }
        }
        if(obj.contains("power"))
        {
            QJsonValue value_7 = obj["power"];
            if(value_7.isDouble())
            {
                c_power_orignal = (uint)value_7.toInt();
                c_power_base = c_power_orignal;
                c_power_current = c_power_base;
            }
        }
        if(obj.contains("position"))
        {
            QJsonValue value_8 = obj["position"];
            if(value_8.isDouble())
            {
                c_position = (POSITION)value_8.toInt();
            }
        }
        if(obj.contains(tr("技能")))
        {
            QJsonValue value_9 = obj[tr("技能")];
            if(value_9.isString())
            {
                c_description = value_9.toString();
            }
        }
        if(obj.contains(tr("name_cn")))
        {
            QJsonValue value_10 = obj[tr("name_cn")];
            if(value_10.isString())
            {
                c_name_cn = value_10.toString();
            }
        }
    }
}

