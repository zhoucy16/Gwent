#include "battlefield.h"
#include "QKeyEvent"
#include "QWheelEvent"
#include "QMouseEvent"

BattleField::BattleField(QString address1, QString address2, QWidget *parent) : QMainWindow(parent), power_A(0), power_A_1(0), power_A_2(0), power_A_3(0), power_B_3(0), power_B_2(0), power_B_1(0), power_B(0)
{
    m_address1 = address1;
    m_address2 = address2;
    chosen = false;
    usable = true;
    giveUpA = false;
    giveUpB = false;
    leaderA_chosen = false;
    leaderB_chosen = false;
    isFirst = 1;
    isMyTurn = 1;
    AWin = 0;
    BWin = 0;
    changeTimes = 0;
    round = 0;
    cardsNumber[0] = 0;
    cardsNumber[1] = ROUND_ONE_CHANGE;
    cardsNumber[2] = ROUND_TWO_CHANGE;
    cardsNumber[3] = ROUND_THREE_CHANGE;
    cardsSumNumber[0] = 0;
    cardsSumNumber[1] = ROUND_ONE;
    cardsSumNumber[2] = ROUND_TWO;
    cardsSumNumber[3] = ROUND_THREE;
    score[0] = 0;
    score[1] = 0;
    score[2] = 0;
    score[3] = 0;
    score[4] = 0;
    score[5] = 0;
    seconds = SECONDS;

    scene = new QGraphicsScene(parent);
    scene->setSceneRect(0, 0, FIELD_WIDTH*SCALE_FILED_WINDOW, FIELD_HEIGHT*SCALE_FILED_WINDOW);

    field = new Field(address_battlefield, scene);
    scene->addItem(field);

    pot_A_0 = new QGraphicsRectItem(BATTLEFIELD_HAND_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_HAND_A_TOP*SCALE_FILED_WINDOW,
                                    BATTLEFIELD_HAND_WIDTH*SCALE_FILED_WINDOW, BATTLEFIELD_HAND_HEIGHT*SCALE_FILED_WINDOW);
    pot_B_0 = new QGraphicsRectItem(BATTLEFIELD_HAND_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_HAND_B_TOP*SCALE_FILED_WINDOW,
                                    BATTLEFIELD_HAND_WIDTH*SCALE_FILED_WINDOW, BATTLEFIELD_HAND_HEIGHT*SCALE_FILED_WINDOW);
    pot_A_1 = new QGraphicsRectItem(BATTLEFIELD_WAR_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_A_1_TOP*SCALE_FILED_WINDOW,
                                    BATTLEFIELD_WAR_WIDTH*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_HEIGHT*SCALE_FILED_WINDOW);
    pot_A_2 = new QGraphicsRectItem(BATTLEFIELD_WAR_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_A_2_TOP*SCALE_FILED_WINDOW,
                                    BATTLEFIELD_WAR_WIDTH*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_HEIGHT*SCALE_FILED_WINDOW);
    pot_A_3 = new QGraphicsRectItem(BATTLEFIELD_WAR_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_A_3_TOP*SCALE_FILED_WINDOW,
                                    BATTLEFIELD_WAR_WIDTH*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_HEIGHT*SCALE_FILED_WINDOW);
    pot_B_1 = new QGraphicsRectItem(BATTLEFIELD_WAR_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_B_1_TOP*SCALE_FILED_WINDOW,
                                    BATTLEFIELD_WAR_WIDTH*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_HEIGHT*SCALE_FILED_WINDOW);
    pot_B_2 = new QGraphicsRectItem(BATTLEFIELD_WAR_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_B_2_TOP*SCALE_FILED_WINDOW,
                                    BATTLEFIELD_WAR_WIDTH*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_HEIGHT*SCALE_FILED_WINDOW);
    pot_B_3 = new QGraphicsRectItem(BATTLEFIELD_WAR_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_B_3_TOP*SCALE_FILED_WINDOW,
                                    BATTLEFIELD_WAR_WIDTH*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_HEIGHT*SCALE_FILED_WINDOW);
    pot_pass = new QGraphicsRectItem(BATTLEFIELD_PASS_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_PASS_TOP*SCALE_FILED_WINDOW,
                                     BATTLEFIELD_PASS_WIDTH*SCALE_FILED_WINDOW, BATTLEFIELD_PASS_HEIGHT*SCALE_FILED_WINDOW);

    QColor color(qRgba(255, 255, 255, 200));
    QPen pen(color);
    pen.setWidth(-1);
    pot_A_0->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_A_0->setPen(pen);
    pot_A_1->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_A_1->setPen(pen);
    pot_A_2->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_A_2->setPen(pen);
    pot_A_3->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_A_3->setPen(pen);
    pot_B_0->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_B_0->setPen(pen);
    pot_B_1->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_B_1->setPen(pen);
    pot_B_2->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_B_2->setPen(pen);
    pot_B_3->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    pot_B_3->setPen(pen);
    pot_pass->setPen(pen);

    scene->addItem(pot_A_0);
    scene->addItem(pot_A_1);
    scene->addItem(pot_A_2);
    scene->addItem(pot_A_3);
    scene->addItem(pot_B_0);
    scene->addItem(pot_B_1);
    scene->addItem(pot_B_2);
    scene->addItem(pot_B_3);
    scene->addItem(pot_pass);

    connect(this, SIGNAL(isclicked(QGraphicsRectItem*)), this, SLOT(useCard(QGraphicsRectItem*)));

    color2[0] = QColor(222, 11, 33, 255);
    color2[1] = QColor(21, 98, 252, 255);
    QFont font_S, font_M, font_L;
    font_S.setPixelSize(FONT_S*SCALE_FILED_WINDOW);
    font_M.setPixelSize(FONT_M*SCALE_FILED_WINDOW);
    font_L.setPixelSize(FONT_L*SCALE_FILED_WINDOW);

    text_A = new QGraphicsTextItem(QString::number(power_A));
    text_A->setPos(BATTLEFIELD_POWER_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_POWER_A_TOP*SCALE_FILED_WINDOW);
    text_A->setDefaultTextColor(color);
    text_A->setFont(font_M);
    text_B = new QGraphicsTextItem(QString::number(power_B));
    text_B->setPos(BATTLEFIELD_POWER_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_POWER_B_TOP*SCALE_FILED_WINDOW);
    text_B->setDefaultTextColor(color);
    text_B->setFont(font_M);
    text_A_1 = new QGraphicsTextItem(QString::number(power_A_1));
    text_A_1->setPos(BATTLEFIELD_POWER_DIS_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_POWER_DIS_A_1_TOP*SCALE_FILED_WINDOW);
    text_A_1->setDefaultTextColor(color);
    text_A_1->setFont(font_S);
    text_A_2 = new QGraphicsTextItem(QString::number(power_A_2));
    text_A_2->setPos(BATTLEFIELD_POWER_DIS_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_POWER_DIS_A_2_TOP*SCALE_FILED_WINDOW);
    text_A_2->setDefaultTextColor(color);
    text_A_2->setFont(font_S);
    text_A_3 = new QGraphicsTextItem(QString::number(power_A_3));
    text_A_3->setPos(BATTLEFIELD_POWER_DIS_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_POWER_DIS_A_3_TOP*SCALE_FILED_WINDOW);
    text_A_3->setDefaultTextColor(color);
    text_A_3->setFont(font_S);
    text_B_1 = new QGraphicsTextItem(QString::number(power_B_1));
    text_B_1->setPos(BATTLEFIELD_POWER_DIS_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_POWER_DIS_B_1_TOP*SCALE_FILED_WINDOW);
    text_B_1->setDefaultTextColor(color);
    text_B_1->setFont(font_S);
    text_B_2 = new QGraphicsTextItem(QString::number(power_B_2));
    text_B_2->setPos(BATTLEFIELD_POWER_DIS_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_POWER_DIS_B_2_TOP*SCALE_FILED_WINDOW);
    text_B_2->setDefaultTextColor(color);
    text_B_2->setFont(font_S);
    text_B_3 = new QGraphicsTextItem(QString::number(power_B_3));
    text_B_3->setPos(BATTLEFIELD_POWER_DIS_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_POWER_DIS_B_3_TOP*SCALE_FILED_WINDOW);
    text_B_3->setDefaultTextColor(color);
    text_B_3->setFont(font_S);
    text_time = new QGraphicsTextItem(QString::number(seconds));
    text_time->setPos(BATTLEFIELD_PASS_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_PASS_TOP*SCALE_FILED_WINDOW);
    text_time->setDefaultTextColor(color2[isMyTurn]);
    text_time->setFont(font_L);

    scene->addItem(text_A);
    scene->addItem(text_B);
    scene->addItem(text_A_1);
    scene->addItem(text_B_1);
    scene->addItem(text_A_2);
    scene->addItem(text_B_2);
    scene->addItem(text_A_3);
    scene->addItem(text_B_3);
    scene->addItem(text_time);

    deck_A = new QGraphicsPixmapItem(QString(address_deck));
    deck_B = new QGraphicsPixmapItem(QString(address_deck));
    deck_A->setPos(BATTLEFIELD_DECK_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_DECK_A_TOP*SCALE_FILED_WINDOW);
    deck_A->setScale(SCALE_BATTLEFIELD_CARD_DECK*SCALE_FILED_WINDOW);
    deck_B->setPos(BATTLEFIELD_DECK_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_DECK_B_TOP*SCALE_FILED_WINDOW);
    deck_B->setScale(SCALE_BATTLEFIELD_CARD_DECK*SCALE_FILED_WINDOW);

    scene->addItem(deck_A);
    scene->addItem(deck_B);

    laundry = new cardslaundry();

    readFile(m_address1, leader_A_ID, cards_A_deck);
    leader_A = new Card(leader_A_ID, BATTLEFIELD_LEADER_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_HAND_A_TOP*SCALE_FILED_WINDOW,
                        CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, scene);
    scene->addItem(leader_A);
    laundry->swapcards(cards_A_deck);
    connect(leader_A, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
    connect(leader_A, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
    connect(leader_A, SIGNAL(c_isClicked(Card*)), this, SLOT(setChosenCard(Card*)));

    readFile(m_address2, leader_B_ID, cards_B_deck);
    leader_B = new Card(leader_B_ID, BATTLEFIELD_LEADER_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_HAND_B_TOP*SCALE_FILED_WINDOW,
                        CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, scene);
    scene->addItem(leader_B);
    laundry->swapcards(cards_B_deck);
    connect(leader_B, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
    connect(leader_B, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
    connect(leader_B, SIGNAL(c_isClicked(Card*)), this, SLOT(setChosenCard(Card*)));

    QFont font;
    font.setPixelSize(FONT_M);

    pot_change = new QGraphicsRectItem(0, 0, BATTLEFIELD_CHANGE_WIDTH*SCALE_FILED_WINDOW, FIELD_HEIGHT*SCALE_FILED_WINDOW);
    pot_change->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    text_change = new QGraphicsTextItem(tr("你已经换牌%1/%2张").arg(changeTimes).arg(cardsNumber[round]), pot_change);
    text_change->setPos(BATTLEFIELD_TEXT_CHANGE_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_TEXT_CHANGE_TOP*SCALE_FILED_WINDOW);
    text_change->setDefaultTextColor(color2[1]);
    text_change->setFont(font);
    button = new QPushButton();
    button->setGeometry(BATTLEFIELD_BUTTON_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_BUTTON_TOP*SCALE_FILED_WINDOW,
                        ICON_WIDTH*SCALE_SELECTFIELD_ICON*SCALE_FILED_WINDOW, ICON_HEIGHT*SCALE_SELECTFIELD_ICON*SCALE_FILED_WINDOW);
    button->setStyleSheet("QPushButton{border-image:url(:/new/cards/field/confirm.png);""border:2px 2px 2px 2px;}");
    scene->addWidget(button);
    button->setVisible(false);
    connect(button, SIGNAL(clicked(bool)), this, SLOT(cardChanged()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));

    roundOne();

    field->installEventFilter(this);

    view = new QGraphicsView(scene);
    view->resize(FIELD_WIDTH*SCALE_FILED_WINDOW, FIELD_HEIGHT*SCALE_FILED_WINDOW);
    view->show();
}

void BattleField::timerUpdate()
{
    if(seconds > 0)
    {
        seconds--;
        text_time->setPlainText(QString("%1").arg(seconds, 2, 10, QChar('0')));
    }
    else if(seconds == 0)
    {
        seconds = SECONDS;
        if(giveUpA && giveUpB)
        {
            giveUpA = false;
            giveUpB = false;
            score[round*2 - 2] = power_A;
            score[round*2 - 1] = power_B;
            if(power_A > power_B)
            {
                AWin++;
            }
            else if(power_B > power_A)
            {
                BWin++;
            }
            else if(power_A == power_B)
            {
                AWin++;
                BWin++;
            }
            powerUpdate();
            if(AWin == 2 && BWin == 2)
            {
                score_field = new scorefield(tr("平局"), score);
                view->close();
            }
            else if(AWin == 2)
            {
                score_field = new scorefield(tr("蓝胜"), score);
                view->close();
            }
            else if(BWin == 2)
            {
                score_field = new scorefield(tr("红胜"), score);
                view->close();
            }

            int j = cards_A_1.count();
            for(int i = 0; i < j; i++)
            {
                scene->removeItem(cards_A_1.first());
                pos_A_1.removeFirst();
                cards_A_1.removeFirst();
            }
            j = cards_A_2.count();
            for(int i = 0; i < j; i++)
            {
                scene->removeItem(cards_A_2.first());
                pos_A_2.removeFirst();
                cards_A_2.removeFirst();
            }
            j = cards_A_3.count();
            for(int i = 0; i < j; i++)
            {
                scene->removeItem(cards_A_3.first());
                pos_A_3.removeFirst();
                cards_A_3.removeFirst();
            }
            j = cards_B_1.count();
            for(int i = 0; i < j; i++)
            {
                scene->removeItem(cards_B_1.first());
                pos_B_1.removeFirst();
                cards_B_1.removeFirst();
            }
            j = cards_B_2.count();
            for(int i = 0; i < j; i++)
            {
                scene->removeItem(cards_B_2.first());
                pos_B_2.removeFirst();
                cards_B_2.removeFirst();
            }
            j = cards_B_3.count();
            for(int i = 0; i < j; i++)
            {
                scene->removeItem(cards_B_3.first());
                pos_B_3.removeFirst();
                cards_B_3.removeFirst();
            }
            changeTimes = 0;
            roundOne();
        }
        else if(giveUpA && !giveUpB)
        {
            isMyTurn = 0;
            if(usable)
            {
                int i = rand() % cards_B_0.count();
                scene->removeItem(cards_B_0[i]);
                adjustPos_B_0(cards_B_0[i]);
                pos_B_0.removeAt(i);
                cards_B_0.removeAt(i);
            }
        }
        else if(giveUpB && !giveUpA)
        {
            isMyTurn = 1;
            if(usable)
            {
                int i = rand() % cards_A_0.count();
                scene->removeItem(cards_A_0[i]);
                adjustPos_A_0(cards_A_0[i]);
                pos_A_0.removeAt(i);
                cards_A_0.removeAt(i);
            }
        }
        else if(isMyTurn == 1)
        {
            isMyTurn = 0;
            if(usable)
            {
                int i = rand() % cards_B_0.count();
                scene->removeItem(cards_B_0[i]);
                adjustPos_B_0(cards_B_0[i]);
                pos_B_0.removeAt(i);
                cards_B_0.removeAt(i);
            }
        }
        else if(isMyTurn == 0)
        {
            isMyTurn = 1;
            if(usable)
            {
                int i = rand() % cards_A_0.count();
                scene->removeItem(cards_A_0[i]);
                adjustPos_A_0(cards_A_0[i]);
                pos_A_0.removeAt(i);
                cards_A_0.removeAt(i);
            }
        }
        usable = true;
        text_time->setPlainText(QString("%1").arg(seconds, 2, 10, QChar('0')));
        text_time->setDefaultTextColor(color2[isMyTurn]);
    }
}

bool BattleField::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == field)
    {
        if(pot_pass->rect().contains(QCursor::pos()))
        {
            if(isMyTurn == 1 && usable == true)
            {
                giveUpA = true;
                usable = false;
                seconds = 0;
            }
            else if(isMyTurn == 0 && usable == true)
            {
                giveUpB = true;
                usable = false;
                seconds = 0;
            }
        }
        else if(pot_A_1->rect().contains(QCursor::pos()))
        {
            useCard(pot_A_1);
            return true;
        }
        else if(pot_A_2->rect().contains(QCursor::pos()))
        {
            useCard(pot_A_2);
            return true;
        }
        else if(pot_A_3->rect().contains(QCursor::pos()))
        {
            useCard(pot_A_3);
            return true;
        }
        else if(pot_B_1->rect().contains(QCursor::pos()))
        {
            useCard(pot_B_1);
            return true;
        }
        else if(pot_B_2->rect().contains(QCursor::pos()))
        {
            useCard(pot_B_2);
            return true;
        }
        else if(pot_B_3->rect().contains(QCursor::pos()))
        {
            useCard(pot_B_3);
            return true;
        }
        else return false;
    }
    else return false;
}

void BattleField::readFile(QString address, int &leader_ID, QList<Card *> &deck)
{
    QFile file(address);
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning("Counldn't open the file");
        return;
    }

    QByteArray json = file.readAll();
    file.close();

    QJsonDocument jsDoc;
    jsDoc = QJsonDocument::fromJson(json);

    if(jsDoc.isObject())
    {
        QJsonObject object = jsDoc.object();

        if(object.contains("Leader"))
        {
            QJsonValue value_1 = object["Leader"];
            if(value_1.isDouble())
            {
                leader_ID = value_1.toInt();
            }
        }
        if(object.contains("Cards"))
        {
            QJsonValue value_2 = object["Cards"];
            if(value_2.isArray())
            {
                QJsonArray array = value_2.toArray();
                int nsize = array.size();
                for(int i = 0; i < nsize; i++)
                {
                    QJsonValue value_i = array.at(i);
                    if(value_i.isDouble())
                    {
                        int card_ID = value_i.toInt();
                        deck.append(new Card(card_ID, 0, 0, 0, 0, scene));
                    }
                }
            }
        }
    }
}

void BattleField::roundOne()
{
    round++;
    for(int i = 0; i < cardsSumNumber[round]; i++)
    {
        Card *newcard = new Card(cards_A_deck.first(), BATTLEFIELD_HAND_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_HAND_A_TOP*SCALE_FILED_WINDOW,
                                 CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, scene, pot_A_0);
        cards_A_deck.removeFirst();

        if(pos_A_0.empty())
        {
            newcard->setPos(0, 0);
        }
        else
        {
            newcard->setPos(pos_A_0.back().x() + CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, 0);
        }

        cards_A_0.append(newcard);
        pos_A_0.append(newcard->pos());

        connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
        connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
        connect(newcard, SIGNAL(c_isClicked(Card*)), this, SLOT(setChosenCard(Card*)));
        connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_A_0(QPointF&)));
    }
    changeCard();
}

