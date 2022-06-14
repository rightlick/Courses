/* Тема 07: Map
Урок 2: Всё могут словари - контейнер map
Задание 51
Иногда нужно срочно найти что-нибудь в значениях, а быстрый поиск работает только среди ключей. Напишите функцию BuildReversedMap, которая переворачивает словарь: ключи становятся значениями, а значения — ключами.
Функция должна работать со словарями типа map<string, string>.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> BuildReversedMap(const map<string, string>& input_map) {
    // Напишите реализацию функции тут
    map<string, string> temp;
    for (const auto& [key, value] : input_map) {
        temp[value] = key;
    }
    return temp;
}

int main() {
    map<string, string> test1_input = {{"cat"s, "felis catus"s}, 
                                       {"dog"s, "canis lupus"s}};
    map<string, string> test1_output = {{"felis catus"s, "cat"s}, 
                                        {"canis lupus"s, "dog"s}};

    // Проверяем корректность BuildReversedMap на примере 
    if (BuildReversedMap(test1_input) != test1_output) {
        cout << "BuildReversedMap returned wrong dictionary"s << endl;
    }
    else {
        cout << "BuildReversedMap returned correct dictionary"s << endl;
    }

    // Добавьте ещё тесты, чтобы убедиться, что ваша функция работает верно
}