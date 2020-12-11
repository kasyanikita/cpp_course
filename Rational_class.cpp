#include <numeric>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational
{
    friend istream &operator>>(istream &stream, Rational &obj);

public:
    Rational()
    {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator)
    {
        int GCD = gcd(numerator, denominator);
        numerator /= GCD;
        denominator /= GCD;
        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator < 0))
        {
            numerator = -numerator;
            denominator = -denominator;
        }
        if (numerator == 0)
        {
            num = 0;
            den = 1;
        }
        else
        {
            num = numerator;
            den = denominator;
        }
    }

    int Numerator() const
    {
        return num;
    }

    int Denominator() const
    {
        return den;
    }

private:
    int num;
    int den;
};

bool operator==(const Rational &lhs, const Rational &rhs)
{
    return (lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator());
}

Rational operator+(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator() +
                        rhs.Numerator() * lhs.Denominator(),
                    lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator() -
                        rhs.Numerator() * lhs.Denominator(),
                    lhs.Denominator() * rhs.Denominator());
}

Rational operator*(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

ostream &operator<<(ostream &stream, const Rational &obj)
{
    stream << obj.Numerator() << '/' << obj.Denominator();
    return stream;
}

istream &operator>>(istream &stream, Rational &obj)
{
    int p = 0;
    int q = 1;
    if (!(stream >> p))
    {
        return stream;
    }
    if (stream.peek() == '/')
    {
        stream.ignore(1); 

        if (!(stream >> q)) {
            return stream;
        }
    } else {
        obj = Rational();
        return stream;
    }
    obj = Rational(p, q);
    return stream;
}

bool operator>(const Rational &lhs, const Rational &rhs)
{
    double f1 = double(lhs.Numerator()) / lhs.Denominator();
    double f2 = double(rhs.Numerator()) / rhs.Denominator();
    return f1 > f2;
}

bool operator<(const Rational &lhs, const Rational &rhs)
{
    double f1 = double(lhs.Numerator()) / lhs.Denominator();
    double f2 = double(rhs.Numerator()) / rhs.Denominator();
    return f1 < f2;
}