/* Тема 01: Числа и строки: операции с ними, ввод и вывод
Урок 6: Целые числа
Задание 4
По аналогии с cout, из cin можно за одну команду получить несколько чисел.
Напишите программу, которая считывает два целых числа и выводит их частное.
*/

#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    cout << x / y << endl;
} 