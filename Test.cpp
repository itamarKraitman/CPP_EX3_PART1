#include <iostream>
#include <string>
#include <stdexcept>
#include <random>
#include <cstdlib>
#include <ctime>
#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace ariel;

TEST_CASE("Zero at the denominator- deviding by zero")
{
    srand(time(NULL));

    for (int i = 0; i < 1000; i++)
    {
        int num = rand() % 2001 - 1000;
        CHECK_THROWS(Fraction(num, 0));
    }
}



TEST_CASE("Methods do not throw errors- fraction with fraction")
{
    srand(time(NULL));

    int nomiA = 0, denomiA = 0, nomiB = 0, denomiB = 0;
    for (int i = 0; i < 1000; i++)
    {
        nomiA = rand() % 2001 - 1000;
        while (denomiA == 0 && denomiB == 0) // make sure I am not deviding by zero
        {
            denomiA = rand() % 2001 - 1000;
            denomiB = rand() % 2001 - 1000;
        }
        Fraction a(nomiA, denomiA);
        Fraction b(nomiB, denomiB);
        CHECK_NOTHROW(a.operator+(b));
        CHECK_NOTHROW(a.operator-(b));
        CHECK_NOTHROW(a.operator/(b));
        CHECK_NOTHROW(a.operator*(b));
        CHECK_NOTHROW(a.operator++());
        CHECK_NOTHROW(a.operator--());
    }
}

TEST_CASE("Methods do not throw errors- fraction with float")
{
    srand(time(NULL));

    int nomiA = 0, denomiA = 0;
    for (int i = 0; i < 1000; i++)
    {
        nomiA = rand() % 2001 - 1000;
        while (denomiA == 0) // make sure I am not deviding by zero
        {
            denomiA = rand() % 2001 - 1000;
        }
        Fraction a(nomiA, denomiA);
        CHECK_NOTHROW(a.operator+(1.1));
        CHECK_NOTHROW(a.operator-(1.1));
        CHECK_NOTHROW(a.operator/(1.1));
        CHECK_NOTHROW(a.operator*(1.1));
    }
}

TEST_CASE("Logic operator do not throw erros")
{
    srand(time(NULL));

    int nomiA = 0, denomiA = 0, nomiB = 0, denomiB = 0;
    for (int i = 0; i < 1000; i++)
    {
        nomiA = rand() % 2001 - 1000;
        while (denomiA == 0 && denomiB == 0) // make sure I am not deviding by zero
        {
            denomiA = rand() % 2001 - 1000;
            denomiB = rand() % 2001 - 1000;
        }
        Fraction a(nomiA, denomiA);
        Fraction b(nomiB, denomiB);
        CHECK_NOTHROW(a >= b);
        CHECK_NOTHROW(a > 1.3);
    }
}

