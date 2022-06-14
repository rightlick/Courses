/* Тема 07: Map
Урок 3: Подводные камни map
Задание 52
Слова называются анаграммами, если одно из них можно получить перестановкой букв в другом. Например, “eat” и “tea” — анаграммы, потому что состоят из одних и тех же букв в разном порядке.
Слова “battle” и “beatle” — не анаграммы. В первом две буквы “t”, а во втором две “e”.
Напишите функцию CheckAnagram, которая принимает два слова и возвращает true, если они анаграммы.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool CheckAnagram(const string& s1, const string& s2) {
    // напишите решение тут
    map<char, int> letters_s1, letters_s2;
    for (const auto& now : s1) {
        ++letters_s1[now];
    }
    for (const auto& now : s2) {
        ++letters_s2[now];
    }

    return (letters_s1 == letters_s2);
}

// напишем небольшую функцию для проверки
void CheckIsTrue(bool value) {
    if (value) {
        cout << "Test passed :)"s << endl;
    } else {
        cout << "Test failed :("s << endl;
    }
}

int main() {
    CheckIsTrue(CheckAnagram("tea"s, "eat"s));
    CheckIsTrue(!CheckAnagram("battle"s, "beatle"s));
    CheckIsTrue(!CheckAnagram("lift"s, "elevator"s));
    CheckIsTrue(CheckAnagram("ocean"s, "canoe"s));
}