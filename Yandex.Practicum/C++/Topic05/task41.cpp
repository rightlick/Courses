/* Тема 05: Set
Урок 4: Как set делает поисковую систему точнее
Задание 41
Научите свою поисковую систему отбрасывать стоп-слова. 
Для этого напишите программу, которая считывает стоп-слова и строку-запрос и выводит те слова запроса, которых нет среди запрещённых.
Формат вывода слов оставьте как в заготовке кода. Функция разбиения строки на слова у вас уже реализована, осталось сделать фильтрацию.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;


vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}


int main() {
    /* Считайте строку со стоп-словами */
    string stop_words;
    getline(cin, stop_words);
    
    vector<string> temp = SplitIntoWords(stop_words);
    
    set<string> set_stop_words(temp.begin(), temp.end());
    
    // Считываем строку-запрос
    string query;
    getline(cin, query);
    
    // Выведите только те слова, которых нет среди стоп-слов
    for (string word : SplitIntoWords(query)) {
        if (!set_stop_words.count(word))
            cout << '[' << word << ']' << endl;
    }
}