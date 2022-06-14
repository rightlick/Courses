/* Тема 01: Числа и строки: операции с ними, ввод и вывод
Урок 12: Нюансы над строками
Задание 14
Напишите программу, которая считывает число (количество документов) и выводит на экран <число документов> documents found. 
Сначала сформируйте строку с ответом, только потом выведите её на экран целиком.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // ...
    int x;
    cin >> x;
    
    string message = " documents found"s;
    message = to_string(x) + message;
    
    cout << message << endl;
    return 0;
}