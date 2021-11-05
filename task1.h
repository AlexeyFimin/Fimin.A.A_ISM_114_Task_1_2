#include <iostream>
#include <vector>
using namespace std;

//спецификациии с собственным реализованным исключением.
/**
 * @brief независимый класс с полями - параметрами функции
 *
 */

class Rational {
private:
    int p;
    int q;
    void reduce();
    /**
     * @brief Приватная фукнция сокращения дроби (поиск НОДа)
     *
     */
public:
    Rational();
    /**
     * @brief Создание рацонального числа без параметров (0/1)
     *
     */

    Rational(int p, int q = 1);
    /**
     * @brief Создание рационального числа с параметрами (числитель, знаменатель)
     *
     */
    Rational(const Rational& other);
    /**
     * @brief Конструктор копирования
     *
     */


    friend bool operator<(const Rational& first, const Rational& second);
    /**
     * @brief Оператор сравнения "меньше"
     *
     */
    friend bool operator==(const Rational& first, const Rational& second);
    /**
     * @brief Оператор сравнения "равно"
     *
     */
    friend bool operator>(const Rational& first, const Rational& second);
    /**
     * @brief Оператор сравнения "больше"
     *
     */

    friend Rational operator+(const Rational& first, const Rational& second);
    /**
     * @brief Оператор сложения двух дробей
     *
     */
    friend Rational operator-(const Rational& first, const Rational& second);
    /**
     * @brief Оператор вычетания двух дробей
     *
     */
    friend Rational operator*(const Rational& first, const Rational& second);
    /**
     * @brief Оператор умножения двух дробей
     *
     */
    friend Rational operator/(const Rational& first, const Rational& second);
    /**
     * @brief Оператор деления двух дробей
     *
     */

    friend ostream& operator<<(ostream& os, const Rational& rational);
    /**
     * @brief Оператор вывода дроби на консоль
     *
     */
};
