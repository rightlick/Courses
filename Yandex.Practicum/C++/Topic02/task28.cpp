/* Тема 02: Условия и циклы
Урок 7: выход из цикла
Задание 28
Оператор continue часто применяют прямо в начале цикла, чтобы отсеять ненужные случаи. Он позволяет упростить код и убрать длинный if.
В заготовке кода — программа для подсчёта чистой прибыли компании. Приходы и расходы она читает из cin, но суммирует только положительные суммы — приходы. 
Все отрицательные суммы игнорируются.
Программа прекрасно работает, но оказалось, что ревьюер, который проверял код, не знает оператор continue, поэтому заказчик требует убрать его.
Что поделаешь, слово заказчика — закон! Ухудшите код программы, не меняя её поведение, избавившись от оператора continue.
*/

#include <iostream>
using namespace std;

int main() {
    int bill;
    int sum = 0;

    do {
        cin >> bill;
        if (bill > 0) {
            cout << "Income: " << bill << endl;
            sum += bill;
        }
    // признаком конца программы будет счёт ноль
    } while (bill != 0);

    cout << "Total income: " << sum << endl;
}