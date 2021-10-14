#include <iostream>
#include <vector>
using namespace std;


class Rational {
private:
    int p;
    int q;
    void reduce();
public:
    Rational(const int& p, const int& q = 1);
    Rational(const Rational& other);

    friend bool operator<(const Rational& first, const Rational& second);
    friend bool operator==(const Rational& first, const Rational& second);
    friend bool operator>(const Rational& first, const Rational& second);

    friend Rational operator+(const Rational& first, const Rational& second);
    friend Rational operator-(const Rational& first, const Rational& second);
    friend Rational operator*(const Rational& first, const Rational& second);
    friend Rational operator/(const Rational& first, const Rational& second);

    friend void Print(const Rational& rational);

};


void Rational::reduce() {
    if (this->p == 0) {
        this->q = 1;
    }
    else {
        int oldUp = abs(this->p);
        int oldDown = abs(this->q);
        while (oldDown != 0 && oldUp != 0) {
            if (oldDown > oldUp) {
                oldDown = oldDown % oldUp;
            }
            else {
                oldUp = oldUp % oldDown;
            }
        }
        if ((this->p < 0 && this->q < 0) || (this->p > 0 && this->q < 0)) {
            this->p = -this->p;
            this->q = -this->q;
        }
        this->p /= oldUp + oldDown;
        this->q /= oldUp + oldDown;
    }
}


Rational::Rational(const int& p, const int& q) {
    this->p = p;
    this->q = q;
    this->reduce();
}


Rational::Rational(const Rational& other) {
    p = other.p;
    q = other.q;
}


bool operator<(const Rational& first, const Rational& second) {
    return ((double(first.p) / double(first.q)) < (double(second.p) / double(second.q)));
}


bool operator==(const Rational& first, const Rational& second) {
    return (!(first < second) && !(second < first));
}


bool operator>(const Rational& first, const Rational& second) {
    return !((first < second) || (first == second));
}


Rational operator+(const Rational& first, const Rational& second) {
    if (second.p == 0) {
        return first;
    }
    else {
        return Rational(first.p * second.q + first.q * second.p, first.q * second.q);
    }
}


Rational operator*(const Rational& first, const Rational& second) {
    return Rational(first.p * second.p, first.q * second.q);
}


Rational operator-(const Rational& first, const Rational& second) {
    if (second.p == 0) {
        return first;
    }
    else {
        return Rational(first.p * second.q - first.q * second.p, first.q * second.q);
    }
}


Rational operator/(const Rational& first, const Rational& second) {
    if (second.p != 0) {
        return Rational(first.p * second.q, first.q * second.p);
    }
}


void Print(const Rational& rational) {
    cout << rational.p;
    if (rational.q != 1) {
        cout << '/' << rational.q;
    }
    cout << endl;
}




int main() {
    Rational a(1, 2);
    Rational b(2);
    Rational c(b);

    vector<Rational> v;
    for (int i = 0; i < 3; ++i) {
        int p, q;
        cin >> p >> q;
        v.emplace_back(p, q);
    }
    for (int i = 0; i < 3; ++i) {
        cout << "v[" << i << "] " << "is ";
        Print(v[i]);
    }


    cout << "Add(a, b): ";
    Print(a + b);
    cout << "Sub(a, c): ";
    Print(a - c);
    cout << "Mul(a, b): ";
    Print(a * b);
    cout << "Div(a, c): ";
    Print(a / c);

    cout << "a < b is " << (a < b) << endl;
    cout << "a == b is " << (a == b) << endl;
    cout << "c > b is " << (c > b) << endl;
     
    cout << "Example of complicated expression " << ((((a + b) * c / b - a) < (b * (c + a) - c)) == ((c * a + b) > (b - a / c))); 
    return 0;
}
