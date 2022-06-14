/* Тема 04: Функции
Урок 3: Возврат значения и ошибки
Задание 36
В прошлой теме вы усовершенствовали разбиение строки на слова: создали и заполнили вектор строк words. 
Теперь вынесите разбиение в отдельную функцию vector<string> SplitIntoWords(string text), которая принимает на вход строку и возвращает вектор слов.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (char c : text) {
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
		string query;
		getline(cin, query);
        SplitIntoWords(query);
    /*vector<string> words;
    string word;
    for (char c : query) {
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
    }*/
		
		/*for (string word : words) {
				cout << '[' << word << ']' << endl;
		}*/   
}