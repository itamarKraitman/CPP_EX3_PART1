#include <iostream>

namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;


    public:
        Fraction(int numerator, int denominator);
        Fraction(double floatNumber);
        int getNumerator() const;
        int geDenominator() const;

        // overloading +,-,*,/,==,>,<,<=,>=,++,--,<<,>>
        Fraction operator+(const Fraction &other);
        Fraction operator-(const Fraction &other);
        Fraction operator*(const Fraction &other);
        Fraction operator/(const Fraction &other);

        Fraction operator*(double floatNumber);
        Fraction operator+(double floatNumber);
        Fraction operator-(double floatNumber);
        Fraction operator/(double floatNumber);

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