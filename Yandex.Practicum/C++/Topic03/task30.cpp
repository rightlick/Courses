/* Тема 03: V — значит вектор
Урок 2: Создание и применение вектора
Задание 30
Улучшите предыдущую программу. Добавьте в неё следующие возможности:
    Нумерацию месяцев ведите не с нуля, а как в жизни: май — пятый месяц, декабрь — двенадцатый.
    Добавьте обработку ошибок. Если пользователь ввёл номер несуществующего месяца, выведите текст Incorrect month.
    Вместо сиротливого числа выведите полноценную фразу, например There are 31 days in January.
Для реализации последнего пункта заведите второй вектор типа vector<string>, в который нужно сложить названия месяцев на английском:
1   January
2   February
3   March
4   April
5   May
6   June
7   July
8   August
9   September
10  October
11  November
12  December
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> month_lengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> month_names = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month_number;
    // считайте номер месяца
    cin >> month_number;
    // и выведите количество дней в нём
    if ((month_number < 1) || (month_number > 12)) {
        cout << "Incorrect month"s << endl;
    }
    else {
        cout << "There are "s << month_lengths[month_number - 1] << " days in "s << month_names[month_number - 1] << endl;
    }
}