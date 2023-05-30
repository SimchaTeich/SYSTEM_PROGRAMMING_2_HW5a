#ifndef ASCENDINGITERATOR_HPP
#define ASCENDINGITERATOR_HPP

#include "MagicalContainer.hpp"

using namespace ariel;

class MagicalContainer::AscendingIterator
{
private:
    MagicalContainer& _container;
    MisticalElementNode *_pElement;
    int _stepsNo;
    
public:
    AscendingIterator(MagicalContainer& container);
    //AscendingIterator(AscendingIterator& other);
    //~AscendingIterator();

    // operatores
    AscendingIterator& operator++(); // pre
    int operator*();
    bool operator!=(const AscendingIterator& other);

    AscendingIterator begin();
    AscendingIterator end();
};

#endif // !ASCENDINGITERATOR_HPP