void BattleField::roundOne2()
{
    for(int i = 0; i < cardsSumNumber[round]; i++)
    {
        Card *newcard = new Card(cards_B_deck.first(), BATTLEFIELD_HAND_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_HAND_B_TOP*SCALE_FILED_WINDOW,
                                 CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, scene, pot_B_0);
        cards_B_deck.removeFirst();

        if(pos_B_0.empty())
        {
            newcard->setPos(0, 0);
        }
        else
        {
            newcard->setPos(pos_B_0.back().x() + CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, 0);
        }

        cards_B_0.append(newcard);
        pos_B_0.append(newcard->pos());

        connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
        connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
        connect(newcard, SIGNAL(c_isClicked(Card*)), this, SLOT(setChosenCard(Card*)));
        connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_A_0(QPointF&)));
    }
    changeCard2();
}

void BattleField::changeCard()
{
    scene->addItem(pot_change);
    text_change->setPlainText(tr("你已经换牌%1/%2张").arg(changeTimes).arg(cardsNumber[round]));
    text_change->setDefaultTextColor(color2[isFirst]);
    scene->addItem(text_change);
    button->setVisible(true);
    int j = cards_A_0.count();
    for(int i = 0; i < j; i++)
    {
        Card *newcard = new Card(cards_A_0.first(), 0, 0,
                CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_CHANGE*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_CHANGE*SCALE_FILED_WINDOW, scene, pot_change);
        scene->removeItem(cards_A_0.first());
        adjustPos_B_0(cards_A_0.first());
        pos_A_0.removeFirst();
        cards_A_0.removeFirst();

        if(pos_change.empty())
        {
            newcard->setPos(0, BATTLEFIELD_CHANGE_TOP*SCALE_FILED_WINDOW);
        }
        else
        {
            newcard->setPos(pos_change.back().x() + CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_CHANGE*SCALE_FILED_WINDOW, BATTLEFIELD_CHANGE_TOP*SCALE_FILED_WINDOW);
        }

        cards_change.append(newcard);
        pos_change.append(newcard->pos());

        connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
        connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
        connect(newcard, SIGNAL(c_isClicked(Card*)), this, SLOT(changeACard(Card*)));
        connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_change(QPointF&)));
    }
}

