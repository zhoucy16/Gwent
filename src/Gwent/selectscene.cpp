#include "selectscene.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

SelectScene::SelectScene(QString address, QWidget *parent) : QMainWindow(parent)
{
    leaderset = false;
    m_address = address;

    sum = 0;
    for(int i = 0; i < 4; i++)
    {
        color[i] = 0;
    }

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, FIELD_WIDTH*SCALE_FILED_WINDOW, FIELD_HEIGHT*SCALE_FILED_WINDOW);

    field = new Field(address_selectfield, scene);
    scene->addItem(field);

    text_sum = new QGraphicsTextItem(tr("全部卡牌 %1").arg(sum));
    text_sum->setX(SELECTFIELD_NUMBER_LEFT*SCALE_FILED_WINDOW);
    text_sum->setY(SELECTFIELD_NUMBER_TOP*SCALE_FILED_WINDOW);
    text_sum->setTextWidth(SELECTFIELD_NUMBER_WIDTH*SCALE_FILED_WINDOW);
    text_sum->setDefaultTextColor(qRgba(255, 0, 0, 100));
    text_sum_2 = new QGraphicsTextItem(tr("不低于25/上限40"));
    text_sum_2->setX(SELECTFIELD_NUMBER_2_LEFT*SCALE_FILED_WINDOW);
    text_sum_2->setY(SELECTFIELD_NUMBER_2_TOP*SCALE_FILED_WINDOW);
    text_sum_2->setTextWidth(SELECTFIELD_NUMBER_WIDTH*SCALE_FILED_WINDOW);
    text_sum_2->setDefaultTextColor(qRgb(255, 0, 0));

    QFont font, font2;
    font.setPixelSize(FONT_M*SCALE_FILED_WINDOW);
    font2.setPixelSize(FONT_S*SCALE_FILED_WINDOW);
    text_sum->setFont(font);
    text_sum_2->setFont(font2);

    connect(this, SIGNAL(sumChanged()), this, SLOT(changeSum()));

    QPushButton *pushbtn = new QPushButton(parent);
    pushbtn->setGeometry(SELECTFIELD_ICON_CONFIRM_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_ICON_CONFIRM_TOP*SCALE_FILED_WINDOW,
                         ICON_WIDTH*SCALE_SELECTFIELD_ICON*SCALE_FILED_WINDOW, ICON_HEIGHT*SCALE_SELECTFIELD_ICON*SCALE_FILED_WINDOW);
    pushbtn->setStyleSheet("QPushButton{border-image:url(:/new/cards/field/confirm.png);" "border:2px 2px 2px 2px;}");
    scene->addWidget(pushbtn);

    connect(pushbtn, SIGNAL(clicked(bool)), this, SLOT(addDeck()));

    pot_5 = new QGraphicsRectItem(SELECTFIELD_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_5_TOP*SCALE_FILED_WINDOW,
                                  SELECTFIELD_STORE_WIDTH*SCALE_FILED_WINDOW, SELECTFIELD_STORE_HEIGHT*SCALE_FILED_WINDOW);
    pot_1 = new QGraphicsRectItem(SELECTFIELD_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_1_TOP*SCALE_FILED_WINDOW,
                                  SELECTFIELD_STORE_WIDTH*SCALE_FILED_WINDOW, SELECTFIELD_STORE_HEIGHT*SCALE_FILED_WINDOW);
    pot_2 = new QGraphicsRectItem(SELECTFIELD_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_2_TOP*SCALE_FILED_WINDOW,
                                  SELECTFIELD_STORE_WIDTH*SCALE_FILED_WINDOW, SELECTFIELD_STORE_HEIGHT*SCALE_FILED_WINDOW);
    pot_3 = new QGraphicsRectItem(SELECTFIELD_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_3_TOP*SCALE_FILED_WINDOW,
                                  SELECTFIELD_STORE_WIDTH*SCALE_FILED_WINDOW, SELECTFIELD_STORE_HEIGHT*SCALE_FILED_WINDOW);
    pot_4 = new QGraphicsRectItem(SELECTFIELD_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_4_TOP*SCALE_FILED_WINDOW,
                                  SELECTFIELD_STORE_WIDTH*SCALE_FILED_WINDOW, SELECTFIELD_STORE_HEIGHT*SCALE_FILED_WINDOW);

    QColor color(qRgba(0, 0, 0, 0));
    QPen pen(color);
    pen.setWidth(-1);
    pot_5->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_5->setPen(pen);
    pot_1->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_1->setPen(pen);
    pot_2->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_2->setPen(pen);
    pot_3->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_3->setPen(pen);
    pot_4->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_4->setPen(pen);

    for(int i = 0; i < SUM; i++)
    {
        each[i] = 0;
        cards_5.append(new Card(i,SELECTFIELD_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_5_TOP*SCALE_FILED_WINDOW,
                                CARD_L_WIDTH*SCALE_FILED_WINDOW*SCALE_SELECTFIELD_CARD_L, CARD_L_HEIGHT*SCALE_FILED_WINDOW*SCALE_SELECTFIELD_CARD_L, scene, pot_5));
        cards_5[i]->setPos(CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW*i, 0);
        pos_5.append(cards_5[i]->pos());
        connect(cards_5[i], SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
        connect(cards_5[i], SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
        connect(cards_5[i], SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust(QPointF&)));
        connect(cards_5[i], SIGNAL(c_isClicked(Card*)), this, SLOT(chooseCard(Card*)));
    }



    scene->addItem(pot_5);
    scene->addItem(pot_1);
    scene->addItem(pot_2);
    scene->addItem(pot_3);
    scene->addItem(pot_4);
    scene->addItem(text_sum);
    scene->addItem(text_sum_2);


    view = new QGraphicsView(scene);
    view->resize(FIELD_WIDTH*SCALE_FILED_WINDOW, FIELD_HEIGHT*SCALE_FILED_WINDOW);
    view->show();
}

