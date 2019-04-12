#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "card.h"
#include "field.h"
#include "cardslaundry.h"
#include "scorefield.h"
#include <QMainWindow>
#include <QTimer>

class BattleField : public QMainWindow
{
    Q_OBJECT
public:
    explicit BattleField(QString address1, QString address2, QWidget *parent = nullptr);

    void readFile(QString address, int &leader_ID, QList<Card*> &deck);
    void roundOne();
    void roundOne2();
    void changeCard();
    void changeCard2();

    bool eventFilter(QObject *watched, QEvent *event);

    void adjustPos_A_0(Card *card);
    void adjustPos_A_1(Card *card);
    void adjustPos_A_2(Card *card);
    void adjustPos_A_3(Card *card);
    void adjustPos_B_0(Card *card);
    void adjustPos_B_1(Card *card);
    void adjustPos_B_2(Card *card);
    void adjustPos_B_3(Card *card);
    void adjustPos_change(Card *card);

public:
    QList<Card*> cards_A_0, cards_A_3, cards_A_2, cards_A_1, cards_B_1, cards_B_2, cards_B_3, cards_B_0, cards_A_deck, cards_B_deck, cards_A_cemetery, cards_B_cemetery, cards_change;
    Card *leader_A, *leader_B, *chosenCard;
    int leader_A_ID, leader_B_ID;
    QList<QPointF> pos_A_0, pos_A_3, pos_A_2, pos_A_1, pos_B_1, pos_B_2, pos_B_3, pos_B_0, pos_change;
    QGraphicsRectItem *pot_A_0, *pot_A_3, *pot_A_2, *pot_A_1, *pot_B_1, *pot_B_2, *pot_B_3, *pot_B_0, *pot_change, *pot_pass;
    QGraphicsPixmapItem *pixmap, *deck_A, *deck_B;
    QGraphicsTextItem *text, *text_A, *text_A_1, *text_A_2, *text_A_3, *text_B_3, *text_B_2, *text_B_1, *text_B, *text_time, *text_change;
    Field *field;
    QGraphicsScene *scene;
    QGraphicsView *view;
    int power_A, power_A_1, power_A_2, power_A_3, power_B_3, power_B_2, power_B_1, power_B;
    bool chosen, usable, giveUpA, giveUpB, leaderA_chosen, leaderB_chosen;
    cardslaundry *laundry;
    QTimer *timer;
    int seconds, isMyTurn, changeTimes, round, chosenNum, isFirst, AWin, BWin;
    QColor color2[2];
    int cardsNumber[4], cardsSumNumber[4], score[6];
    QPushButton *button;
    QString m_address1, m_address2;
    scorefield *score_field;

signals:
    void isclicked(QGraphicsRectItem *pot);

public slots:
    void powerUpdate();
    void timerUpdate();

    void putInfo(Card *card);
    void clearInfo();

    void setChosenCard(Card *card);
    void useCard(QGraphicsRectItem *pot);
    void changeACard(Card *card);
    void changeBCard(Card *card);
    void cardChanged();

    void posAdjust_A_0(QPointF &pos);
    void posAdjust_A_1(QPointF &pos);
    void posAdjust_A_2(QPointF &pos);
    void posAdjust_A_3(QPointF &pos);
    void posAdjust_B_0(QPointF &pos);
    void posAdjust_B_1(QPointF &pos);
    void posAdjust_B_2(QPointF &pos);
    void posAdjust_B_3(QPointF &pos);
    void posAdjust_change(QPointF &pos);
};
#endif // BATTLEFIELD_H
