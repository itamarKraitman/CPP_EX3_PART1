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
    // generating 1000 times reandom numerator, and check if constructing fraction with
    // zero at the dnominator throws an error
    srand(time(NULL));

    for (int i = 0; i < 1000; i++)
    {
        int num = rand() % 2001 - 1000; // generate random number between -1000 to 1000
        CHECK_THROWS(Fraction(num, 0));
    }

    CHECK_NOTHROW(Fraction(0, 0)); // should not throw
}

TEST_CASE("Float number as input")
{
    Fraction a(1.5);
    CHECK_EQ(a, 1.5);
    Fraction b(3, 2);
    CHECK_EQ(a, b);
    CHECK(a.getNumerator() == b.getNumerator() && a.getDenominator() == b.getDenominator());
    Fraction c(0.000001); // should be rounded up to 3 digits beyond decimal point (so, to 0) according README
    CHECK_EQ(c, 0);
}

TEST_CASE("Methods do not throw errors- fraction with fraction")
{
    srand(time(NULL));

    int nomiA = 0, denomiA = 0, nomiB = 0, denomiB = 0;
    for (int i = 0; i < 1000; i++)
    {
        nomiA = rand() % 2001 - 1000;
        while (denomiA == 0 || denomiB == 0) // make sure I am not deviding by zero
        {
            denomiA = rand() % 2001 - 1000;
            denomiB = rand() % 2001 - 1000;
        }
        Fraction a(nomiA, denomiA);
        Fraction b(nomiB, denomiB);
        CHECK_NOTHROW(a + b);
        CHECK_NOTHROW(a - b);
        if (b > 0 || b < 0) // b might be zero becuase nominator equals to 0 is valid
        {
            CHECK_NOTHROW(a / b);
        }
        CHECK_NOTHROW(a * b);
        CHECK_NOTHROW(a++);
        CHECK_NOTHROW(a--);
        CHECK_NOTHROW(--a);
        CHECK_NOTHROW(++a);
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
        CHECK_NOTHROW(a + 1.1);
        CHECK_NOTHROW(a - 1.1);
        CHECK_NOTHROW(a / 1.1);
        CHECK_NOTHROW(a * 1.1);
        CHECK_NOTHROW(1.1 * a);
        CHECK_NOTHROW(1.1 + a);
    }
}

TEST_CASE("Logic operators work as expected- fraction and fraction")
{
    bool flag = true;
    for (int i = 1; i < 1000; i++)
    {
        Fraction a(i, i + 1); // first 1/2
        // sanity check
        if (flag == 1)
        {
            flag = false;
            CHECK(a == 1 / 2);
        }

        Fraction b(i + 1, i + 2); // first 2/3
        Fraction c(i + 2, i + 3); // first 4/3 --> a < b < c
        CHECK(a <= b);
        CHECK(c >= b);
        CHECK(c >= a);
        CHECK(!(a == b));
        CHECK(!(c == b));
        Fraction d(i, i + 1); // same as a
        CHECK(a.getNumerator() == b.getNumerator() && a.getDenominator() == b.getDenominator());
        CHECK(a == d);
        CHECK(c > a);
        CHECK(!(a > b));
    }
}

TEST_CASE("Logic operatos works as expectd- float number and fraction")
{
    Fraction a(1, 4);
    CHECK(a > 0.1);
    CHECK(a > Fraction(0.1));
    CHECK(0.111 < a);
    CHECK(a < Fraction(1, 2));
    CHECK(a > Fraction(1, 5));
    CHECK(a == 0.25);
    Fraction b(6 / 5);
    CHECK(a <= b);
    CHECK(!(a >= b));
    CHECK(!(a == b));
    Fraction c(2, 8);
    CHECK(a == c);
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
        CHECK(a == b); // 'a' and 'b' should be rqual! eg 1/2 == 2/4 == 3/6...
    }
}

TEST_CASE("Binary operators works as excpected")
{
    Fraction a(1, 2);
    Fraction b(1, 4);
    Fraction c = a + b;
    cout << c << endl;
    CHECK(c == Fraction(3, 4));
    c = a - b;
    CHECK(c == Fraction(1, 4));
    c = a / b;
    CHECK(c == Fraction(2, 1));
    c = a * b;
    CHECK(c == Fraction(1, 8));
    c = 1.1 * a;
    CHECK(!(c == Fraction(8, 5)));
    c = a * 5.2365984; // calculation should be a * 5.236
    cout << a * 5.237 << endl;
    CHECK(c == Fraction(5237, 2000));
    c = b + 2.421;
    CHECK(c == Fraction(2671, 1000));
    c = a + b - 1;
    CHECK(c == Fraction(-1, 4));
    a++; // returns 1/2 before apply ++
    CHECK(a == Fraction(1, 2));
    --a; // apply -- before return a
    CHECK(a == Fraction(1, 2));
}

TEST_CASE("<< operator works correctly")
{
    std::ostringstream output;
    Fraction a(1, 2);
    output << a;
    CHECK(output.str() == "1/2");
    output.str("");
    Fraction b(1, -2);
    output << b;
    CHECK(output.str() == "1/-2");
    output.str("");
    Fraction c(-1, 2);
    output << c;
    cout << c.getDenominator() << ", " << c.getNumerator() << endl;
    CHECK(output.str() == "-1/2");
}

TEST_CASE(">> operator works correctly")
{
    Fraction a(1, 2), b(-1, 2), c(1, -2), d(-1, -2);
    stringstream input("1 2"); // should produce 1/2

    Fraction frac1;
    CHECK_NOTHROW(input >> frac1);
    CHECK_EQ(frac1, a);
    input.clear();
    input.str("-1 2");
    Fraction frac2;
    CHECK_NOTHROW(input >> frac2);
    CHECK_EQ(frac2, b);
    input.clear();
    input.str("1 -2");
    Fraction frac3;
    CHECK_NOTHROW(input >> frac3);
    CHECK_EQ(frac3, c);
    input.clear();
    input.str("-1 -2");
    Fraction frac4;
    CHECK_NOTHROW(input >> frac4);
    CHECK_EQ(frac4, d);
    input.clear();

    // more than one fraction as input
    stringstream chain_input("1 2 -1 -2");
    Fraction frac5, frac6;
    chain_input >> frac5 >> frac6;
    CHECK_EQ(frac5, a);
    CHECK_EQ(frac6, d);

    // invalid input
    stringstream invalid_input("1");
    Fraction invalid;
    CHECK_THROWS_AS(invalid_input >> invalid, std::runtime_error);
    invalid_input.str("/");
    CHECK_THROWS_AS(invalid_input >> invalid, std::invalid_argument);
}