void SelectScene::putInfo(Card *card)
{
    pixmap = new QGraphicsPixmapItem(card->c_pic_L);
    pixmap->setScale(SCALE_FILED_WINDOW*SCALE_SELECTFIELD_CARD_L_INFO);
    pixmap->setPos(SELECTFIELD_INFO_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_INFO_TOP*SCALE_FILED_WINDOW);
    text = new QGraphicsTextItem(card->c_description);
    text->setTextWidth(SELECTFIELD_INFO_WIDTH*SCALE_FILED_WINDOW);
    text->setX(SELECTFIELD_INFO_LEFT*SCALE_FILED_WINDOW);
    text->setY(SELECTFIELD_INFO_TOP*SCALE_FILED_WINDOW + CARD_L_HEIGHT*SCALE_FILED_WINDOW*SCALE_SELECTFIELD_CARD_L_INFO);
    text->setDefaultTextColor(qRgb(255, 215, 0));
    QFont font;
    font.setPixelSize(FONT_S*SCALE_FILED_WINDOW);
    text->setFont(font);
    scene->addItem(pixmap);
    scene->addItem(text);
}

void SelectScene::clearInfo()
{
    scene->removeItem(pixmap);
    scene->removeItem(text);
}

void SelectScene::posAdjust(QPointF &pos)
{
    if((pos_5[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_5[SUM-1].x() + pos.x() >= SELECTFIELD_STORE_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        for (int i = 0; i < SUM; i++)
        {
            pos_5[i].setX(pos_5[i].x() + pos.x());
            cards_5[i]->setPos(pos_5[i]);
        }
    }
}

void SelectScene::posAdjust1(QPointF &pos)
{
    if((pos_1[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_1[cards_1.count()-1].x() + pos.x() >= SELECTFIELD_STORE_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_1.count();
        for (int i = 0; i < j; i++)
        {
            pos_1[i].setX(pos_1[i].x() + pos.x());
            cards_1[i]->setPos(pos_1[i]);
        }
    }
}

void SelectScene::posAdjust2(QPointF &pos)
{
    if((pos_2[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_2[cards_2.count()-1].x() + pos.x() >= SELECTFIELD_STORE_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_2.count();
        for (int i = 0; i < j; i++)
        {
            pos_2[i].setX(pos_2[i].x() + pos.x());
            cards_2[i]->setPos(pos_2[i]);
        }
    }
}

void SelectScene::posAdjust3(QPointF &pos)
{
    if((pos_3[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_3[cards_3.count()-1].x() + pos.x() >= SELECTFIELD_STORE_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_3.count();
        for (int i = 0; i < j; i++)
        {
            pos_3[i].setX(pos_3[i].x() + pos.x());
            cards_3[i]->setPos(pos_3[i]);
        }
    }
}

void SelectScene::posAdjust4(QPointF &pos)
{
    if((pos_4[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_4[cards_4.count()-1].x() + pos.x() >= SELECTFIELD_STORE_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_4.count();
        for (int i = 0; i < j; i++)
        {
            pos_4[i].setX(pos_4[i].x() + pos.x());
            cards_4[i]->setPos(pos_4[i]);
        }
    }
}

void SelectScene::chooseCard(Card *card)
{
    if(sum == 40)
    {
        return;
    }
    else if(card->c_level == Cu && each[card->c_ID] == 3)
    {
        return;
    }
    else if(card->c_level == Ag && (each[card->c_ID] == 1 || color[card->c_level] == 6))
    {
        return;
    }
    else if(card->c_level == Au && (each[card->c_ID] == 1 || color[card->c_level] == 4))
    {
        return;
    }
    else if(card->c_level == LEADER)
    {
        setLeader(card);
        return;
    }
    else if(card->c_type == NEUTRAL)
    {
        each[card->c_ID]++;
        color[card->c_level]++;
        sum++;
        emit sumChanged();

        Card *newcard = new Card(card, SELECTFIELD_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_4_TOP*SCALE_FILED_WINDOW,
                                 CARD_L_WIDTH*SCALE_FILED_WINDOW*SCALE_SELECTFIELD_CARD_L, CARD_L_HEIGHT*SCALE_FILED_WINDOW*SCALE_SELECTFIELD_CARD_L, scene, pot_4);

        if(pos_4.empty())
        {
            newcard->setPos(0, 0);
        }
        else
        {
            newcard->setPos(pos_4.back().x() + CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW, 0);
        }

        cards_4.append(newcard);
        pos_4.append(newcard->pos());

        connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
        connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
        connect(newcard, SIGNAL(c_isClicked(Card*)), this, SLOT(cancelCard4(Card*)));
        connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust4(QPointF&)));

        return;
    }
    else if(card->c_position == A_2 || card->c_position == B_2)
    {
        each[card->c_ID]++;
        color[card->c_level]++;
        sum++;
        emit sumChanged();

        Card *newcard = new Card(card, SELECTFIELD_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_2_TOP*SCALE_FILED_WINDOW,
                                 CARD_L_WIDTH*SCALE_FILED_WINDOW*SCALE_SELECTFIELD_CARD_L, CARD_L_HEIGHT*SCALE_FILED_WINDOW*SCALE_SELECTFIELD_CARD_L, scene, pot_2);
        newcard->setPos(CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW*cards_2.count(), 0);

        if(pos_2.empty())
        {
            newcard->setPos(0, 0);
        }
        else
        {
            newcard->setPos(pos_2.back().x() + CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW, 0);
        }

        cards_2.append(newcard);
        pos_2.append(newcard->pos());

        connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
        connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
        connect(newcard, SIGNAL(c_isClicked(Card*)), this, SLOT(cancelCard2(Card*)));
        connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust2(QPointF&)));
        return;
    }
    else if(card->c_position == A_3 || card->c_position == B_3)
    {
        each[card->c_ID]++;
        color[card->c_level]++;
        sum++;
        emit sumChanged();

        Card *newcard = new Card(card, SELECTFIELD_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_3_TOP*SCALE_FILED_WINDOW,
                                 CARD_L_WIDTH*SCALE_FILED_WINDOW*SCALE_SELECTFIELD_CARD_L, CARD_L_HEIGHT*SCALE_FILED_WINDOW*SCALE_SELECTFIELD_CARD_L, scene, pot_3);
        newcard->setPos(CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW*cards_3.count(), 0);

        if(pos_3.empty())
        {
            newcard->setPos(0, 0);
        }
        else
        {
            newcard->setPos(pos_3.back().x() + CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW, 0);
        }

        cards_3.append(newcard);
        pos_3.append(newcard->pos());

        connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
        connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
        connect(newcard, SIGNAL(c_isClicked(Card*)), this, SLOT(cancelCard3(Card*)));
        connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust3(QPointF&)));
        return;
    }
    else if(card->c_position == A_1 || card->c_position == B_1 || card->c_position == A || card->c_position == B || card->c_position == A_B)
    {
        each[card->c_ID]++;
        color[card->c_level]++;
        sum++;
        emit sumChanged();

        Card *newcard = new Card(card, SELECTFIELD_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_1_TOP*SCALE_FILED_WINDOW,
                                 CARD_L_WIDTH*SCALE_FILED_WINDOW*SCALE_SELECTFIELD_CARD_L, CARD_L_HEIGHT*SCALE_FILED_WINDOW*SCALE_SELECTFIELD_CARD_L, scene, pot_1);
        newcard->setPos(CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW*cards_1.count(), 0);

        if(pos_1.empty())
        {
            newcard->setPos(0, 0);
        }
        else
        {
            newcard->setPos(pos_1.back().x() + CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW, 0);
        }

        cards_1.append(newcard);
        pos_1.append(newcard->pos());

        connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
        connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
        connect(newcard, SIGNAL(c_isClicked(Card*)), this, SLOT(cancelCard1(Card*)));
        connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust1(QPointF&)));
        return;
    }
}

void SelectScene::cancelCard1(Card *card)
{
    emit card->c_isNotHovered();
    sum--;
    emit sumChanged();
    each[card->c_ID]--;
    color[card->c_level]--;
    pos_1.removeOne(card->pos());
    cards_1.removeOne(card);
    scene->removeItem(card);
    int j = pos_1.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_1[i].x() > card->pos().x())
        {
            pos_1[i].setX(pos_1[i].x() - CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW);
            cards_1[i]->setPos(pos_1[i]);
        }
    }
}

