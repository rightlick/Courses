/* Тема 06: Глубокое копирование, ссылки, константность
Урок 7: Ядро поисковой системы
Задание 50
Напишите реализацию поиска по базе документов. Используйте следующий алгоритм:
Взять очередной документ из базы документов. Вы уже знаете, что это вектор слов документа.
Добавить индекс документа в результаты поиска, если среди слов этого документа встречаются слова из поискового запроса.
Повторить эти действия для оставшихся документов.
Так как в базе документов не содержатся стоп-слова, лучше сразу исключить их из поискового запроса.
Сигнатура функции поиска должны выглядеть так:
// Возвращает массив id документов, подходящих под запрос query
// Стоп-слова исключаются из поиска
vector<int> FindDocuments(const vector<vector<string>>& documents, const set<string>& stop_words,
                          const string& query) {
    // Напишите код функции
} 
Вам также понадобятся вспомогательные функции:
ParseQuery — разбирает текст запроса на слова, исключая из них стоп-слова.
MatchDocument — проверяет, подходит ли документ под критерии поискового запроса.
Используйте эти функции, чтобы реализовать функцию FindDocuments. Их сигнатуры:
// Разбирает text на слова и возвращает только те из них, которые не входят в stop_words
set<string> ParseQuery(const string& text, const set<string>& stop_words) {
    // Напишите код функции
}

// Возвращает true, если среди слов документа (document_words)
// встречаются слова поискового запроса query_words
bool MatchDocument(const vector<string>& document_words, const set<string>& query_words) {
    // Напишите код функции
} 
Функция main из заготовки кода считывает стоп-слова, документы и поисковый запрос. Затем она выводит результаты поиска: id документов, соответствующих поисковому запросу.
Требования
Разные слова могут встречаться в одних и тех же документах. Верните результат поиска без повторов.
Не меняйте сигнатуру FindDocuments.
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result = 0;
    cin >> result;
    ReadLine();
    return result;
}

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

set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    // проходим по всем словам из текста и проверяем, что их нет в списке стоп-слов
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    // вернём результат без стоп-слов
    return words;
}

void AddDocument(vector<vector<string>>& documents, const set<string>& stop_words, const string& document) {
    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
    documents.push_back(words);
}

// Разбирает text на слова и возвращает только те из них, которые не входят в stop_words
set<string> ParseQuery(const string& text, const set<string>& stop_words) {
    set<string> query_words;

    // Напишите код функции
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            query_words.insert(word);
        }
    }

    return query_words;
}

// Возвращает true, если среди слов документа (document_words)
// встречаются слова поискового запроса query_words
bool MatchDocument(const vector<string>& document_words, const set<string>& query_words) {
    // Напишите код функции
    for (const string& word : document_words) {
        if (query_words.count(word) > 0) {
            return true;
        } 
    }
    return false;
}

// Возвращает массив id документов, подходящих под запрос query
// Стоп-слова исключаются из поиска
vector<int> FindDocuments(const vector<vector<string>>& documents, const set<string>& stop_words, const string& query) {
    vector<int> matched_documents;

    // Напишите код функции
    // Воспользуйте вспомогательными функциями ParseQuery, MatchDocument
    // В качестве id документа используйте его индекс в массиве documents
    for (unsigned int i = 0; i < documents.size(); ++i) {
        vector<string> temp = documents[i];
        if (MatchDocument(temp, ParseQuery(query, stop_words))) {
            matched_documents.push_back(i);
        }
    }

    return matched_documents;
}

int main() {
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read documents
    vector<vector<string>> documents;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        AddDocument(documents, stop_words, ReadLine());
    }

    const string query = ReadLine();
    for (const int document_id : FindDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id << " }"s << endl;
    }
}