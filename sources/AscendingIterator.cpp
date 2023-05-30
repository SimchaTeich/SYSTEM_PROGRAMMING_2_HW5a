#include "AscendingIterator.hpp"


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
    : _container(container)
{
    _stepsNo = 0;
    _pElement = nullptr;
};


MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    if(_pElement != nullptr)
    {
        _pElement = _pElement->getAscNext();
        _stepsNo++;
    }

    return *this;
};


int MagicalContainer::AscendingIterator::operator*()
{
    if(_pElement == nullptr) throw "Ilegal iterator";

    return _pElement->value();
};


bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator& other)
{
    return _pElement != other._pElement;
};


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    MagicalContainer::AscendingIterator newIterator(_container);
    newIterator._pElement = _container._head;

    return newIterator;
};


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    MagicalContainer::AscendingIterator newIterator(_container);

    return newIterator;
};