void BattleField::changeCard2()
{
    changeTimes = 0;
    scene->addItem(pot_change);
    text_change->setPlainText(tr("你已经换牌%1/%2张").arg(changeTimes).arg(cardsNumber[round]));
    text_change->setDefaultTextColor(color2[isFirst]);
    scene->addItem(text_change);
    button->setVisible(true);
    int j = cards_B_0.count();
    for(int i = 0; i < j; i++)
    {
        Card *newcard = new Card(cards_B_0.first(), 0, 0,
                CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_CHANGE*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_CHANGE*SCALE_FILED_WINDOW, scene, pot_change);
        scene->removeItem(cards_B_0.first());
        //adjustPos_B_0(cards_B_0.first());
        pos_B_0.removeFirst();
        cards_B_0.removeFirst();

        if(pos_change.empty())
        {
            newcard->setPos(0, BATTLEFIELD_CHANGE_TOP*SCALE_FILED_WINDOW);
        }
        else
        {
            newcard->setPos(pos_change.back().x() + CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_CHANGE*SCALE_FILED_WINDOW, BATTLEFIELD_CHANGE_TOP*SCALE_FILED_WINDOW);
        }

        cards_change.append(newcard);
        pos_change.append(newcard->pos());

        connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
        connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
        connect(newcard, SIGNAL(c_isClicked(Card*)), this, SLOT(changeBCard(Card*)));
        connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_change(QPointF&)));
    }
}

