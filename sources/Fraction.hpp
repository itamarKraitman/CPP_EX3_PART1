#include <iostream>

namespace ariel
{
    class Fraction
    {
    private:
        int nominator;
        int denominator;


    public:
        Fraction(int nominator, int denominator);
        int getNominator() const;
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

        friend bool operator+(double floatNumber, const Fraction &f1);
        friend bool operator-(double floatNumber, const Fraction &f1);
        friend bool operator*(double floatNumber, const Fraction &f1);
        friend bool operator/(double floatNumber, const Fraction &f1);

        friend bool operator==(const Fraction &f1, const Fraction &f2);
        friend bool operator>=(const Fraction &f1, const Fraction &f2);
        friend bool operator<=(const Fraction &f1, const Fraction &f2);
        friend bool operator>(const Fraction &f1, const Fraction &f2);
        friend bool operator<(const Fraction &f1, const Fraction &f2);
        friend bool operator==(const Fraction &f1, double floatNumber);
        friend bool operator>=(const Fraction &f1, double floatNumber);
        friend bool operator<=(const Fraction &f1, double floatNumber);
        friend bool operator>(const Fraction &f1, double floatNumber);
        friend bool operator<(const Fraction &f1, double floatNumber);

        friend std::ostream &operator<<(std::ostream &output, const Fraction &f);
        friend std::istream &operator>>(std::istream &input, Fraction &f);
    };
}