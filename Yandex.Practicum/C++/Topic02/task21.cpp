/* Тема 02: Условия и циклы
Урок 4: Логические операции: сравнение
Задание 21
Вы узнали, как сравнивать неравные объекты. С равными объектами то же самое, только оператор сравнения будет ==. 
Напишите код, который сравнивает половины апельсина. Программа считывает два вещественных числа — размеры половинок. 
Если числа равны, программа должна выводить на экран The orange is divided into two equal parts. 
Если первое число больше, пусть программа выводит Cut off X from the first part. 
Если больше второе число — пусть выводит Cut off X from the second part. Вместо X подставьте разницу в размере.
*/

#include <iostream>

using namespace std;

int main() {
    float x, y;
    cin >> x >> y;

    if (x == y) cout << "The orange is divided into two equal parts"s << endl;
    else if (x > y) cout << "Cut off "s << x - y << " from the first part"s << endl;
    else if (x < y) cout << "Cut off " << y - x << " from the second part"s << endl;
}