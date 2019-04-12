#include "cardslaundry.h"

cardslaundry::cardslaundry()
{

}

void cardslaundry::swapcards(QList<Card *> &deck)
{
    srand(clock());
    int i, j;
    for(i = deck.count() - 1; i >= 0; i--)
    {
        j = rand() % (i + 1);
        deck.swap(i, j);
    }
}
