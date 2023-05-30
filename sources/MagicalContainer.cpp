#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::MagicalContainer()
{
    _size = 0;
    _primeSize = 0;
    _head = nullptr;
    _tail = nullptr;
    _primeHead = nullptr;
};


void MagicalContainer::addElement(int value)
{
    MisticalElementNode *pNewNode = new MisticalElementNode(value);
    insertNode(pNewNode, _head);
    _size++;

    if(isPrime(value))
    {
        insertNode(pNewNode, _primeHead);
        _primeSize++;
    }
}


bool MagicalContainer::isPrime(int num) const
{
    if (num <= 1) return false;

    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0) return false;
    }

    return true;
};


