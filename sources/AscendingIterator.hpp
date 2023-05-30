#ifndef ASCENDINGITERATOR_HPP
#define ASCENDINGITERATOR_HPP

#include "MagicalContainer.hpp"

using namespace ariel;

class MagicalContainer::AscendingIterator
{
private:
    int step;
    int *pelement;
    
public:
    AscendingIterator(MagicalContainer &container);
};

#endif // !ASCENDINGITERATOR_HPP