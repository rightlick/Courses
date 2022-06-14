/* Тема 02: Условия и циклы
Урок 2: Условный оператор if
Задание 17
В предыдущей теме вы написали код программы, которая:
считывает число — количество документов;
выводит на экран, сколько документов найдено: <число документов> documents found.
Программа работает, но слово “document” всегда пишет во множественном числе — например, 1 documents found. 
Отредактируйте код. Если на вход дан 0, пусть программа выводит No documents found, если 1 — One document found. 
Во всех остальных случаях программа должна выводить <число документов> documents found.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int document_count;
    cin >> document_count;
    string message;
    
    if (document_count == 0) {
        message = "No documents found"s;
    }
    else if (document_count == 1) {
        message = "One document found"s;
    }
    else {
        message = to_string(document_count) + " documents found"s;
    }
    
    cout << message << endl;
}