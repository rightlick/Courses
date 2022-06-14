/* Тема 07: Map
Урок 5: Контейнер map
Задание 54
Не всегда ответ на запрос соответствует ожиданиям. Чем результат ближе к ожидаемому, тем выше его релевантность запросу. Релевантностью документа называют количество уникальных слов, которые пересекаются с запросом. Научите свою поисковую систему считать релевантность документа.
Релевантность нужно возвращать вместе с идентификатором документа как пару из двух целых чисел {document_id, relevance}. Иными словами, функция FindDocuments теперь должна выглядеть так:
    vector<pair<int, int>> FindDocuments(const vector<pair<int, vector<string>>>& documents,
                                        const set<string>& stop_words,
                                        const string& query) {
    } 
Сама структура базы данных тоже должна измениться. Теперь каждый документ надо представить не в виде vector<string>, а в виде pair<int, vector<string>>. Первый элемент пары хранит id документа, а второй — вектор его слов. Функция AddDocument также должна изменить сигнатуру:
    void AddDocument(vector<pair<int, vector<string>>>& documents,
                    const set<string>& stop_words,
                    int document_id, 
                    const string& document) {
    } 
Вспомогательная функция MatchDocument раньше сообщала, соответствует ли документ поисковому запросу. Теперь она должна изменить сигнатуру и будет возвращать релевантность документа:
    int MatchDocument(const pair<int, vector<string>>& content, 
                    const set<string>& query_words) {
    } 
*/

#include <iostream>
#include <set>
#include <string>
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
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

void AddDocument(vector<pair<int, vector<string>>>& documents,
                 const set<string>& stop_words,
                 int document_id, 
                 const string& document) {
    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);

    documents.push_back({document_id, words});

}

set<string> ParseQuery(const string& text, const set<string>& stop_words) {
    set<string> query_words;
    for (const string& word : SplitIntoWordsNoStop(text, stop_words)) {
        query_words.insert(word);
    }
    return query_words;
}

int MatchDocument(const pair<int, vector<string>>& content, const set<string>& query_words) {
    int relevance = 0;
    vector<string> temp = content.second;
    
    for (const auto& now : temp) {
        if (query_words.count(now) != 0) {
            ++relevance;
        }
    }
    return relevance;
}

// Для каждого найденного документа возвращает его id  
// Релевантность нужно возвращать вместе с идентификатором документа как пару из двух целых чисел {document_id, relevance}
vector<pair<int, int>> FindDocuments(const vector<pair<int, vector<string>>>& documents, 
                                     const set<string>& stop_words, 
                                     const string& query) {
    const set<string> query_words = ParseQuery(query, stop_words);
    vector<pair<int, int>> id_and_relevance;
    for (const auto& now : documents) {
        int relevance = MatchDocument(now, query_words);
        if (relevance > 0) {
            id_and_relevance.push_back({now.first, relevance});
        }
    }
    return id_and_relevance;
}

int main() {
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Считываем документы
    vector<pair<int, vector<string>>> documents;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        AddDocument(documents, stop_words, document_id, ReadLine());
    }

    const string query = ReadLine();
    // Выводим результаты поиска по запросу query
    for (auto [document_id, relevance] : FindDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s
             << endl;
    }
} 