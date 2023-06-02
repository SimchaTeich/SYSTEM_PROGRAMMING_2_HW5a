#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>

using namespace ariel;


TEST_CASE("Create container")
{
    CHECK_NOTHROW(MagicalContainer());
}


TEST_CASE("Insert elements")
{
    MagicalContainer mc;

    CHECK_NOTHROW(mc.addElement(1));
    CHECK(mc.size() == 1);

    CHECK_NOTHROW(mc.addElement(2));
    CHECK(mc.size() == 2);

    CHECK_NOTHROW(mc.addElement(3));
    CHECK(mc.size() == 3);

    CHECK_NOTHROW(mc.addElement(4));
    CHECK(mc.size() == 4);

    CHECK_NOTHROW(mc.addElement(5));
    CHECK(mc.size() == 5);
}


TEST_CASE("remove elements")
{
    MagicalContainer mc;

    // insert 12 elements
    for(int i = 1; i <= 12; i++)
    {
        mc.addElement(i);
    }

    // remove the first
    CHECK_NOTHROW(mc.removeElement(1));
    CHECK(mc.size() == 11);

    // remove the last
    CHECK_NOTHROW(mc.removeElement(12));
    CHECK(mc.size() == 10);
}


TEST_CASE("Ascending Iterator")
{
    MagicalContainer mc;
    MagicalContainer::AscendingIterator ai(mc);

    // insert elements
    int elements[] = {3, 4, 6, 7, 11, 9, 10, 5, 1, 2, 0, 8};
    for(int i = 0; i < 12; i++)
    {
        mc.addElement(elements[i]);
    }

    // check that order is ascending.
    int i = 0;
    for(auto it = ai.begin(); it != ai.end(); ++it)
    {
        CHECK(*it == i++);
    }

    // check copy CTOR
    auto it1 = ai.begin();
    CHECK_NOTHROW(MagicalContainer::AscendingIterator it2(it1));

    // check booliean operators
    MagicalContainer::AscendingIterator it2(it1);
    CHECK(it1 == it2);
    ++it2;
    CHECK(it1 < it2);
    CHECK(it2 > it1);
}


TEST_CASE("sideCross Iterator")
{
    MagicalContainer mc;
    MagicalContainer::SideCrossIterator si(mc);

    // insert elements
    int elements[] = {3, 4, 6, 7, 11, 9, 10, 5, 1, 2, 12, 8};
    for(int i = 0; i < 12; i++)
    {
        mc.addElement(elements[i]);
    }

    // check that order is side cross.
    auto it = si.begin();
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 12);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 11);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 10);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 9);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 8);
    ++it;
    CHECK(*it == 6);
    ++it;
    CHECK(*it == 7);
    ++it;
    CHECK(it == si.end());

    // check copy CTOR
    auto it1 = si.begin();
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator it2(it1));

    // check booliean operators
    MagicalContainer::SideCrossIterator it2(it1);
    CHECK(it1 == it2);
    ++it2;
    CHECK(it1 < it2);
    CHECK(it2 > it1);
}


TEST_CASE("Prime Iterator")
{
    MagicalContainer mc;
    MagicalContainer::PrimeIterator pi(mc);

    // insert elements
    int elements[] = {3, 4, 6, 7, 11, 9, 10, 5, 1, 2, 12, 8};
    for(int i = 0; i < 12; i++)
    {
        mc.addElement(elements[i]);
    }

    // check that order is just on primes.
    auto it = pi.begin();
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 7);
    ++it;
    CHECK(*it == 11);
    ++it;
    CHECK(it == pi.end());

    // check copy CTOR
    auto it1 = pi.begin();
    CHECK_NOTHROW(MagicalContainer::PrimeIterator it2(it1));

    // check booliean operators
    MagicalContainer::PrimeIterator it2(it1);
    CHECK(it1 == it2);
    ++it2;
    CHECK(it1 < it2);
    CHECK(it2 > it1);
}