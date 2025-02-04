#include "deckstack.h"

/*
#include "controll.h"
extern Controll * game;
*/

DeckStack::DeckStack(int max)
{
    cardArray = new Naipe*[max];
    showingCard = -1;
    topCard = -1;
    size = 0;
    this->max = max;
    this->posX = 0;
    this->posY = 0;
}

void DeckStack::push(Naipe *naipe)
{
    cardArray[size] = naipe;
    topCard = size;
    size ++;
}

Naipe *DeckStack::pop()
{
    Naipe *tmp = cardArray[size - 1];
    cardArray[size - 1] = NULL;
    size --;
    return tmp;
}

Naipe *DeckStack::topValue()
{
    return cardArray[topCard];
}

int DeckStack::getSize() const
{
    return size;
}

/*
void DeckStack::showTopCard()
{
    game->showTopDiscardPile(cardArray[topCard]);
}
*/

void DeckStack::setPos(int x, int y)
{
    this->posX = x;
    this->posY = y;
}

void DeckStack::shuffle()
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        swap(i, rand() % size);
    }
}

bool DeckStack::isEmpty()
{
    return size==0;
}

void DeckStack::refillDeck(DeckStack *decktoFillFrom)
{
    for (int i = 0 ; i<decktoFillFrom->getSize()-1 ; i++ ){
        this->push(decktoFillFrom->pop());
    }
    this->shuffle();
}

void DeckStack::swap(int pos1, int pos2)
{
    Naipe* tmp = cardArray[pos1];
    cardArray[pos1] = cardArray[pos2];
    cardArray[pos2] = tmp;
}

int DeckStack::getPosX() const
{
    return posX;
}

int DeckStack::getPosY() const
{
    return posY;
}
