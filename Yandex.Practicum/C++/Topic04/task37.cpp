/* Тема 04: Функции
Урок 4: Зачем нужны функции
Задание 37
Напишите функцию, которая называется Factorial. Она должна возвращать int, принимать int и возвращать факториал своего аргумента.
Гарантируется, что аргумент функции находится в пределах от -10 до 10. Для отрицательных аргументов и нуля функция должна возвращать 1.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Factorial(int x) {
	// здесь вычисляем факториал числа и возвращаем полученное значение
    if (x > 1) {
        int count = 1;
        for (int i = 2; i <= x; ++i) {
            count *= i;
        }
        return count;
    }
    else 
        return 1;
}

int main () {
    int x;
    cin >> x;
    cout << "Factorial of " << x << " is " << Factorial(x) << endl;
}