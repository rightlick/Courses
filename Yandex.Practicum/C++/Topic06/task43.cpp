/* Тема 06: Глубокое копирование, ссылки, константность
Урок 3: Ссылки
Задание 43
Представьте, что собираете данные очевидцев о том, где они видели пропавшего кота. Чтобы очертить круг поисков, нужно вычислить максимальное расстояние, на которое кот удалился от дома.
Текущее максимальное расстояние лежит в целочисленной переменной max_distance. Каждое новое свидетельство очевидца — это целое число с расстоянием. И оно может увеличить max_distance.
Напишите функцию UpdateIfGreater, принимающую два целочисленных аргумента: limit и value. Если limit окажется больше value, пусть функция запишет в value значение параметра limit. Нужно, чтобы изменение параметра value было видно на вызывающей стороне. Возвращать и выводить функция ничего не должна.
*/

#include <iostream>
#include <string>

using namespace std;

void UpdateIfGreater(/* какой тут тип? */ int limit, /* а тут? */int& value) {
	  // код функции
    if (limit > value) {
        value = limit;
    }
}

int main() {
    int max_distance = 26;
    UpdateIfGreater(25, max_distance);
    cout << max_distance << endl;  // выведет 26, так как 25 не больше 26
    UpdateIfGreater(40, max_distance);
    cout << max_distance << endl;  // выведет 40, так как 40 больше 26 
}