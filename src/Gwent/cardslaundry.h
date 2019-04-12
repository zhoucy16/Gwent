#ifndef CARDSLAUNDRY_H
#define CARDSLAUNDRY_H

#include "card.h"

class cardslaundry
{
public:
    cardslaundry();

public:
    void swapcards(QList<Card*> &deck);
};

#endif // CARDSLAUNDRY_H
