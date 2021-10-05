#include <iostream>
#include <cstring>
using namespace std;


class Rational {
private:
    int p;
    int q;
    void reduce();
    void addvalue (string& text, int value) const;

public:

    Rational() = default;
    Rational(const int p, const int q = 1);

    void set_q (const int q)
    {
        return this->q;
    }

    void reduce() {
       
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


    void addvalue (string& text, int value) const {
       
        int ost;
        while (value != 0) {
            ost = value % 10;
            temp += ost;
            value -= ost;
            value /= 10;
        }
        
        string temp;

        for (int i = temp.size() - 1; i >= 0; --i) {
            text += temp[i];
        }
    }


    stringstrem Rational::ToString() const {
        string text;
        addvalue (text, this->p);
        text += '/';
        addvalue (text, this->q);
        return text;
    }


    void Init(const int& p, const int& q) {
        if (q != 0) {
            this->p = p;
            this->q = q;
            reduce();
        }
    }



    Rational::Rational(const int& p, const int& q) {
        this->p = p;
        this->q = q;
        this->reduce();
    }


    bool Less(const Rational& second) const {
        int ans1= (((double(this->p)*double(second.q)) / (double(this->q)*double(second.q)))
        int ans2= (((double(second.p)*double(this->q)) / (double(second.q)*double(this->q)))

        return  ans1 < ans2; 
    }


    bool =Equal(const Rational& second) const {
        return (!(this->Less(second)) && !(second.Less(*this)));
    }


    bool Grater(const Rational& second) const {
        return !(this->Less(second) || this->Equal(second));
    }


    Rational Add(const Rational& second) const {
        
            return Rational(this->p * second.q + this->q * second.p, this->q * second.q);
        
    }


    Rational Mul(const Rational& second) const {
        return Rational(this->p * second.p, this->q * second.q);
    }


    Rational Sub(const Rational& second) const {
       
            return Rational(this->p * second.q - this->q * second.p, this->q * second.q);
        
    }


    Rational Div(const Rational& second) const {
        if (second.p != 0) {
            Rational result(this->p * second.q, this->q * second.p);
            return result;
        }
    }


    void Display() const {
        cout << this->p;
        if (this->q != 1) {
            cout << '/' << this->q;
        }
        cout << endl;
    }


    Rational MakeRational(const int& p, const int& q) {
        return { p, q };
    }
};


int main() {
    Rational a(1, 2);
   
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
