/* Тема 06: Глубокое копирование, ссылки, константность
Урок 5: Хитрости константных ссылок
Задание 47
Поэкспериментируйте с вызовом функции SplitIntoWords, которая принимает строку по константной ссылке. 
Передайте в неё текст test search query и выведите полученные слова в квадратных скобках.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> SplitIntoWords(const string& text) {
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
	// ваш код
    //string temp = "test search query"s;
    for (string& now : SplitIntoWords("test search query"s)) {
        cout << '[' << now << ']' << ' ';
    }
}