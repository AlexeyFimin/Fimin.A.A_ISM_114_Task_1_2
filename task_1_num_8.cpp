#include <iostream>
#include <cstring>
using namespace std;


class Rational {
private:
    int p;
    int q;
    void reduce();
    void AddValueToText(string& text, int value) const;

public:

    Rational() = default;
    Rational(const int& p, const int& q = 1);

    void Init(const int& p, const int& q);
    string ToString() const;
    void Read();
    friend Rational MakeRational(const int& p, const int& q);

    bool Less(const Rational& second) const;
    bool Equal(const Rational& second) const;
    bool Grater(const Rational& second) const;

    Rational Add(const Rational& second) const;
    Rational Sub(const Rational& second) const;
    Rational Mul(const Rational& second) const;
    Rational Div(const Rational& second) const;

    void Display() const;
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


void Rational::AddValueToText(string& text, int value) const {
    string temp;
    int ost;
    while (value != 0) {
        ost = value % 10;
        temp += char('0' + ost);
        value -= ost;
        value /= 10;
    }

    for (int i = temp.size() - 1; i >= 0; --i) {
        text += temp[i];
    }
}


string Rational::ToString() const {
    string text;
    AddValueToText(text, this->p);
    text += '/';
    AddValueToText(text, this->q);
    return text;
}


void Rational::Init(const int& p, const int& q) {
    if (q != 0) {
        this->p = p;
        this->q = q;
        reduce();
    }
}


void Rational::Read() {
    char* string = new char[13];
    cin >> string;
    cout << endl;
    char* key;
    bool flag = false;
    for (size_t i = 0; i < strlen(string); ++i) {
        if (string[i] == '/') {
            flag = true;
            break;
        }
    }
    if (flag) {
        char* f_string = new char[13];
        char* s_string = new char[13];
        size_t index;
        for (index = 0; string[index] != '/'; ++index) {
            f_string[index] = string[index];
        }
        int i = 0;
        for (++index; index < strlen(string); ++index && ++i) {
            s_string[i] = string[index];
        }
        this->p = int(strtoll(f_string, &key, 10));
        this->q = int(strtoll(s_string, &key, 10));
        this->reduce();
        delete[]f_string;
        delete[]s_string;
    }
    else {
        this->p = int(strtoll(string, &key, 10));
        this->q = 1;
    }
    delete[]string;
}


Rational::Rational(const int& p, const int& q) {
    this->p = p;
    this->q = q;
    this->reduce();
}


bool Rational::Less(const Rational& second) const {
    return ((double(this->p) / double(this->q)) < (double(second.p) / double(second.q)));
}


bool Rational::Equal(const Rational& second) const {
    return (!(this->Less(second)) && !(second.Less(*this)));
}


bool Rational::Grater(const Rational& second) const {
    return !(this->Less(second) || this->Equal(second));
}


Rational Rational::Add(const Rational& second) const {
    if (second.p == 0) {
        return *this;
    }
    else {
        return Rational(this->p * second.q + this->q * second.p, this->q * second.q);
    }
}


Rational Rational::Mul(const Rational& second) const {
    return Rational(this->p * second.p, this->q * second.q);
}


Rational Rational::Sub(const Rational& second) const {
    if (second.p == 0) {
        return *this;
    }
    else {
        return Rational(this->p * second.q - this->q * second.p, this->q * second.q);
    }
}


Rational Rational::Div(const Rational& second) const {
    if (second.p != 0) {
        Rational result(this->p * second.q, this->q * second.p);
        return result;
    }
}


void Rational::Display() const {
    cout << this->p;
    if (this->q != 1) {
        cout << '/' << this->q;
    }
    cout << endl;
}


Rational MakeRational(const int& p, const int& q) {
    return { p, q };
}


int main() {
    Rational a(1, 2);

    Rational b{};
    b.Read();

    Rational c{};
    c.Init(3, 5);

    Rational d = MakeRational(8, 3);

    d.Display();

    Rational result_1 = a.Add(b);
    result_1.Display();

    result_1 = a.Sub(c);
    result_1.Display();

    result_1 = a.Mul(b);
    result_1.Display();

    result_1 = b.Div(c);
    result_1.Display();

    cout << a.Less(b) << endl;;
    cout << a.Equal(b) << endl;;
    cout << c.Grater(b) << endl;

    return 0;
}
