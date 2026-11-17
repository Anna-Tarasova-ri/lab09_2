//////////////////////////////////////////////////////////////////////////////
// calc.cpp
// файл реалізації – обчислення w (варіант 27)
#include "calc.h"
#include "macros.h"

double calc(double x, double y)
{
#if Z > 3
    // компілюється, якщо z > 3
    return MAX(SQR(x - Z), x - y);
#else
    // компілюється, якщо z <= 3
    return MAX(x * y, y * Z) + MAX(Z * x, y * Z);
#endif
}