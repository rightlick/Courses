/* Тема 01: Числа и строки: операции с ними, ввод и вывод
Урок 12: Нюансы над строками
Задание 13
Напишите программу, которая считывает два целых неотрицательных числа, разделённых пробелом. 
Программа должна вычислить их сумму S и вывести произведение S на количество цифр в десятичной записи S.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Считайте два целых числа из cin
    int x, y;
    cin >> x >> y;
    // Выведите произведение их суммы на количество чисел в записи суммы
    int s = x + y;
    string sum = to_string(s);
    cout << s * sum.size() << endl;
}