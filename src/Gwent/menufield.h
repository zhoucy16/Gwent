#ifndef MENUFIELD_H
#define MENUFIELD_H

#include "field.h"
#include "selectscene.h"
#include "battlefield.h"
#include <QMainWindow>

class menufield : public QMainWindow
{
    Q_OBJECT
public:
    explicit menufield(QWidget *parent = nullptr);

public:
    Field *field;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPushButton *btn_game, *btn_deck_A, *btn_deck_B, *btn_exit;
    SelectScene *select;
    BattleField *battle;

signals:

public slots:
    void createSelectA();
    void createSelectB();
    void createBattle();
    void btnMoveOut1();
    void btnMoveOut2();
    void btnMoveOut3();
    void btnMoveOut4();
};

#endif // MENUFIELD_H
