/* Тема 06: Глубокое копирование, ссылки, константность
Урок 2: Глубокое копирование
Задание 42
Посмотрите на код, разбивающий текст на слова с учётом стоп-слов. Избавьтесь от лишних копирований в заголовках функций и в циклах for. 
Для этого допишите к типам амперсанды в нужных участках кода. Тип string замените на string&, set<string> — на set<string>&. 
Как именно это работает, узнаете в следующем уроке.
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


vector<string> SplitIntoWords(string& text) {
    vector<string> words;
    string word;
    for (unsigned int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            words.push_back(word);
            word = ""s;
        } else {
            word += text[i];
        }
    }
    words.push_back(word);
    
    return words;
}

set<string> ParseStopWords(string& text) {
    set<string> stop_words;
    for (string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> ParseQuery(string& text, set<string>& stop_words) {
    vector<string> words;
    for (string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

int main() {
    // Read stop words
    string stop_words_joined;
    getline(cin, stop_words_joined);
    set<string> stop_words = ParseStopWords(stop_words_joined);
    
    // Read query
    string query;
    getline(cin, query);
    vector<string> query_words = ParseQuery(query, stop_words);
    
    for (string& word : query_words) {
        cout << '[' << word << ']' << endl;
    }
}