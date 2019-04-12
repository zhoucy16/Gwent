#ifndef SCOREFIELD_H
#define SCOREFIELD_H

#include "field.h"
#include <QMainWindow>

class scorefield : public QMainWindow
{
    Q_OBJECT
public:
    explicit scorefield(QString str, int *score, QWidget *parent = nullptr);

public:
    Field *field;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsTextItem *text1, *text2, *text3, *text4, *text5, *text6, *text;
    QPushButton *button;

signals:

public slots:
};

#endif // SCOREFIELD_H