void SelectScene::cancelCard2(Card *card)
{
    emit card->c_isNotHovered();
    sum--;
    emit sumChanged();
    each[card->c_ID]--;
    color[card->c_level]--;
    pos_2.removeOne(card->pos());
    cards_2.removeOne(card);
    scene->removeItem(card);
    int j = pos_2.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_2[i].x() > card->pos().x())
        {
            pos_2[i].setX(pos_2[i].x() - CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW);
            cards_2[i]->setPos(pos_2[i]);
        }
    }
}

void SelectScene::cancelCard3(Card *card)
{
    emit card->c_isNotHovered();
    sum--;
    emit sumChanged();
    each[card->c_ID]--;
    color[card->c_level]--;
    pos_3.removeOne(card->pos());
    cards_3.removeOne(card);
    scene->removeItem(card);
    int j = pos_3.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_3[i].x() > card->pos().x())
        {
            pos_3[i].setX(pos_3[i].x() - CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW);
            cards_3[i]->setPos(pos_3[i]);
        }
    }
}

void SelectScene::cancelCard4(Card *card)
{
    emit card->c_isNotHovered();
    sum--;
    emit sumChanged();
    each[card->c_ID]--;
    color[card->c_level]--;
    pos_4.removeOne(card->pos());
    cards_4.removeOne(card);
    scene->removeItem(card);
    int j = pos_4.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_4[i].x() > card->pos().x())
        {
            pos_4[i].setX(pos_4[i].x() - CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L*SCALE_FILED_WINDOW);
            cards_4[i]->setPos(pos_4[i]);
        }
    }
}

