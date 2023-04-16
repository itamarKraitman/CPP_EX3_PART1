#include <iostream>
#include "Fraction.hpp"

namespace ariel
{
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}
    int Fraction::getNumerator() const {return this->numerator;}
    int Fraction::geDenominator() const {return this->denominator;}

    // overloading +,-,*,/,==,>,<,<=,>=,++,--,<<,>>
    Fraction Fraction::operator+(const Fraction &other) {return Fraction(this->numerator, other.numerator);}
    Fraction Fraction::operator-(const Fraction &other) {return Fraction(this->numerator, other.numerator);}
    Fraction Fraction::operator*(const Fraction &other) {return Fraction(this->numerator, other.numerator);}
    Fraction Fraction::operator/(const Fraction &other) {return Fraction(this->numerator, other.numerator);}

    Fraction Fraction::operator*(double floatNumber) {return Fraction(this->numerator, floatNumber);}
    Fraction Fraction::operator+(double floatNumber) {return Fraction(this->numerator, floatNumber);}
    Fraction Fraction::operator-(double floatNumber) {return Fraction(this->numerator, floatNumber);}
    Fraction Fraction::operator/(double floatNumber) {return Fraction(this->numerator, floatNumber);}

    Fraction Fraction::operator++(int dummy_flag) {
        Fraction copy = *this;
        return copy;
    }
    Fraction Fraction::operator--(int dummy_flag) {
        Fraction copy = *this;
        return copy;
    }
    Fraction &Fraction::operator++() {return *this;}
    Fraction &Fraction::operator--() {return *this;}
    

    Fraction operator+(double floatNumber, const Fraction &f1) {return Fraction(floatNumber + f1.getNumerator(), 1);}
    Fraction operator-(double floatNumber, const Fraction &f1) {return Fraction(floatNumber - f1.getNumerator(), 1);}
    Fraction operator*(double floatNumber, const Fraction &f1) {return Fraction(floatNumber * f1.getNumerator(), 1);}
    Fraction operator/(double floatNumber, const Fraction &f1) {return Fraction(floatNumber / f1.getNumerator(), 1);}

    bool operator==(const Fraction &f1, const Fraction &f2) {return (f1.getNumerator() == f2.getNumerator());}
    bool operator>=(const Fraction &f1, const Fraction &f2) {return (f1.getNumerator() >= f2.getNumerator());}
    bool operator<=(const Fraction &f1, const Fraction &f2) {return (f1.getNumerator() <= f2.getNumerator());}
    bool operator>(const Fraction &f1, const Fraction &f2) {return (f1.getNumerator() > f2.getNumerator());}
    bool operator<(const Fraction &f1, const Fraction &f2) {return (f1.getNumerator() < f2.getNumerator());}
    
    bool operator==(double floatNumber, const Fraction &f1) {return (f1.getNumerator() == floatNumber);}
    bool operator>=(double floatNumber, const Fraction &f1) {return (f1.getNumerator() >= floatNumber);}
    bool operator<=(double floatNumber, const Fraction &f1) {return (f1.getNumerator() <= floatNumber);}
    bool operator>(double floatNumber, const Fraction &f1) {return (f1.getNumerator() > floatNumber);}
    bool operator<(double floatNumber, const Fraction &f1) {return (f1.getNumerator() < floatNumber);}
    
    bool operator==(const Fraction &f1, double floatNumber) {return (f1.getNumerator() == floatNumber);}
    bool operator>=(const Fraction &f1, double floatNumber) {return (f1.getNumerator() >= floatNumber);}
    bool operator<=(const Fraction &f1, double floatNumber) {return (f1.getNumerator() <= floatNumber);}
    bool operator>(const Fraction &f1, double floatNumber) {return (f1.getNumerator() < floatNumber);}
    bool operator<(const Fraction &f1, double floatNumber) {return (f1.getNumerator() < floatNumber);}

    std::ostream &operator<<(std::ostream &output, const Fraction &f) {return (output << f.getNumerator() << '/' << f.geDenominator());}
    std::istream &operator>>(std::istream &input, Fraction &f) {
         input >> f.numerator >> f.denominator;

        // Check if denominator is zero
        if (f.denominator == 0) {
            input.setstate(std::ios_base::failbit); // Set fail bit
        } else {
            f.numerator = 0; // Reduce fraction to its lowest terms
        }

        return input;

    }
}