void BattleField::changeACard(Card *card)
{
    if(changeTimes < cardsNumber[round])
    {
        cards_A_deck.append(card);
        Card *newcard = new Card(cards_A_deck.first(), 0, 0,
                                 CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_CHANGE*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_CHANGE*SCALE_FILED_WINDOW, scene, pot_change);
        cards_A_deck.removeFirst();

        int i = cards_change.indexOf(card);
        scene->removeItem(card);
        emit card->c_isNotHovered();
        cards_change.replace(i, newcard);
        cards_change.removeOne(card);
        newcard->setPos(pos_change[i]);

        connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
        connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
        connect(newcard, SIGNAL(c_isClicked(Card*)), this, SLOT(changeACard(Card*)));
        connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_change(QPointF&)));

        changeTimes++;
        text_change->setPlainText(tr("你已经换牌%1/%2张").arg(changeTimes).arg(cardsNumber[round]));
    }
}

void BattleField::changeBCard(Card *card)
{
    if(changeTimes < cardsNumber[round])
    {
        cards_B_deck.append(card);
        Card *newcard = new Card(cards_B_deck.first(), 0, 0,
                                 CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_CHANGE*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_CHANGE*SCALE_FILED_WINDOW, scene, pot_change);
        cards_B_deck.removeFirst();

        int i = cards_change.indexOf(card);
        scene->removeItem(card);
        emit card->c_isNotHovered();
        cards_change.replace(i, newcard);
        cards_change.removeOne(card);
        newcard->setPos(pos_change[i]);

        connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
        connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
        connect(newcard, SIGNAL(c_isClicked(Card*)), this, SLOT(changeBCard(Card*)));
        connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_change(QPointF&)));

        changeTimes++;
        text_change->setPlainText(tr("你已经换牌%1/%2张").arg(changeTimes).arg(cardsNumber[round]));
    }
}