void SelectScene::setLeader(Card *card)
{
    leaderset = true;
    leader = new Card(card, SELECTFIELD_LEADER_LEFT*SCALE_FILED_WINDOW, SELECTFIELD_LEADER_TOP*SCALE_FILED_WINDOW,
                      CARD_L_WIDTH*SCALE_SELECTFIELD_CARD_L_LEADER*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_SELECTFIELD_CARD_L_LEADER*SCALE_FILED_WINDOW, scene);
    scene->addItem(leader);
    connect(leader, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
    connect(leader, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
}

void SelectScene::changeSum()
{
    text_sum->setPlainText(tr("全部卡牌 %1").arg(sum));
}

void SelectScene::addDeck()
{
    if(sum < 25 || leaderset == false)
    {
        return;
    }
    QJsonArray cardsArray;
    int j = cards_1.count();
    for(int i = 0; i < j; i++)
    {
        cardsArray.append(cards_1[i]->c_ID);
    }
    j = cards_2.count();
    for(int i = 0; i < j; i++)
    {
        cardsArray.append(cards_2[i]->c_ID);
    }
    j =  cards_3.count();
    for(int i = 0; i < j; i++)
    {
        cardsArray.append(cards_3[i]->c_ID);
    }
    j = cards_4.count();
    for(int i = 0; i < j; i++)
    {
        cardsArray.append(cards_4[i]->c_ID);
    }

    QJsonObject json;
    json.insert("Leader", leader->c_ID);
    json.insert("Cards", QJsonValue(cardsArray));

    QJsonDocument document;
    document.setObject(json);

    QByteArray byte_array = document.toJson(QJsonDocument::Compact);

    QFile saveFile(m_address);
    if(!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Couldn't open the saveFile");
        return;
    }

    saveFile.write(byte_array);
    saveFile.close();
    view->close();
}
