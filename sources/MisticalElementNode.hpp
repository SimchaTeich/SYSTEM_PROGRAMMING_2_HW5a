#ifndef MISTICAL_ELEMENT_NODE_HPP
#define MISTICAL_ELEMENT_NODE_HPP

namespace ariel
{
    class MisticalElementNode
    {
    public:
        MisticalElementNode(int value);

        // getters
        int value() const;
        MisticalElementNode *getAscNext() const;
        MisticalElementNode *getAscBack() const;
        MisticalElementNode *getPrimeNext() const;
        MisticalElementNode *getPrimeBack() const;

        // setters
        void setAscNext(MisticalElementNode *next);
        void setAscBack(MisticalElementNode *next);
        void setPrimeNext(MisticalElementNode *next);
        void setPrimeBack(MisticalElementNode *next);

    private:
        int _value;
        MisticalElementNode *_ascNext;
        MisticalElementNode *_ascBack;
        MisticalElementNode *_primeNext;
        MisticalElementNode *_primeBack;
    };
};

#endif // !MISTICAL_ELEMENT_NODE_HPP