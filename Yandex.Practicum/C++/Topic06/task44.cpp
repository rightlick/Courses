/* Тема 06: Глубокое копирование, ссылки, константность
Урок 3: Ссылки
Задание 44
Напишите функцию MoveStrings. Она принимает векторы строк source и destination и дописывает все строки из первого вектора в конец второго. 
После выполнения функции вектор source должен стать пустым.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(/* укажите параметры функции */ vector<string>& source, vector<string>& destination) {
    // код функции
    for (string& word : source) {
        destination.push_back(word);
    }
    source.clear();
}

int main() {
    vector<string> source = {"how"s, "to"s, "learn"s};
    vector<string> destination = {"c++"s};
    MoveStrings(source, destination);
    // source должен оказаться пустым
    // destination должен содержать строки "c++", "how", "to", "learn" именно в таком порядке 
    for (auto now : source) {
        cout << now << " "s;
    }
    cout << endl;
    for (auto now : destination) {
        cout << now << " "s;
    }
    cout << endl;
}