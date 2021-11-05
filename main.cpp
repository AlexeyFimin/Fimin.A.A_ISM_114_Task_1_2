#include "Rational.h"



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
        cout << v[i];
    }


    cout << "Add(a, b): ";
    cout << a + b;
    cout << "Sub(a, c): ";
    cout << a - c;
    cout << "Mul(a, b): ";
    cout << a * b;
    cout << "Div(a, c): ";
    cout << a / c;

    cout << "a < b is " << (a < b) << endl;
    cout << "a == b is " << (a == b) << endl;
    cout << "c > b is " << (c > b) << endl;

    cout << "Example of complicated expression " << ((((a + b) * c / b - a) < (b * (c + a) - c)) == ((c * a + b) > (b - a / c))); //пример комбинирования
    return 0;
}
