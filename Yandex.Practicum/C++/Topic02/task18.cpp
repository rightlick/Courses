/* Тема 02: Условия и циклы
Урок 3: Логические операции "и", "или", "не"
Задание 18
У Марты потерялся кот Маркиз. Прохожий сказал ей, что видел похожего кота у одного из трёх домов около почтового отделения. 
На вопрос, у какого из домов он видел Маркиза, прохожий может вспомнить цвет дома, а также количество этажей в доме. 
Возможна ситуация, когда прохожий забыл часть информации или вообще всё.
Напишите программу, которая на основе показаний прохожего помогает принять Марте решение, в какие из трёх домов нужно зайти.
Формат входных и выходных данных
На вход программы подаются следующие данные, разделяемые пробелом:
цвет первого дома и количество этажей в нём,
цвет второго дома и количество этажей в нём,
цвет третьего дома и количество этажей в нём,
цвет дома и количество этажей, которые сообщил прохожий. Если прохожий не помнит цвет дома или этажность, 
вместо цвета подаётся строка ? (вопросительный знак), а вместо количества этажей — число -1.
Программа должна вывести в порядке возрастания номера домов, в которые Марте надо зайти, по одному в каждой строке. 
Номера домов выводятся в виде чисел 1, 2 или 3. Номера домов, которые посещать не нужно, выводиться не должны.
*/

#include <iostream>

using namespace std;

int main() {
    string house1_color, house2_color, house3_color;
    int house1_floors, house2_floors, house3_floors;
    
    string indication_color;
    int indication_floors;
    
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;

    // Считайте информацию о трёх домах, которые видит перед собой Марта,
    cin >> house1_color >> house1_floors >> house2_color >> house2_floors >> house3_color >> house3_floors;
    // а также показания очевидца.
    cin >> indication_color >> indication_floors;
    
    if ((indication_color == "?") && (indication_floors == -1)) {
        flag1 = true;
        flag2 = true;
        flag3 = true;
    }
    else if ((indication_color != "?") && (indication_floors == -1)) {
        if (indication_color == house1_color) flag1 = true;
        if (indication_color == house2_color) flag2 = true;
        if (indication_color == house3_color) flag3 = true;
    }
    else if ((indication_color == "?") && (indication_floors != -1)) {
        if (indication_floors == house1_floors) flag1 = true;
        if (indication_floors == house2_floors) flag2 = true;
        if (indication_floors == house3_floors) flag3 = true;
    }
    else if ((indication_color != "?") && (indication_floors != -1)) {
        if ((indication_color == house1_color) && (indication_floors == house1_floors)) flag1 = true;
        if ((indication_color == house2_color) && (indication_floors == house2_floors)) flag2 = true;
        if ((indication_color == house3_color) && (indication_floors == house3_floors)) flag3 = true;
    }
    // Выведите номера тех домов (1, 2, 3) которые нужно посетить,
    // по одному номеру в каждой строке
    if (flag1) cout << 1 << endl;
    if (flag2) cout << 2 << endl;
    if (flag3) cout << 3 << endl;
} 