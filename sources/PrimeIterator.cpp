#include "MagicalContainer.hpp"

using namespace ariel;


MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
    : _container(container)
{
    _stepsNo = 0;
    _pElement = nullptr;
};


MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{
    if(_pElement != nullptr)
    {
        _pElement = _pElement->getPrimeNext();
        _stepsNo++;
    }

    return *this;
};


int MagicalContainer::PrimeIterator::operator*()
{
    if(_pElement == nullptr) throw "Ilegal iterator";

    return _pElement->value();
};


bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other)
{
    return _pElement != other._pElement;
};


bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other)
{
    return !(*this == other);
};


bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other)
{
    return _stepsNo > other._stepsNo;
};


bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other)
{
    return _stepsNo < other._stepsNo;
};


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    PrimeIterator newIterator(_container);
    newIterator._pElement = _container._primeHead;

    return newIterator;
};


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    return PrimeIterator(_container);
};
