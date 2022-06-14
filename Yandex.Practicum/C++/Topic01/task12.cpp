/* Тема 01: Числа и строки: операции с ними, ввод и вывод
Урок 11: Символы
Задание 12
Считайте из стандартного ввода пять слов и выведите первые символы введённых строк слитно. 
Под словом понимается последовательность символов, таких как буквы, цифры, знаки препинания. 
Слова разделяются одним пробелом.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // считайте пять слов и выведите их первые символы слитно
    string first_characters;
    
    for (int i = 0; i < 5; ++i) {
        string current_word;
        cin >> current_word;
        first_characters += current_word[0];
    }
    
    cout << first_characters << endl;
}