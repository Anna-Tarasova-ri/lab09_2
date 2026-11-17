//////////////////////////////////////////////////////////////////////////////
// UnitTest.cpp
// unit-тест функції calc() – лабораторна робота 9.2, частина 1, варіант 27
// (проєкт Native Unit Test Project, Microsoft CppUnitTest)
#include "pch.h"
#include "CppUnitTest.h"
#include "../PR9_2_1/macros.h"   // макрос Z
#include "../PR9_2_1/calc.h"     // функція calc
#include "../PR9_2_1/calc.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest9_2
{
    TEST_CLASS(UnitTest9_2)
    {
    public:

#if Z > 3
        // гілка z > 3:  w = max((x - z)^2, x - y)   (для Z = 5)

        TEST_METHOD(SquareIsMax)
        {
            // (10 - 5)^2 = 25, x - y = 10  ->  25
            Assert::AreEqual(25.0, calc(10, 0), 1e-9);
        }

        TEST_METHOD(DifferenceIsMax)
        {
            // (5 - 5)^2 = 0, x - y = 105  ->  105
            Assert::AreEqual(105.0, calc(5, -100), 1e-9);
        }

        TEST_METHOD(NegativeValues)
        {
            // (1 - 5)^2 = 16, x - y = -1  ->  16
            Assert::AreEqual(16.0, calc(1, 2), 1e-9);
        }

#else
        // гілка z <= 3:  w = max(xy, yz) + max(zx, yz)   (для Z = 2)

        TEST_METHOD(PositiveValues)
        {
            // max(2, 4) + max(2, 4) = 8
            Assert::AreEqual(8.0, calc(1, 2), 1e-9);
        }

        TEST_METHOD(ZeroValues)
        {
            Assert::AreEqual(0.0, calc(0, 0), 1e-9);
        }

        TEST_METHOD(NegativeValues)
        {
            // x = -1, y = -2: max(2, -4) + max(-2, -4) = 2 + (-2) = 0
            Assert::AreEqual(0.0, calc(-1, -2), 1e-9);
        }
#endif
    };
}