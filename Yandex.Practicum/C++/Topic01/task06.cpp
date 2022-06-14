/* Тема 01: Числа и строки: операции с ними, ввод и вывод
Урок 7: Вещественные числа
Задание 6
Напишите программу, которая считывает два double-числа и выводит целую часть их суммы.
*/
#include <iostream>

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;
    //cout << (int) (x + y) << endl;
    cout << static_cast<int>(x + y) << endl;
} 