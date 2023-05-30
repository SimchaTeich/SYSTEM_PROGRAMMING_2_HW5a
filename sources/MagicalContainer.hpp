#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include "MisticalElementNode.hpp"

namespace ariel
{
    class MagicalContainer
    {
    public:
        MagicalContainer();
        void addElement(int value);
        void removeElement(int value);
        void size() const;

    private:
        // helpers methods
        bool isPrime(int num) const;
        MisticalElementNode *createNode(int value) const;
        void insertNode(MisticalElementNode *pNode);
        void printLinkedList(MisticalElementNode *pHead) const;

        // members
        MisticalElementNode *_head;
        MisticalElementNode *_tail;
        MisticalElementNode *_primeHead;
        MisticalElementNode *_primeTail;
        int _size;
        int _primeSize;
    
    // code for Iterators in extrenal hpp files.
    // https://stackoverflow.com/questions/28176371/how-can-i-avoid-this-ugly-nested-class-c-code
    public:
        //class AscendingIterator;
        //class SideCrossIterator;
        //class PrimeIterator;
    };
}

#endif // !MAGICALCONTAINER_HPP