/* Тема 02: Условия и циклы
Урок 4: Логические операции: сравнение
Задание 19
Перед Зои три дома разного цвета. Ей известно, рядом с домом какого цвета видели последний раз её Пушистика. 
Дома имеют номера: 1, 2 и 3. Определите номер дома, с владельцем которого ей надо поговорить насчёт своего питомца.
*/

#include <iostream>

using namespace std;

int main() {
    string house1_color, house2_color, house3_color;
    
    string indication_color;
    
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;

    // Считайте информацию о трёх домах, которые видит перед собой Марта,
    cin >> house1_color >> house2_color >> house3_color;
    // а также показания очевидца.
    cin >> indication_color;
    
    if (indication_color == house1_color) flag1 = true;
    if (indication_color == house2_color) flag2 = true;
    if (indication_color == house3_color) flag3 = true;

    // Выведите номера тех домов (1, 2, 3) которые нужно посетить,
    // по одному номеру в каждой строке
    if (flag1) cout << "Enter the house " << 1 << endl;
    else if (flag2) cout << "Enter the house " << 2 << endl;
    else if (flag3) cout << "Enter the house " << 3 << endl;
    else cout << "Seek somewhere else" << endl;
}