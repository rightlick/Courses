/* Тема 03: V — значит вектор
Урок 4: Меняем размер вектора
Задание 34
В программе симуляции очереди реализуйте новую команду WORRY_COUNT. Она должна вывести количество беспокойных клиентов в очереди.
Для этого циклом пройдитесь по вектору. При появлении значения true в теле цикла прибавляйте единицу к заранее созданной переменной.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    // создайте вектор типа vector<bool> для хранения очереди
    vector <bool> queue;
  
    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;
    
        if (operation_code == "WORRY"s) {
            int index;
            cin >> index;

            // Отметьте человека по индексу index как 
            // беспокоящегося (значение true).
            queue[index] = true;
        } 
        else if (operation_code == "HAPPY"s) {
            int index;
            cin >> index;

            // Отметьте человека по индексу index как 
            // спокойного (значение false).
            queue[index] = false;
        } 
        else if (operation_code == "COME"s) {
            int count;
            cin >> count;

            // Измените размер на count. Указывайте второй параметр метода
            // resize, чтобы добавлялись только спокойные (значение false).
            queue.resize((queue.size() + count), false);
        } 
        else if (operation_code == "LAST_WORRY"s) {
            // Выведите worry, если последний человек беспокойный, и happy,
            // если спокойный
            if (queue[queue.size() - 1] ) cout << "worry" << endl;
            else cout << "happy" << endl;
        }
        else if (operation_code == "WORRY_COUNT"s) {
            int counter = 0;
            for (auto now : queue) {
                if (now)  ++counter;
            }
            cout << counter << endl;
        }
    }
}