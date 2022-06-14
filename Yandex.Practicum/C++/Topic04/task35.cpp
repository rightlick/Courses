/* Тема 04: Функции
Урок 2: Функция, вас вызывают!
Задание 35
Напишите функцию IsPalindrome(string), которая проверяет, будет ли строка палиндромом. 
Если строка — палиндром, пусть функция печатает 1, а если нет — 0. Пустая строка считается палиндромом.
*/

#include <iostream>
#include <string>

using namespace std;

void IsPalindrome(string s) {
    // нужно понять, будет ли s палиндромом
    bool flag = true;
    
    if (s.empty()) {
        cout << 1 << endl;
    }
    else {
        for (unsigned int i = 0; i < s.size(); ++i) {
            if (s[i] != s[(s.size() - 1 - i)]) 
                flag = false;
        }
        if (flag) 
            cout << 1 << endl;
        else 
            cout << 0 << endl;
    }
}

int main() {
    //IsPalindrome("ara"s);
    //IsPalindrome("deer"s);
    string input_string;
    cin >> input_string;
    IsPalindrome(input_string);
}