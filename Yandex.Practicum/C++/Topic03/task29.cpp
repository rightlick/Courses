/* Тема 03: V — значит вектор
Урок 2: Создание и применение вектора
Задание 29
Напишите программу, которая считывает номер месяца в нумерации с нуля (0 — это январь, 11 — декабрь) и выводит количество дней в нём.
Требуется обработать только одно число. Цикл в этой задаче не нужен.
После того, как тренажёр примет ваше решение, не спешите переходить к следующему заданию. Попробуйте себя в роли тестировщика:
    передайте на вход программе число от 0 до 11 и получите количество дней в соответствующем месяце;
    передайте некорректное число — например, отрицательное или слишком большое — и полюбуйтесь на ошибки;
    введите не число, а другие символы — они не считаются, и в переменной останется её начальное значение. Это необязательно будет ноль.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> month_lengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month_number;
    // считайте номер месяца
    cin >> month_number;
    // и выведите количество дней в нём
    cout << month_lengths[month_number] << endl;
}