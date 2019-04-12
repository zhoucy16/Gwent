#ifndef SELECTSCENE_H
#define SELECTSCENE_H

#include "card.h"
#include "field.h"
#include <QMainWindow>

class SelectScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit SelectScene(QString address, QWidget *parent = nullptr);

    void setLeader(Card *card);

public:
    QList<Card*> cards_5, cards_1, cards_2, cards_3, cards_4, cards_deck;
    Card *leader;
    QList<QPointF> pos_5, pos_1, pos_2, pos_3, pos_4;
    QGraphicsRectItem *pot_5, *pot_1, *pot_2, *pot_3, *pot_4;
    QGraphicsPixmapItem *pixmap;
    QGraphicsTextItem *text, *text_sum, *text_sum_2;
    Field *field;
    QGraphicsScene *scene;
    QGraphicsView *view;
    int each[SUM], color[4];
    int sum;
    bool leaderset;
    QString m_address;

signals:
    void sumChanged();

public slots:
    void putInfo(Card *card);
    void clearInfo();

    void posAdjust(QPointF &pos);
    void posAdjust1(QPointF &pos);
    void posAdjust4(QPointF &pos);
    void posAdjust2(QPointF &pos);
    void posAdjust3(QPointF &pos);

    void chooseCard(Card *card);
    void cancelCard4(Card *card);
    void cancelCard3(Card *card);
    void cancelCard2(Card *card);
    void cancelCard1(Card *card);

    void changeSum();
    void addDeck();
};

#endif // SELECTSCENE_H