void BattleField::cardChanged()
{
    button->setVisible(false);
    if(isFirst == 1)
    {
        isFirst = 0;
        cards_A_0.clear();
        pos_A_0.clear();
        int j = cards_change.count();
        for(int i = 0; i < j; i++)
        {
            Card *newcard = new Card(cards_change.first(), BATTLEFIELD_HAND_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_HAND_A_TOP*SCALE_FILED_WINDOW,
                                     CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, scene, pot_A_0);
            scene->removeItem(cards_change.first());
            cards_change.removeFirst();
            pos_change.removeFirst();

            if(pos_A_0.empty())
            {
                newcard->setPos(0, 0);
            }
            else
            {
                newcard->setPos(pos_A_0.back().x() + CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, 0);
            }

            cards_A_0.append(newcard);
            pos_A_0.append(newcard->pos());

            connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
            connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
            connect(newcard, SIGNAL(c_isClicked(Card*)), this, SLOT(setChosenCard(Card*)));
            connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_A_0(QPointF&)));
        }
        scene->removeItem(text_change);
        scene->removeItem(pot_change);
        roundOne2();
    }
    else if(isFirst == 0)
    {
        isFirst = 1;
        cards_B_0.clear();
        pos_B_0.clear();
        int j = cards_change.count();
        for(int i = 0; i < j; i++)
        {
            Card *newcard = new Card(cards_change.first(), BATTLEFIELD_HAND_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_HAND_B_TOP*SCALE_FILED_WINDOW,
                                     CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, scene, pot_B_0);
            scene->removeItem(cards_change.first());
            cards_change.removeFirst();
            pos_change.removeFirst();

            if(pos_B_0.empty())
            {
                newcard->setPos(0, 0);
            }
            else
            {
                newcard->setPos(pos_B_0.back().x() + CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW, 0);
            }

            cards_B_0.append(newcard);
            pos_B_0.append(newcard->pos());

            connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
            connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
            connect(newcard, SIGNAL(c_isClicked(Card*)), this, SLOT(setChosenCard(Card*)));
            connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_B_0(QPointF&)));
        }
        scene->removeItem(text_change);
        scene->removeItem(pot_change);

        timer->start(SECOND);
    }
}

void BattleField::powerUpdate()
{
    power_A_1 = 0;
    int j = cards_A_1.count();
    for(int i = 0; i < j; i++)
    {
        power_A_1 += cards_A_1[i]->c_power_current;
    }
    power_A_2 = 0;
    j = cards_A_2.count();
    for(int i = 0; i < j; i++)
    {
        power_A_2 += cards_A_2[i]->c_power_current;
    }
    power_A_3 = 0;
    j = cards_A_3.count();
    for(int i = 0; i < j; i++)
    {
        power_A_3 += cards_A_3[i]->c_power_current;
    }
    power_B_1 = 0;
    j = cards_B_1.count();
    for(int i = 0; i < j; i++)
    {
        power_B_1 += cards_B_1[i]->c_power_current;
    }
    power_B_2 = 0;
    j = cards_B_2.count();
    for(int i = 0; i < j; i++)
    {
        power_B_2 += cards_B_2[i]->c_power_current;
    }
    power_B_3 = 0;
    j = cards_B_3.count();
    for(int i = 0; i < j; i++)
    {
        power_B_3 += cards_B_3[i]->c_power_current;
    }
    power_A = power_A_1 + power_A_2 + power_A_3;
    power_B = power_B_1 + power_B_2 + power_B_3;
    text_A->setPlainText(QString::number(power_A));
    text_B->setPlainText(QString::number(power_B));
    text_A_1->setPlainText(QString::number(power_A_1));
    text_A_2->setPlainText(QString::number(power_A_2));
    text_A_3->setPlainText(QString::number(power_A_3));
    text_B_1->setPlainText(QString::number(power_B_1));
    text_B_2->setPlainText(QString::number(power_B_2));
    text_B_3->setPlainText(QString::number(power_B_3));
}

void BattleField::putInfo(Card *card)
{
    pixmap = new QGraphicsPixmapItem(card->c_pic_L);
    pixmap->setScale(SCALE_BATTLEFIELD_CARD_L_INFO*SCALE_FILED_WINDOW);
    pixmap->setPos(BATTLEFIELD_INFO_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_INFO_TOP*SCALE_FILED_WINDOW);
    text = new QGraphicsTextItem(card->c_description);
    text->setTextWidth((BATTLEFIELD_INFO_WIDTH*SCALE_FILED_WINDOW));
    text->setPos(BATTLEFIELD_INFO_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_INFO_TOP*SCALE_FILED_WINDOW + CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_INFO*SCALE_FILED_WINDOW);
    text->setDefaultTextColor(qRgb(255, 215, 0));
    QFont font;
    font.setPixelSize(FONT_S*SCALE_FILED_WINDOW);
    text->setFont(font);
    scene->addItem(pixmap);
    scene->addItem(text);
}

void BattleField::clearInfo()
{
    scene->removeItem(pixmap);
    scene->removeItem(text);
}

void BattleField::setChosenCard(Card *card)
{
    if(card->parentItem() == pot_A_0 && isMyTurn == 1)
    {
        chosenCard = new Card(card, 0, 0, CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, scene);
        chosenNum = cards_A_0.indexOf(card);
        chosen = true;
    }
    else if(card->parentItem() == pot_B_0 && isMyTurn == 0)
    {
        chosenCard = new Card(card, 0, 0, CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, scene);
        chosenNum = cards_B_0.indexOf(card);
        chosen = true;
    }
    else if(card == leader_A)
    {
        chosenCard = new Card(card, 0, 0, CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, scene);
        leaderA_chosen = true;
        chosen = true;
    }
    else if(card == leader_B)
    {
        chosenCard = new Card(card, 0, 0, CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, scene);
        leaderB_chosen = true;
        chosen = true;
    }
}

