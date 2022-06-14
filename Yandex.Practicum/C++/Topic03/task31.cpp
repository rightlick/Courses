/* Тема 03: V — значит вектор
Урок 2: Создание и применение вектора
Задание 31
В английском языке числительные строятся примерно как в русском — числа до двадцати имеют самостоятельные имена: 
0 — zero, 1 — one, 2 — two, 3 — three, 4 — four, 5 — five, 6 — six, 7 — seven, 8 — eight, 9 — nine, 10 — ten, 11 — eleven, 12 — twelve, 13 — thirteen, 14 — fourteen, 15 — fifteen, 16 — sixteen, 17 — seventeen, 18 — eighteen, 19 — nineteen.
В числах от 20 до 99 десятки и единицы записываются через дефис. Например: 24 — twenty-four, 48 — forty-eight. 
Десятки называются так: 20 — twenty, 30 — thirty, 40 — fourty, 50 — fifty, 60 — sixty, 70 — seventy, 80 — eighty, 90 — ninety.
Напишите программу для превращения чисел в текст на английском языке. Пока что достаточно ограничиться двузначными числами.
Все английские слова даны в заготовке кода.
*/

// Самостоятельно впишите нужные #include.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> tens_names = {"twenty"s, "thirty"s, "fourty"s, "fifty"s, 
                                 "sixty"s, "seventy"s, "eighty"s, "ninety"s};

    vector<string> num_names = { "zero"s, "one"s, "two"s, "three"s, "four"s, "five"s, 
                                 "six"s, "seven"s, "eight"s, "nine"s, "ten"s, "eleven"s, 
                                 "twelve"s, "thirteen"s, "fourteen"s, "fifteen"s, 
                                 "sixteen"s, "seventeen"s, "eighteen"s, "nineteen"s};
    int number;
    cin >> number;

    // Вычислим единицы и десятки как остаток и частное:
    int units = number % 10;
    int tens = number / 10;
    //cout << units << ' ' << tens << endl;

    // Выведите число, используя векторы, которые даны выше.
    // Если число меньше 20, то выведите элемент из num_names.
    // Иначе, если единицы равны нулю, то выведите элемент tenth_names.
    // Иначе выведите через дефис значения из tenth_names и num_names. 
    if (number < 20) {
        cout << num_names[number] << endl;
    }
    else if ((number >= 20) && (units == 0)) {
        cout << tens_names[tens - 2] << endl;
    }
    else {
        cout << tens_names[tens - 2] << '-' << num_names[units] << endl;
    }
}