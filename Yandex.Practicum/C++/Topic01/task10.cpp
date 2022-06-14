/* Тема 01: Числа и строки: операции с ними, ввод и вывод
Урок 10: Строки
Задание 10
Напишите программу, которая считывает имя и фамилию, разделённые пробелом, и выводит полное имя в формате <Фамилия>, <Имя>. 
Примените оператор сложения, чтобы соединить части строк в одну строку перед выводом, либо выведите их по отдельности 
в нужном порядке.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. Считайте имя и фамилию
    string name, surname;
    cin >> name >> surname;
    
    // 2. Выведите полное имя в формате: фамилия, имя
    cout << surname << ", "s << name << endl; 
}