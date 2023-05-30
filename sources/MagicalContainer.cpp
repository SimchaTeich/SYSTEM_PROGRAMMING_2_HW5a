#include "MagicalContainer.hpp"
#include <iostream>

using std::cout;
using std::endl;

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
    insertNode_asc(pNewNode);
    _size++;

    if(isPrime(value))
    {
        insertNode_prime(pNewNode);
        _primeSize++;
    }
};


void MagicalContainer::removeElement(int value)
{
    // removeNode_asc(value);
    // _size--;

    // if(isPrime(value))
    // {
    //     removeNode_asc(value);
    //     _primeSize--;
    // }
};


int MagicalContainer::size() const
{
    return _size;
}


void MagicalContainer::insertNode_asc(MisticalElementNode *pNode)
{
    // for first node
    if(_head == nullptr)
    {
        _head = pNode;
        _tail = pNode;

        return;
    }

    // in case we need to change the head:
    if(pNode->value() < _head->value())
    {
        // update pointers
        pNode->setAscNext(_head);
        _head->setAscBack(pNode);


        // replace the head
        _head = pNode;
        
        return;
    }

    // all other cases: find the node will be before new node.
    MisticalElementNode *pCurr = _head;
    while(pCurr->getAscNext() && pCurr->getAscNext()->value() < pNode->value())
    {
        pCurr = pCurr->getAscNext();
    }

    // 2 options here: 'middle' or after tail..
    if(pCurr->getAscNext() == nullptr)                   // tail case
    {
        // update pointers
        pNode->setAscBack(pCurr);
        pCurr->setAscNext(pNode);

        // replace the tail
        _tail = pNode;
    }
    else                                                 // 'middle' case
    {
        // update pointers of new Node
        pNode->setAscBack(pCurr);
        pNode->setAscNext(pCurr->getAscNext());

        // updates pointers of two nodes we disconnect them
        pCurr->setAscNext(pNode);
        pNode->getAscNext()->setAscBack(pNode);
    }
}


void MagicalContainer::insertNode_prime(MisticalElementNode *pNode)
{
    // for first prime node
    if(_primeHead == nullptr)
    {
        _primeHead = pNode;
        _primeTail = pNode;

        return;
    }

    // in case we need to change the head of primes:
    if(pNode->value() < _primeHead->value())
    {
        // update pointers
        pNode->setPrimeNext(_primeHead);
        _primeHead->setPrimeBack(pNode);


        // replace the head of primes
        _primeHead = pNode;
        
        return;
    }

    // all other cases: find the node will be before new node.
    MisticalElementNode *pCurr = _primeHead;
    while(pCurr->getPrimeNext() && pCurr->getPrimeNext()->value() < pNode->value())
    {
        pCurr = pCurr->getPrimeNext();
    }

    // 2 options here: 'middle' or after tail of primes
    if(pCurr->getPrimeNext() == nullptr)                   // prime-tail case
    {
        // update pointers
        pNode->setPrimeBack(pCurr);
        pCurr->setPrimeNext(pNode);

        // replace the tail
        _primeTail = pNode;
    }
    else                                                 // 'middle' case
    {
        // update pointers of new Node
        pNode->setPrimeBack(pCurr);
        pNode->setPrimeNext(pCurr->getPrimeNext());

        // updates pointers of two nodes we disconnect them
        pCurr->setPrimeNext(pNode);
        pNode->getPrimeNext()->setPrimeBack(pNode);
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


void MagicalContainer::printLinkedListAscNext() const
{
    MisticalElementNode *pCurr = _head;

    while(pCurr)
    {
        cout << pCurr->value() << " --> ";
        pCurr = pCurr->getAscNext();
    }
    cout << "NULL" << endl;
}


void MagicalContainer::printLinkedListAscBack() const
{
    MisticalElementNode *pCurr = _tail;

    while(pCurr)
    {
        cout << pCurr->value() << " --> ";
        pCurr = pCurr->getAscBack();
    }
    cout << "NULL" << endl;
}


void MagicalContainer::printLinkedListPrimeNext() const
{
    MisticalElementNode *pCurr = _primeHead;

    while(pCurr)
    {
        cout << pCurr->value() << " --> ";
        pCurr = pCurr->getPrimeNext();
    }
    cout << "NULL" << endl;
}


void MagicalContainer::printLinkedListPrimeBack() const
{
    MisticalElementNode *pCurr = _primeTail;

    while(pCurr)
    {
        cout << pCurr->value() << " --> ";
        pCurr = pCurr->getPrimeBack();
    }
    cout << "NULL" << endl;
}