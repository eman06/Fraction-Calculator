#include <iostream>
using namespace std;

class Rational;
Rational& simplification(Rational& r);

class Rational
{
private:
    int num;
    int den;

public:
    Rational()
    {
        num = 0;
        den = 1;
    }

    Rational(int num, int denom)
    {
        this->num = num;
        if (denom == 0) {
            cout << "Error loser" << endl;
            this->den = 1;
        }
        else {
            this->den = denom;
        }
    }

    Rational(const Rational& other)
    {
        *this = other;
    }

    ~Rational()
    {
        // Destructor
    }

    Rational operator+(const Rational& other) const
    {
        Rational r;
        r.den = this->den * other.den;
        r.num = (this->num * other.den) + (other.num * this->den);
        simplification(r);
        return r;
    }

    Rational operator-(const Rational& other) const
    {
        Rational r;
        r.den = this->den * other.den;
        r.num = (this->num * other.den) - (other.num * this->den);
        simplification(r);
        return r;
    }

    Rational operator*(const Rational& other) const
    {
        Rational r;
        r.den = this->den * other.den;
        r.num = this->num * other.num;
        simplification(r);
        return r;
    }

    Rational operator/(const Rational& other) const
    {
        if (other.num == 0)
        {
            cout << "Error: Division by zero!" << endl;
            Rational r;
            r.num = 0;
            r.den = 1;
            return r;
        }
        Rational r;
        r.den = this->den * other.num;
        r.num = this->num * other.den;
        return simplification(r);
    }

    bool operator==(const Rational& other) const
    {
        return (other.num == this->num && other.den == this->den);
    }

    bool operator!=(const Rational& other) const
    {
        return (!(*this == other));
    }

    friend std::ostream& operator<<(std::ostream& os, const Rational& rational);
    friend std::istream& operator>>(std::istream& is, Rational& rational);

    void display()
    {
        if (this->den != 1)
            cout << this->num << "/" << this->den << endl;
        else
            cout << this->num << endl;
    }

    int getnum() const
    {
        return num;
    }

    int getden() const
    {
        return den;
    }

    void setnum(int n)
    {
        num = n;
    }

    void setden(int d)
    {
        if (d == 0)
        {
            cout << "Error loser" << endl;
            den = 1;
        }
        else
        {
            den = d;
        }
    }
};

ostream& operator<<(std::ostream& os, const Rational& rational)
{
    os << rational.num << "/" << rational.den;
    return os;
}

istream& operator>>(std::istream& is, Rational& rational)
{
    is >> rational.num >> rational.den;
    if (rational.den == 0) {
        cout << "Error loser" << endl;
        rational.den = 1;
    }
    return is;
}

Rational& simplification(Rational& r) {
    int a = r.getnum();
    int b = r.getden();
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gv = a;
    r.setnum(r.getnum() / gv);
    r.setden(r.getden() / gv);
    if (r.getden() < 0) {
        r.setden(-r.getden());
        r.setnum(-r.getnum());
    }
    return r;
}

int main()
{
    int p;
    int q, p2, q2;
    cout << "enter numerator 1: ";
    cin >> p;
    cout << "enter denominator 1: ";
    cin >> q;
    cout << "enter numerator 2: ";
    cin >> p2;
    cout << "enter denominator 2: ";
    cin >> q2;
    if (q != 0 && q2 != 0)
    {
        Rational r1(p, q);
        Rational r2(p2, q2);

        Rational r3 = r1 + r2;
        cout << "Addition: ";
        r3.display();
        Rational r4 = r1 - r2;
        cout << "Subtraction: ";
        r4.display();
        Rational r5 = r1 * r2;
        cout << "Multiplication: ";
        r5.display();
        Rational r6 = r1 / r2;

        cout << "Division: ";
        r6.display();
        cout << "Is r1 == r2? " << (r1 == r2) << endl;

    }
    else
    {
        cout << "error loser!!!";
    }


}
