#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include "Fraction.hpp"

namespace ariel
{
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
    {
        if (numerator == 0)
        {
            throw logic_error("Dividing by zero");
        }
        reduce_fraction();
    }
    Fraction::Fraction(double floatNumber) // https://www.geeksforgeeks.org/convert-given-float-value-to-equivalent-fraction/
    {
        // find the number of digits after decimal point
        size_t decimalPointPos = std::to_string(floatNumber).find(".");
        size_t numbrOfDigitsAfterPoint = std::to_string(floatNumber).size() - decimalPointPos - 1;

        // round to 3 decimal places at most
        double limitedToThreeNumber;
        if (numbrOfDigitsAfterPoint > 3)
        {
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(3) << floatNumber;
            limitedToThreeNumber = std::stod(stream.str());
        }

        // convert to numerator and denominator
        this->denominator = std::pow(10, numbrOfDigitsAfterPoint);
        cout << this->denominator << endl;
        this->numerator = std::round(limitedToThreeNumber * denominator);
        cout << this->numerator << endl;

        // reduce
        reduce_fraction();

        // check if the number is rational ,if not, its denominator equals to 0
        if (this->denominator == 0)
        {
            throw runtime_error("irretional number, dividing by zero");
        }
    }
    int Fraction::getNumerator() const { return this->numerator; }
    int Fraction::getDenominator() const { return this->denominator; }

    // overloading +,-,*,/,==,>,<,<=,>=,++,--,<<,>>
    Fraction Fraction::operator+(const Fraction &other) const
    {
        Fraction temp(this->numerator * other.getDenominator() + this->denominator + other.getNumerator(), this->denominator * other.denominator);
        temp.reduce_fraction();
        return temp;
    }
    Fraction Fraction::operator-(const Fraction &other) const
    {
        Fraction temp(this->numerator * other.getDenominator() - this->denominator + other.getNumerator(), this->denominator * other.denominator);
        temp.reduce_fraction();
        return temp;
    }
    Fraction Fraction::operator*(const Fraction &other) const
    {
        Fraction temp(this->numerator * other.getNumerator(), this->denominator * other.getDenominator());
        temp.reduce_fraction();
        return temp;
    }
    Fraction Fraction::operator/(const Fraction &other) const
    {
        Fraction temp(this->numerator * other.getDenominator(), this->denominator * other.getNumerator());
        temp.reduce_fraction();
        return temp;
    }

    Fraction Fraction::operator*(double floatNumber) const
    {
        Fraction floatAsFraction(floatNumber);
        floatAsFraction.reduce_fraction();
        return this->operator*(floatAsFraction);
    }
    Fraction Fraction::operator+(double floatNumber) const
    {
        Fraction floatAsFraction(floatNumber);
        floatAsFraction.reduce_fraction();
        return this->operator+(floatAsFraction);
    }
    Fraction Fraction::operator-(double floatNumber) const
    {
        Fraction floatAsFraction(floatNumber);
        floatAsFraction.reduce_fraction();
        return this->operator-(floatAsFraction);
    }
    Fraction Fraction::operator/(double floatNumber) const 
    { 
        Fraction floatAsFraction(floatNumber);
        floatAsFraction.reduce_fraction();
        return this->operator/(floatAsFraction); 
    }

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

    void Fraction::reduce_fraction()
    {
        int gcd = find_gcd();
        this->numerator /= gcd;
        this->denominator /= gcd;
    }

    int Fraction::find_gcd() const
    {
        int nume = this->numerator;
        int deno = this->denominator;
        while (deno != 0)
        {
            int temp = deno;
            deno = nume % deno;
            nume = temp;
        }
        return nume;
    }

    Fraction &Fraction::operator++() { return *this; }
    Fraction &Fraction::operator--() { return *this; }

    Fraction operator+(double floatNumber, const Fraction &frac1) { return Fraction(floatNumber + frac1.getNumerator(), 1); }
    Fraction operator-(double floatNumber, const Fraction &frac1) { return Fraction(floatNumber - frac1.getNumerator(), 1); }
    Fraction operator*(double floatNumber, const Fraction &frac1) { return Fraction(floatNumber * frac1.getNumerator(), 1); }
    Fraction operator/(double floatNumber, const Fraction &frac1) { return Fraction(floatNumber / frac1.getNumerator(), 1); }

    bool operator==(const Fraction &frac1, const Fraction &frac2) { return (frac1.getNumerator() == frac2.getNumerator()); }
    bool operator>=(const Fraction &frac1, const Fraction &frac2) { return (frac1.getNumerator() >= frac2.getNumerator()); }
    bool operator<=(const Fraction &frac1, const Fraction &frac2) { return (frac1.getNumerator() <= frac2.getNumerator()); }
    bool operator>(const Fraction &frac1, const Fraction &frac2) { return (frac1.getNumerator() > frac2.getNumerator()); }
    bool operator<(const Fraction &frac1, const Fraction &frac2) { return (frac1.getNumerator() < frac2.getNumerator()); }

    bool operator==(double floatNumber, const Fraction &frac1) { return (frac1.getNumerator() == floatNumber); }
    bool operator>=(double floatNumber, const Fraction &frac1) { return (frac1.getNumerator() >= floatNumber); }
    bool operator<=(double floatNumber, const Fraction &frac1) { return (frac1.getNumerator() <= floatNumber); }
    bool operator>(double floatNumber, const Fraction &frac1) { return (frac1.getNumerator() > floatNumber); }
    bool operator<(double floatNumber, const Fraction &frac1) { return (frac1.getNumerator() < floatNumber); }

    bool operator==(const Fraction &frac1, double floatNumber) { return (frac1.getNumerator() == floatNumber); }
    bool operator>=(const Fraction &frac1, double floatNumber) { return (frac1.getNumerator() >= floatNumber); }
    bool operator<=(const Fraction &frac1, double floatNumber) { return (frac1.getNumerator() <= floatNumber); }
    bool operator>(const Fraction &frac1, double floatNumber) { return (frac1.getNumerator() < floatNumber); }
    bool operator<(const Fraction &frac1, double floatNumber) { return (frac1.getNumerator() < floatNumber); }

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