/* Тема 05: Set
Урок 2: Как работают множества
Задание 39
Множества позволяют оставлять в наборе элементов только уникальные. Найдите, сколько уникальных строк ввёл пользователь.
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    // считываем число строк
    int n;
    cin >> n;
    // создаём множество
    set<string> user_strings;
    // заполняем его строками и выводим размер
    for (int i = 0; i < n; ++i) {
        string current_string;
        cin >> current_string;
        user_strings.insert(current_string);
    }
    cout << user_strings.size() << endl;
    return 0;
}