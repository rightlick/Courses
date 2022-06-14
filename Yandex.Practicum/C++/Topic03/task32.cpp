/* Тема 03: V — значит вектор
Урок 3: Лаконичный for и добавление элементов в вектор
Задание 32
Не так давно вы разбивали строку на слова. В заготовке кода — решение той задачи. 
Теперь примените вектор, чтобы сохранить все слова в вектор. Затем их нужно вывести на экран.
Вектор строк назовите words — имя переменной будет учитываться при проверке.
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

    // Мы заменили обычный for на range-based.
    for (char c : query) {
        if (c == ' ') {
            // Удалите вывод в cout и замените его на добавление элемента в вектор.
            //cout << '[' << word << ']' << endl;
            words.push_back(word);
            word = ""s;
        } else {
            word += c;
        }
    }
    // Добавьте в вектор последнее слово вместо вывода.
    //cout << '[' << word << ']' << endl;
    words.push_back(word);

    // Сюда вставьте вывод элементов вектора.
    for (auto word : words) {
        cout << '[' << word << ']' << endl;
    }
}