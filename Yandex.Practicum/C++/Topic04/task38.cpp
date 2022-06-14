/* Тема 04: Функции
Урок 4: Зачем нужны функции
Задание 38
Напишите функцию, которая:
    называется PalindromeFilter,
    возвращает vector<string>,
    принимает vector<string> words и int min_length,
    возвращает из вектора words все строки-палиндромы длиной не меньше min_length.
Функция PalindromeFilter должна использовать вспомогательную функцию IsPalindrome, которая определяет, будет ли переданная ей строка палиндромом.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// определяет, будет ли строка s палиндромом
bool IsPalindrome(string s) {
    for (unsigned int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromeFilter(vector<string> words, unsigned int min_length) {
    // Возвращает из words все строки-палиндромы длиной не меньше min_length
    // Эта функция должна вызывать написанную выше функцию IsPalindrome
    vector<string> polyndromic_words;
    for (auto now : words) {
        if (now.size() >= min_length) {
            if (IsPalindrome(now)) 
                polyndromic_words.push_back(now);
        }
    }
    return polyndromic_words;
}

int main () {
    string s;
    getline(cin, s);
    unsigned int min_length_input = 0;

    vector<string> words_input;
    string temp_word;
    for (auto now : s) {
        if (now == ' ') {
            words_input.push_back(temp_word);
            temp_word.clear();
        } 
        else { 
            temp_word += now;
        }
    }
    if (!temp_word.empty()) {
        words_input.push_back(temp_word);
        temp_word.clear();
    }

    for (auto now : PalindromeFilter(words_input, min_length_input)) {
        cout << now << " ";
    } 
    cout << endl;
}