void BattleField::useCard(QGraphicsRectItem *pot)
{
    if(chosen == true && usable == true)
    {
        chosen = false;
        usable = false;
        if(pot == pot_A_1)
        {
            if(((chosenCard->c_position == A_1 || chosenCard->c_position == A || chosenCard->c_position == A_B) && isMyTurn == 1) ||
                    ((chosenCard->c_position == B_1 || chosenCard->c_position == B || chosenCard->c_position == A_B) && isMyTurn == 0))
            {
                Card *newcard = new Card(chosenCard, BATTLEFIELD_WAR_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_A_1_TOP*SCALE_FILED_WINDOW,
                                          CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, scene, pot_A_1);
                emit chosenCard->c_isNotHovered();
                if(leaderA_chosen)
                {
                    leaderA_chosen = false;
                    scene->removeItem(leader_A);
                }
                else if(leaderB_chosen)
                {
                    leaderB_chosen = false;
                    scene->removeItem(leader_B);
                }
                else if(isMyTurn == 1)
                {
                    adjustPos_A_0(cards_A_0.at(chosenNum));
                    scene->removeItem(cards_A_0.at(chosenNum));
                    pos_A_0.removeAt(chosenNum);
                    cards_A_0.removeAt(chosenNum);
                }
                else if(isMyTurn == 0)
                {
                    adjustPos_B_0(cards_B_0.at(chosenNum));
                    scene->removeItem(cards_B_0.at(chosenNum));
                    pos_B_0.removeAt(chosenNum);
                    cards_B_0.removeAt(chosenNum);
                }

                if(pos_A_1.empty())
                {
                    newcard->setPos(0, 0);
                }
                else
                {
                    newcard->setPos(pos_A_1.back().x() + CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, 0);
                }

                cards_A_1.append(newcard);
                pos_A_1.append(newcard->pos());
                seconds = 0;

                connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
                connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
                connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_A_1(QPointF&)));
            }
        }
        else if(pot == pot_A_2)
        {
            if(((chosenCard->c_position == A_2 || chosenCard->c_position == A || chosenCard->c_position == A_B) && isMyTurn == 1) ||
                    ((chosenCard->c_position == B_2 || chosenCard->c_position == B || chosenCard->c_position == A_B) && isMyTurn == 0))
            {
                Card *newcard = new Card(chosenCard, BATTLEFIELD_WAR_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_A_2_TOP*SCALE_FILED_WINDOW,
                                          CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, scene, pot_A_2);
                emit chosenCard->c_isNotHovered();
                if(leaderA_chosen)
                {
                    leaderA_chosen = false;
                    scene->removeItem(leader_A);
                }
                else if(leaderB_chosen)
                {
                    leaderB_chosen = false;
                    scene->removeItem(leader_B);
                }
                else if(isMyTurn == 1)
                {
                    adjustPos_A_0(cards_A_0.at(chosenNum));
                    scene->removeItem(cards_A_0.at(chosenNum));
                    pos_A_0.removeAt(chosenNum);
                    cards_A_0.removeAt(chosenNum);
                }
                else if(isMyTurn == 0)
                {
                    adjustPos_B_0(cards_B_0.at(chosenNum));
                    scene->removeItem(cards_B_0.at(chosenNum));
                    pos_B_0.removeAt(chosenNum);
                    cards_B_0.removeAt(chosenNum);
                }

                if(pos_A_2.empty())
                {
                    newcard->setPos(0, 0);
                }
                else
                {
                    newcard->setPos(pos_A_2.back().x() + CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, 0);
                }

                cards_A_2.append(newcard);
                pos_A_2.append(newcard->pos());
                seconds = 0;

                connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
                connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
                connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_A_2(QPointF&)));
            }
        }
        else if(pot == pot_A_3)
        {
            if(((chosenCard->c_position == A_3 || chosenCard->c_position == A || chosenCard->c_position == A_B) && isMyTurn == 1) ||
                    ((chosenCard->c_position == B_3 || chosenCard->c_position == B || chosenCard->c_position == A_B) && isMyTurn == 0))
            {
                Card *newcard = new Card(chosenCard, BATTLEFIELD_WAR_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_A_3_TOP*SCALE_FILED_WINDOW,
                                          CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, scene, pot_A_3);
                emit chosenCard->c_isNotHovered();
                if(leaderA_chosen)
                {
                    leaderA_chosen = false;
                    scene->removeItem(leader_A);
                }
                else if(leaderB_chosen)
                {
                    leaderB_chosen = false;
                    scene->removeItem(leader_B);
                }
                else if(isMyTurn == 1)
                {
                    adjustPos_A_0(cards_A_0.at(chosenNum));
                    scene->removeItem(cards_A_0.at(chosenNum));
                    pos_A_0.removeAt(chosenNum);
                    cards_A_0.removeAt(chosenNum);
                }
                else if(isMyTurn == 0)
                {
                    adjustPos_B_0(cards_B_0.at(chosenNum));
                    scene->removeItem(cards_B_0.at(chosenNum));
                    pos_B_0.removeAt(chosenNum);
                    cards_B_0.removeAt(chosenNum);
                }

                if(pos_A_3.empty())
                {
                    newcard->setPos(0, 0);
                }
                else
                {
                    newcard->setPos(pos_A_3.back().x() + CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, 0);
                }

                cards_A_3.append(newcard);
                pos_A_3.append(newcard->pos());
                seconds = 0;

                connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
                connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
                connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_A_3(QPointF&)));
            }
        }
        else if(pot == pot_B_1)
        {
            if(((chosenCard->c_position == A_3 || chosenCard->c_position == A || chosenCard->c_position == A_B) && isMyTurn == 0) ||
                    ((chosenCard->c_position == B_3 || chosenCard->c_position == B || chosenCard->c_position == A_B) && isMyTurn == 1))
            {
                Card *newcard = new Card(chosenCard, BATTLEFIELD_WAR_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_B_1_TOP*SCALE_FILED_WINDOW,
                                          CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, scene, pot_B_1);
                emit chosenCard->c_isNotHovered();
                if(leaderA_chosen)
                {
                    leaderA_chosen = false;
                    scene->removeItem(leader_A);
                }
                else if(leaderB_chosen)
                {
                    leaderB_chosen = false;
                    scene->removeItem(leader_B);
                }
                else if(isMyTurn == 1)
                {
                    adjustPos_A_0(cards_A_0.at(chosenNum));
                    scene->removeItem(cards_A_0.at(chosenNum));
                    pos_A_0.removeAt(chosenNum);
                    cards_A_0.removeAt(chosenNum);
                }
                else if(isMyTurn == 0)
                {
                    adjustPos_B_0(cards_B_0.at(chosenNum));
                    scene->removeItem(cards_B_0.at(chosenNum));
                    pos_B_0.removeAt(chosenNum);
                    cards_B_0.removeAt(chosenNum);
                }

                if(pos_B_1.empty())
                {
                    newcard->setPos(0, 0);
                }
                else
                {
                    newcard->setPos(pos_B_1.back().x() + CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, 0);
                }

                cards_B_1.append(newcard);
                pos_B_1.append(newcard->pos());
                seconds = 0;

                connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
                connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
                connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_B_1(QPointF&)));
            }
        }
        else if(pot == pot_B_2)
        {
            if(((chosenCard->c_position == A_2 || chosenCard->c_position == A || chosenCard->c_position == A_B) && isMyTurn == 0) ||
                    ((chosenCard->c_position == B_2 || chosenCard->c_position == B || chosenCard->c_position == A_B) && isMyTurn == 1))
            {
                Card *newcard = new Card(chosenCard, BATTLEFIELD_WAR_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_B_2_TOP*SCALE_FILED_WINDOW,
                                          CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, scene, pot_B_2);
                emit chosenCard->c_isNotHovered();
                if(leaderA_chosen)
                {
                    leaderA_chosen = false;
                    scene->removeItem(leader_A);
                }
                else if(leaderB_chosen)
                {
                    leaderB_chosen = false;
                    scene->removeItem(leader_B);
                }
                else if(isMyTurn == 1)
                {
                    adjustPos_A_0(cards_A_0.at(chosenNum));
                    scene->removeItem(cards_A_0.at(chosenNum));
                    pos_A_0.removeAt(chosenNum);
                    cards_A_0.removeAt(chosenNum);
                }
                else if(isMyTurn == 0)
                {
                    adjustPos_B_0(cards_B_0.at(chosenNum));
                    scene->removeItem(cards_B_0.at(chosenNum));
                    pos_B_0.removeAt(chosenNum);
                    cards_B_0.removeAt(chosenNum);
                }

                if(pos_B_2.empty())
                {
                    newcard->setPos(0, 0);
                }
                else
                {
                    newcard->setPos(pos_B_2.back().x() + CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, 0);
                }

                cards_B_2.append(newcard);
                pos_B_2.append(newcard->pos());
                seconds = 0;

                connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
                connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
                connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_B_2(QPointF&)));
            }
        }
        else if(pot == pot_B_3)
        {
            if(((chosenCard->c_position == A_3 || chosenCard->c_position == A || chosenCard->c_position == A_B) && isMyTurn == 0) ||
                    ((chosenCard->c_position == B_3 || chosenCard->c_position == B || chosenCard->c_position == A_B) && isMyTurn == 1))
            {
                Card *newcard = new Card(chosenCard, BATTLEFIELD_WAR_LEFT*SCALE_FILED_WINDOW, BATTLEFIELD_WAR_B_3_TOP*SCALE_FILED_WINDOW,
                                          CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, CARD_L_HEIGHT*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, scene, pot_B_3);
                emit chosenCard->c_isNotHovered();
                if(leaderA_chosen)
                {
                    leaderA_chosen = false;
                    scene->removeItem(leader_A);
                }
                else if(leaderB_chosen)
                {
                    leaderB_chosen = false;
                    scene->removeItem(leader_B);
                }
                else if(isMyTurn == 1)
                {
                    adjustPos_A_0(cards_A_0.at(chosenNum));
                    scene->removeItem(cards_A_0.at(chosenNum));
                    pos_A_0.removeAt(chosenNum);
                    cards_A_0.removeAt(chosenNum);
                }
                else if(isMyTurn == 0)
                {
                    adjustPos_B_0(cards_B_0.at(chosenNum));
                    scene->removeItem(cards_B_0.at(chosenNum));
                    pos_B_0.removeAt(chosenNum);
                    cards_B_0.removeAt(chosenNum);
                }

                if(pos_B_3.empty())
                {
                    newcard->setPos(0, 0);
                }
                else
                {
                    newcard->setPos(pos_B_3.back().x() + CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW, 0);
                }

                cards_B_3.append(newcard);
                pos_B_3.append(newcard->pos());
                seconds = 0;

                connect(newcard, SIGNAL(c_isHovered(Card*)), this, SLOT(putInfo(Card*)));
                connect(newcard, SIGNAL(c_isNotHovered()), this, SLOT(clearInfo()));
                connect(newcard, SIGNAL(c_isMoving(QPointF&)), this, SLOT(posAdjust_B_3(QPointF&)));
            }
        }
        else
        {
            chosen = true;
            usable = true;
        }
        powerUpdate();
    }
}

