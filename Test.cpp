#include <iostream>
#include <string>
#include <stdexcept>
#include <random>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
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

TEST_CASE("Logic operators work as expected- fraction and fraction")
{
    int nomiA = 0, denomiA = 0, nomiB = 0, denomiB = 0, nomiC = 0, denomiC = 0;
    for (int i = 1; i < 1000; i++)
    {
        Fraction a(i, i + 1);
        Fraction b(i + 1, i + 2);
        Fraction c(i + 2, i + 3);
        // a > b > c always!
        CHECK(a >= b);
        CHECK(b >= c);
        CHECK(c <= a);
        CHECK(!(a == b));
        CHECK(!(c == b));
        Fraction d(i, i + 1); // same as a
        CHECK(a == d);
        CHECK(c < a);
        CHECK(a > b);
    }
}

TEST_CASE("Logic operatos works as expectd- float number and fraction")
{
    Fraction a(1, 2);
    CHECK(a > 0.1);
    CHECK(0.111 < a);
    CHECK(a == 0.5);
}

TEST_CASE("Negative numerator and denominator")
{
    Fraction a(-5, -3); // -5/-3 == 5/3
    Fraction b(5, 3);
    CHECK(a == b);
    Fraction c(-5, 3); //-5/3
    CHECK(a > c);
    Fraction d(5, -3); // 5/-3 == -5/3
    CHECK(c == d);
    CHECK(d < b);
}

TEST_CASE("reduced and unreduced fractions are equal")
{
    for (int i = 1; i < 1000; i++)
    {
        Fraction a(i, i + 1);
        Fraction b(i * 3, (i + 1) * 3);
        CHECK(a == b); // 'a' and 'b' should be rqual! eg 1/2 == 2/4 == 3/6
    }
}

TEST_CASE("Binary operators works as excpected")
{
    Fraction a(1, 2);
    Fraction b(1, 4);
    Fraction c = a + b;
    CHECK(c == Fraction(3, 4));
    c = a - b;
    CHECK(c == Fraction(1, 4));
    c = a / b;
    CHECK(c == Fraction(2, 1));
    c = a * b;
    CHECK(c == Fraction(1, 8));
    c = 1.1 * a;
    CHECK(c == Fraction(8, 5));
    c = b + 2.421;
    CHECK(c == Fraction(2671, 1000));
    c = a + b - 1;
    CHECK(c == Fraction(-1, 4));
    a++;
    CHECK(a == Fraction(3,2));
    b--;
    CHECK(b == Fraction(-3,4));
}


TEST_CASE("<< operator works correctly")
{
     std::ostringstream output;
     Fraction a(1,2);
     output << a;
     CHECK(output.str() == "1/2");
     output.clear();
     Fraction b(1,-2);
     output << b;
     CHECK(output.str() == "1/-2");
     output.clear();
     Fraction c(-1,2);
     output << c;
     CHECK(output.str() == "-1/2");
}