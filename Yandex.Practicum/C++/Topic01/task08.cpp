/* Тема 01: Числа и строки: операции с ними, ввод и вывод
Урок 9: Работа над ошибками
Задание 8
Не все ошибки удаётся обнаружить во время компиляции программы. Некоторые из них доживают до момента её запуска. 
Перед вами код программы, которая должна считывать числа типа double и выводить их сумму. В коде есть ошибка. Исправьте её.
*/

#include <iostream>

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;
    cout << x + y;
}