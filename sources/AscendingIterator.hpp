#ifndef ASCENDINGITERATOR_HPP
#define ASCENDINGITERATOR_HPP

#include "MagicalContainer.hpp"

using namespace ariel;

class MagicalContainer::AscendingIterator
{
private:
    MagicalContainer& _container;
    MisticalElementNode *_pElement;
    int stepsNo;
    
public:
    AscendingIterator(MagicalContainer& container);
    AscendingIterator(AscendingIterator& other);
    ~AscendingIterator();

    // operatores
    friend AscendingIterator& operator++(AscendingIterator& iterator); // pre
    friend int operator*(AscendingIterator& iterator);

    AscendingIterator begin();
    AscendingIterator end();
};

#endif // !ASCENDINGITERATOR_HPP