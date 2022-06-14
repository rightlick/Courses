/* Тема 05: Set
Урок 3: Плюсы множеств
Задание 40
Представьте, что анализируете запросы пользователей в вашей поисковой системе. Есть слова запроса и описание животного. 
Посчитайте релевантность запроса — размер множества слов, которые входят и в запрос, и в описание. 
Для этого доработайте функцию CalculateSimilarity из заготовки кода так, чтобы она вернула релевантность.
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int CalculateSimilarity(vector<string> first, vector<string> second) {
    // верните размер пересечения множеств слов first и second
    set<string> set_first, set_second;
    
    for (auto now : first) {
        set_first.insert(now);
        //cout << now << endl;
    }
    for (auto now : second) {
        set_second.insert(now);
        //cout << now << endl;
    }
    
    int count_similarity = 0;
    
    for (auto now : set_first) {
        if (set_second.count(now))
            ++count_similarity;
    }
    return count_similarity;
}

// SplitIntoWords разбивает строку text на слова и возвращает их в виде вектора
// Слово - последовательность непробельных символов,
// разделённых одним или более пробелов.
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
    string query, description;

    getline(cin, query);
    getline(cin, description);

    cout << CalculateSimilarity(SplitIntoWords(query), SplitIntoWords(description)) << endl;
}