void BattleField::posAdjust_A_0(QPointF &pos)
{
    if((pos_A_0[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_A_0[cards_A_0.count()-1].x() + pos.x() >= BATTLEFIELD_HAND_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_A_0.count();
        for (int i = 0; i < j; i++)
        {
            pos_A_0[i].setX(pos_A_0[i].x() + pos.x());
            cards_A_0[i]->setPos(pos_A_0[i]);
        }
    }
}

void BattleField::posAdjust_A_1(QPointF &pos)
{
    if((pos_A_1[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_A_1[cards_A_1.count()-1].x() + pos.x() >= BATTLEFIELD_WAR_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_A_1.count();
        for (int i = 0; i < j; i++)
        {
            pos_A_1[i].setX(pos_A_1[i].x() + pos.x());
            cards_A_1[i]->setPos(pos_A_1[i]);
        }
    }
}

void BattleField::posAdjust_A_2(QPointF &pos)
{
    if((pos_A_2[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_A_2[cards_A_2.count()-1].x() + pos.x() >= BATTLEFIELD_WAR_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_A_2.count();
        for (int i = 0; i < j; i++)
        {
            pos_A_2[i].setX(pos_A_2[i].x() + pos.x());
            cards_A_2[i]->setPos(pos_A_2[i]);
        }
    }
}

void BattleField::posAdjust_A_3(QPointF &pos)
{
    if((pos_A_3[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_A_3[cards_A_3.count()-1].x() + pos.x() >= BATTLEFIELD_WAR_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_A_3.count();
        for (int i = 0; i < j; i++)
        {
            pos_A_3[i].setX(pos_A_3[i].x() + pos.x());
            cards_A_3[i]->setPos(pos_A_3[i]);
        }
    }
}

void BattleField::posAdjust_B_0(QPointF &pos)
{
    if((pos_B_0[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_B_0[cards_B_0.count()-1].x() + pos.x() >= BATTLEFIELD_HAND_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_B_0.count();
        for (int i = 0; i < j; i++)
        {
            pos_B_0[i].setX(pos_B_0[i].x() + pos.x());
            cards_B_0[i]->setPos(pos_B_0[i]);
        }
    }
}

void BattleField::posAdjust_B_1(QPointF &pos)
{
    if((pos_B_1[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_B_1[cards_B_1.count()-1].x() + pos.x() >= BATTLEFIELD_WAR_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_B_1.count();
        for (int i = 0; i < j; i++)
        {
            pos_B_1[i].setX(pos_B_1[i].x() + pos.x());
            cards_B_1[i]->setPos(pos_B_1[i]);
        }
    }
}

void BattleField::posAdjust_B_2(QPointF &pos)
{
    if((pos_B_2[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_B_2[cards_B_2.count()-1].x() + pos.x() >= BATTLEFIELD_WAR_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_B_2.count();
        for (int i = 0; i < j; i++)
        {
            pos_B_2[i].setX(pos_B_2[i].x() + pos.x());
            cards_B_2[i]->setPos(pos_B_2[i]);
        }
    }
}

void BattleField::posAdjust_B_3(QPointF &pos)
{
    if((pos_B_3[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_B_3[cards_B_3.count()-1].x() + pos.x() >= BATTLEFIELD_WAR_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_B_3.count();
        for (int i = 0; i < j; i++)
        {
            pos_B_3[i].setX(pos_B_3[i].x() + pos.x());
            cards_B_3[i]->setPos(pos_B_3[i]);
        }
    }
}

void BattleField::posAdjust_change(QPointF &pos)
{
    if((pos_change[0].x() + pos.x() <= 0 && pos.x() > 0)
       || (pos_change[cards_change.count()-1].x() + pos.x() >= BATTLEFIELD_CHANGE_WIDTH*SCALE_FILED_WINDOW - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_CHANGE*SCALE_FILED_WINDOW && pos.x() < 0))
    {
        int j = cards_change.count();
        for (int i = 0; i < j; i++)
        {
            pos_change[i].setX(pos_change[i].x() + pos.x());
            cards_change[i]->setPos(pos_change[i]);
        }
    }
}

void BattleField::adjustPos_A_0(Card * card)
{
    int j = pos_A_0.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_A_0[i].x() > card->pos().x())
        {
            pos_A_0[i].setX(pos_A_0[i].x() - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW);
            cards_A_0[i]->setPos(pos_A_0[i]);
        }
    }
}

void BattleField::adjustPos_A_1(Card * card)
{
    int j = pos_A_1.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_A_1[i].x() > card->pos().x())
        {
            pos_A_1[i].setX(pos_A_1[i].x() - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW);
            cards_A_1[i]->setPos(pos_A_1[i]);
        }
    }
}

void BattleField::adjustPos_A_2(Card * card)
{
    int j = pos_A_2.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_A_2[i].x() > card->pos().x())
        {
            pos_A_2[i].setX(pos_A_2[i].x() - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW);
            cards_A_2[i]->setPos(pos_A_2[i]);
        }
    }
}

void BattleField::adjustPos_A_3(Card * card)
{
    int j = pos_A_3.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_A_3[i].x() > card->pos().x())
        {
            pos_A_3[i].setX(pos_A_3[i].x() - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW);
            cards_A_3[i]->setPos(pos_A_3[i]);
        }
    }
}

void BattleField::adjustPos_B_0(Card * card)
{
    int j = pos_B_0.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_B_0[i].x() > card->pos().x())
        {
            pos_B_0[i].setX(pos_B_0[i].x() - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_IN*SCALE_FILED_WINDOW);
            cards_B_0[i]->setPos(pos_B_0[i]);
        }
    }
}

void BattleField::adjustPos_B_1(Card * card)
{
    int j = pos_B_1.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_B_1[i].x() > card->pos().x())
        {
            pos_B_1[i].setX(pos_B_1[i].x() - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW);
            cards_B_1[i]->setPos(pos_B_1[i]);
        }
    }
}

void BattleField::adjustPos_B_2(Card * card)
{
    int j = pos_B_2.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_B_2[i].x() > card->pos().x())
        {
            pos_B_2[i].setX(pos_B_2[i].x() - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW);
            cards_B_2[i]->setPos(pos_B_2[i]);
        }
    }
}

void BattleField::adjustPos_B_3(Card * card)
{
    int j = pos_B_3.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_B_3[i].x() > card->pos().x())
        {
            pos_B_3[i].setX(pos_B_3[i].x() - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW);
            cards_B_3[i]->setPos(pos_B_3[i]);
        }
    }
}

void BattleField::adjustPos_change(Card * card)
{
    int j = pos_change.count();
    for(int i = 0; i < j; i++)
    {
        if(pos_change[i].x() > card->pos().x())
        {
            pos_change[i].setX(pos_change[i].x() - CARD_L_WIDTH*SCALE_BATTLEFIELD_CARD_L_ON*SCALE_FILED_WINDOW);
            cards_change[i]->setPos(pos_change[i]);
        }
    }
}
