#include "Rational.h"

Rational::Rational() {
    /**
     * @brief Создание рацонального числа без параметров (0/1)
     *
     */
    this->p = 0;
    this->q = 1;
}


void Rational::reduce() {
    /**
     * @brief Приватная фукнция сокращения дроби (поиск НОДа)
     *
     */
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


Rational::Rational(int p, int q) {
    /**
     * @brief Создание рационального числа с параметрами (числитель, знаменатель)
     *
     */
    this->p = p;
    this->q = q;
    this->reduce();
}


Rational::Rational(const Rational& other) {
    /**
     * @brief Конструктор копирования
     *
     */
    p = other.p;
    q = other.q;
}


bool operator<(const Rational& first, const Rational& second) {
    /**
     * @brief Оператор сравнения "меньше"
     *
     */
    return (first.p * second.q < second.p * first.p);
}


bool operator==(const Rational& first, const Rational& second) {
    /**
     * @brief Оператор сравнения "равно"
     *
     */
    return (first.p == second.p && first.q == second.q);
}


bool operator>(const Rational& first, const Rational& second) {
    /**
     * @brief Оператор сравнения "больше"
     *
     */
    return (first.p * second.q > second.p * first.p);
}


Rational operator+(const Rational& first, const Rational& second) {
    /**
     * @brief Оператор сложения двух дробей
     *
     */
    return Rational(first.p * second.q + first.q * second.p, first.q * second.q);
}


Rational operator*(const Rational& first, const Rational& second) {
    /**
     * @brief Оператор умножения двух дробей
     *
     */
    return Rational(first.p * second.p, first.q * second.q);
}


Rational operator-(const Rational& first, const Rational& second) {
    /**
     * @brief Оператор вычетания двух дробей
     *
     */
    return Rational(first.p * second.q - first.q * second.p, first.q * second.q);
}


Rational operator/(const Rational& first, const Rational& second) {
    /**
     * @brief Оператор деления двух дробей
     *
     */
    return Rational(first.p * second.q, first.q * second.p);
}

ostream& operator<<(ostream& os, const Rational& rational) {
    /**
     * @brief Оператор вывода дроби на консоль
     *
     */
    os << rational.p << '/' << rational.q << endl;
    return os;
}
