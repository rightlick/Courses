/* Тема 01: Числа и строки: операции с ними, ввод и вывод
Урок 10: Строки
Задание 9
Перед вами знакомая программа, которая выводит на экран “Hello, friend!”. 
Измените код: создайте строковую переменную с содержимым Hello, friend! и выведите её на экран.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string greetings;
    greetings = "Hello, friend!"s;
    cout << greetings << endl;
    return 0;
}