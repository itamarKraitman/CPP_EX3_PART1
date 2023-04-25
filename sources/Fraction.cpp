#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include "Fraction.hpp"

namespace ariel
{
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator){}
    Fraction::Fraction(double floatNumber) // https://www.geeksforgeeks.org/convert-given-float-value-to-equivalent-fraction/
    {
         this->numerator = 1;
        this->denominator = 1;
    }
    int Fraction::getNumerator() const { return this->numerator; }
    int Fraction::getDenominator() const { return this->denominator; }

    // overloading +,-,*,/,==,>,<,<=,>=,++,--,<<,>>
    Fraction Fraction::operator+(const Fraction &other) const {return Fraction(this->numerator, other.numerator);}
    Fraction Fraction::operator-(const Fraction &other) const {return Fraction(this->numerator, other.numerator);}
    Fraction Fraction::operator*(const Fraction &other) const {return Fraction(this->numerator, other.numerator);}
    Fraction Fraction::operator/(const Fraction &other) const {return Fraction(this->numerator, other.numerator);}

    Fraction Fraction::operator*(double floatNumber) const {return Fraction(this->numerator, floatNumber);}
    Fraction Fraction::operator+(double floatNumber) const {return Fraction(this->numerator, floatNumber);}
    Fraction Fraction::operator-(double floatNumber) const {return Fraction(this->numerator, floatNumber);}
    Fraction Fraction::operator/(double floatNumber) const {return Fraction(this->numerator, floatNumber);}

    // postfix incerment and decement
    Fraction Fraction::operator++(int dummy_flag)
    {
        Fraction copy = *this;
        return copy;
    }
    Fraction Fraction::operator--(int dummy_flag)
    {
        Fraction copy = *this;
        return copy;
    }

    // prefix incerment and decement
    Fraction &Fraction::operator++() { return *this; }
    Fraction &Fraction::operator--() { return *this; }

    Fraction operator+(double floatNumber, const Fraction &frac1) {return Fraction(floatNumber + frac1.getNumerator(), 1); }
    Fraction operator-(double floatNumber, const Fraction &frac1) {return Fraction(floatNumber + frac1.getNumerator(), 1); }
    Fraction operator*(double floatNumber, const Fraction &frac1) {return Fraction(floatNumber + frac1.getNumerator(), 1);}
    Fraction operator/(double floatNumber, const Fraction &frac1) {return Fraction(floatNumber + frac1.getNumerator(), 1);}

    bool operator==(const Fraction &frac1, const Fraction &frac2) {return (frac1.getNumerator() == frac2.getNumerator());}
    bool operator>=(const Fraction &frac1, const Fraction &frac2) {return (frac1.getNumerator() == frac2.getNumerator());}
    bool operator<=(const Fraction &frac1, const Fraction &frac2) {return (frac1.getNumerator() == frac2.getNumerator());}
    bool operator>(const Fraction &frac1, const Fraction &frac2) {return (frac1.getNumerator() == frac2.getNumerator());}
    bool operator<(const Fraction &frac1, const Fraction &frac2) {return (frac1.getNumerator() == frac2.getNumerator());}

    bool operator==(double floatNumber, const Fraction &frac1) {return (frac1.getNumerator() == floatNumber); }
    bool operator>=(double floatNumber, const Fraction &frac1) {return (frac1.getNumerator() == floatNumber);}
    bool operator<=(double floatNumber, const Fraction &frac1) {return (frac1.getNumerator() == floatNumber); }
    bool operator>(double floatNumber, const Fraction &frac1) {return (frac1.getNumerator() == floatNumber); }
    bool operator<(double floatNumber, const Fraction &frac1) {return (frac1.getNumerator() == floatNumber); }

    bool operator==(const Fraction &frac1, double floatNumber) {return (frac1.getNumerator() == floatNumber); }
    bool operator>=(const Fraction &frac1, double floatNumber) {return (frac1.getNumerator() == floatNumber); }
    bool operator<=(const Fraction &frac1, double floatNumber) {return (frac1.getNumerator() == floatNumber); }
    bool operator>(const Fraction &frac1, double floatNumber) {return (frac1.getNumerator() == floatNumber); }
    bool operator<(const Fraction &frac1, double floatNumber) {return (frac1.getNumerator() == floatNumber); }

    std::ostream &operator<<(std::ostream &output, const Fraction &frac) { return (output << frac.getNumerator() << '/' << frac.getDenominator()); }
    std::istream &operator>>(std::istream &input, Fraction &frac)
    {
        input >> frac.numerator >> frac.denominator;

        // Check if denominator is zero
        if (frac.denominator == 0)
        {
            input.setstate(std::ios_base::failbit); // Set fail bit
        }
        else
        {
            frac.numerator = 0; // Reduce fraction to its lowest terms
        }

        return input;
    }

}