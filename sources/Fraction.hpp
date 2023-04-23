#include <iostream>

namespace ariel
{

    using namespace std;

    template <typename T>
    bool isEqual(const T &a, const T &b)
    {
        return a == b;
    }

    template <typename T>
    bool greaterEqual(const T &a, const T &b)
    {
        return a >= b;
    }

    template <typename T>
    bool lessEqual(const T &a, const T &b)
    {
        return a <= b;
    }

    template <typename T>
    bool lessThan(const T &a, const T &b)
    {
        return a < b;
    }

    template <typename T>
    bool greaterThan(const T &a, const T &b)
    {
        return a > b;
    }

    class Fraction
    {
    private:
        int numerator;
        int denominator;
        int findGcd() const;

    public:
        Fraction(int numerator, int denominator);
        Fraction(double floatNumber);
        int getNumerator() const;
        int getDenominator() const;
        void reduceFraction();

        // overloading +,-,*,/,==,>,<,<=,>=,++,--,<<,>>
        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;

        Fraction operator*(double floatNumber) const;
        Fraction operator+(double floatNumber) const;
        Fraction operator-(double floatNumber) const;
        Fraction operator/(double floatNumber) const;

        Fraction operator++(int dummy_flag);
        Fraction operator--(int dummy_flag);
        Fraction &operator++();
        Fraction &operator--();

        friend Fraction operator+(double floatNumber, const Fraction &frac1);
        friend Fraction operator-(double floatNumber, const Fraction &frac1);
        friend Fraction operator*(double floatNumber, const Fraction &frac1);
        friend Fraction operator/(double floatNumber, const Fraction &frac1);

        friend bool operator==(const Fraction &frac1, const Fraction &frac2);
        friend bool operator>=(const Fraction &frac1, const Fraction &frac2);
        friend bool operator<=(const Fraction &frac1, const Fraction &frac2);
        friend bool operator>(const Fraction &frac1, const Fraction &frac2);
        friend bool operator<(const Fraction &frac1, const Fraction &frac2);
        friend bool operator==(double floatNumber, const Fraction &frac1);
        friend bool operator>=(double floatNumber, const Fraction &frac1);
        friend bool operator<=(double floatNumber, const Fraction &frac1);
        friend bool operator>(double floatNumber, const Fraction &frac1);
        friend bool operator<(double floatNumber, const Fraction &frac1);
        friend bool operator==(const Fraction &frac1, double floatNumber);
        friend bool operator>=(const Fraction &frac1, double floatNumber);
        friend bool operator<=(const Fraction &frac1, double floatNumber);
        friend bool operator>(const Fraction &frac1, double floatNumber);
        friend bool operator<(const Fraction &frac1, double floatNumber);

        friend std::ostream &operator<<(std::ostream &output, const Fraction &frac);
        friend std::istream &operator>>(std::istream &input, Fraction &frac);
    };
}