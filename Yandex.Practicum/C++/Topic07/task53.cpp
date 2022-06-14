/* Тема 07: Map
Урок 4: Словари и константность
Задание 53
Представьте, что провели выходные за бёрдвотчингом. Вооружившись биноклем, блокнотом и фотоаппаратом с огромным объективом, вы два дня просидели в кустах у большого водоёма. Чтобы не спугнуть птиц, вы боялись пошевелиться, и записи получились не очень хорошо структурированными. Все статистические данные вы решили посчитать, когда фотографии будут готовы. Теперь они готовы, и каждая фотография подписана именем птицы, изображённой на ней. Каждая птица сфотографирована только единожды, но птицы могли быть одного вида. Используйте эти данные и определите самую распространённую птицу в этих краях.
Напишите функцию FindWidespreadBird, принимающую на вход вектор названий птиц и возвращающую самую популярную из них.
*/

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string FindWidespreadBird(const vector<string>& types) {
    // напишите здесь ваше решение
    map<string, int> bird_met;
    string popular_bird;
    int max = 0;

    for (auto& type : types) {
        ++bird_met[type];
    }

    for (auto [bird, count] : bird_met) {
        if (max < count) {
            max = count;
            popular_bird = bird;
        }
    }
   
    return popular_bird;
}

int main() {
    vector<string> bird_types1 = {"zyablik"s, "sinica"s, "vorobey"s, "zyablik"s, "sinica"s, "sinica"s};
    if (FindWidespreadBird(bird_types1) == "sinica"s) {
        cout << "Correct"s << endl;
    } else {
        cout << "Not correct"s << endl;
    }

    vector<string> bird_types2 = {"ruh"s, "sirin"s, "blue bird of fortune"s, "finist"s, "fenix"s};
    if (FindWidespreadBird(bird_types2) == "blue bird of fortune"s ) {
        cout << "Correct"s << endl;
    } else {
        cout << "Not correct"s << endl;
    }
}