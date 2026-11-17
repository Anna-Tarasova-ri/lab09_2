   /// Лабораторна робота № 9.2. Директиви препроцесора. Частина 1, варіант 27.
   /// Обчислити вираз:
   ///         | max((x - z)^2, x - y),          z > 3
   ///     w = |
   ///         | max(xy, yz) + max(zx, yz),      z <= 3
   /// Функції max(), піднесення до квадрата та виведення результатів задано
   /// макросами (macros.h). За допомогою директив умовної компіляції на основі
   /// значення z (макрос Z) препроцесор обирає, яка гілка компілюється.


#include <iostream>
#include "macros.h"    // власний заголовний файл з макросами
#include "calc.h"      // оголошення функції calc

using namespace std;

int main()
{
    cout << "Lab 9.2. Using macros and preprocessing directives" << endl;

    double x, y;       // значення задаються користувачем
    double w;          // результат
    char ch;           // відповідь: чи повторювати виконання програми

    do
    {
        cout << "Input x: "; cin >> x;
        PRINTV(x);
        cout << "Input y: "; cin >> y;
        PRINTV(y);

#if Z > 3
        cout << "branch: z > 3, z = " << Z << endl;
#else
        cout << "branch: z <= 3, z = " << Z << endl;
#endif                 // завершення блоку умовної компіляції

        w = calc(x, y);    // гілку обчислення обрано в calc.cpp за значенням Z

        PRINTR(w);

        cout << "Repeat? y/n: "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}