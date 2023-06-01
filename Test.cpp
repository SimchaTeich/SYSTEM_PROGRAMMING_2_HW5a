#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>

using namespace ariel;


TEST_CASE("Create container")
{
    CHECK_NOTHROW(MagicalContainer());
}

