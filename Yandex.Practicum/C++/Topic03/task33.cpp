/* Тема 03: V — значит вектор
Урок 4: Меняем размер вектора
Задание 33
Разбиение на слова работает только в жёстких условиях: нет нескольких пробелов подряд, нет пробелов в начале и конце. 
Исправьте программу, чтобы она разбивала на слова любые строки, даже не удовлетворяющие этим ограничениям.
*/

#include <iostream>
#include <string>
// не забудьте подключить библиотеку <vector>
#include <vector>

using namespace std;

int main() {
    // Объявите переменную-вектор, которая будет хранить слова.
    // Назовите её words.
    vector <string> words;

    string query;
    getline(cin, query);

    string word;
    bool flag = false;

    // Мы заменили обычный for на range-based.
    for (char c : query) {
        if (c == ' ') {
            if (flag) {
                // Удалите вывод в cout и замените его на добавление элемента в вектор.
                //cout << '[' << word << ']' << endl;
                words.push_back(word);
                
                word = ""s;
                flag = false;
            }
        } else {
            word += c;
            flag = true;
        }
    }
    // Добавьте в вектор последнее слово вместо вывода.
    //cout << '[' << word << ']' << endl;
    if (flag) words.push_back(word);

    // Сюда вставьте вывод элементов вектора.
    for (auto word : words) {
        cout << '[' << word << ']' << endl;
    }
}