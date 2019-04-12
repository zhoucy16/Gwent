#include "scorefield.h"

scorefield::scorefield(QString str, int *score, QWidget *parent) : QMainWindow(parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, FIELD_WIDTH*SCALE_FILED_WINDOW, FIELD_HEIGHT*SCALE_FILED_WINDOW);

    field = new Field(address_scorefield, scene);
    scene->addItem(field);

    QColor color(255, 255, 255);
    QFont font;
    font.setPixelSize(FONT_L*SCALE_FILED_WINDOW);

    text1 = new QGraphicsTextItem(QString::number(score[0]));
    text1->setPos(SCORE_1_LEFT*SCALE_FILED_WINDOW, SCORE_1_TOP*SCALE_FILED_WINDOW);
    text1->setDefaultTextColor(color);
    text1->setFont(font);
    text2 = new QGraphicsTextItem(QString::number(score[1]));
    text2->setPos(SCORE_2_LEFT*SCALE_FILED_WINDOW, SCORE_1_TOP*SCALE_FILED_WINDOW);
    text2->setDefaultTextColor(color);
    text2->setFont(font);
    text3 = new QGraphicsTextItem(QString::number(score[2]));
    text3->setPos(SCORE_1_LEFT*SCALE_FILED_WINDOW, SCORE_2_TOP*SCALE_FILED_WINDOW);
    text3->setDefaultTextColor(color);
    text3->setFont(font);
    text4 = new QGraphicsTextItem(QString::number(score[3]));
    text4->setPos(SCORE_2_LEFT*SCALE_FILED_WINDOW, SCORE_2_TOP*SCALE_FILED_WINDOW);
    text4->setDefaultTextColor(color);
    text4->setFont(font);
    text5 = new QGraphicsTextItem(QString::number(score[4]));
    text5->setPos(SCORE_1_LEFT*SCALE_FILED_WINDOW, SCORE_3_TOP*SCALE_FILED_WINDOW);
    text5->setDefaultTextColor(color);
    text5->setFont(font);
    text6 = new QGraphicsTextItem(QString::number(score[5]));
    text6->setPos(SCORE_2_LEFT*SCALE_FILED_WINDOW, SCORE_3_TOP*SCALE_FILED_WINDOW);
    text6->setDefaultTextColor(color);
    text6->setFont(font);
    text = new QGraphicsTextItem(str);
    text->setPos(SCORE_0_LEFT*SCALE_FILED_WINDOW, SCORE_0_TOP*SCALE_FILED_WINDOW);
    text->setDefaultTextColor(color);
    text->setFont(font);

    scene->addItem(text1);
    scene->addItem(text2);
    scene->addItem(text3);
    scene->addItem(text4);
    scene->addItem(text5);
    scene->addItem(text6);
    scene->addItem(text);

    button = new QPushButton(parent);
    button->setGeometry(SCORE_BUTTON_LEFT*SCALE_FILED_WINDOW, SCORE_BUTTON_TOP*SCALE_FILED_WINDOW,
                        ICON_WIDTH*SCALE_SELECTFIELD_ICON*SCALE_FILED_WINDOW, ICON_HEIGHT*SCALE_SELECTFIELD_ICON*SCALE_FILED_WINDOW);
    button->setStyleSheet("QPushButton{border-image:url(:/new/cards/field/confirm.png);" "border:2px 2px 2px 2px;}");
    scene->addWidget(button);

    view = new QGraphicsView(scene);
    view->resize(FIELD_WIDTH*SCALE_FILED_WINDOW, FIELD_HEIGHT*SCALE_FILED_WINDOW);
    view->show();

    connect(button, SIGNAL(clicked(bool)), view, SLOT(close()));
}
