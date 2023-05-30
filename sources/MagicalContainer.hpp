#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include "MisticalElementNode.hpp"

namespace ariel
{
    class MagicalContainer
    {
    public:
        MagicalContainer();
        ~MagicalContainer();
        void addElement(int value);
        void removeElement(int value);
        int size() const;

    private:
        // helpers methods
        bool isPrime(int num) const;
        void insertNode(MisticalElementNode *pNode, MisticalElementNode *pHead);
        void removeNode(int value, MisticalElementNode *pHead);
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