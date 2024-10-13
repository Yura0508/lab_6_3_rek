#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_6_3_rek/lab_6_3_rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestIFirst)
        {
            int a[10] = { 2, 4, 1, 3, 5, 8, 10, 12, 13, 14 };
            int min;
            int index = IFirst(a, 10, min, 0);

            Assert::AreEqual(2, index);
            Assert::AreEqual(1, min);   
        }

        TEST_METHOD(TestMin)
        {
            int a[10] = { 2, 4, 1, 3, 5, 8, 10, 12, 13, 14 };
            int min = 1;
            int firstIndex = IFirst(a, 10, min, 0);
            int result = Min(a, 10, min, firstIndex + 1);

            Assert::AreEqual(1, result); 
        }

        TEST_METHOD(TestNoOddElements)
        {
            int a[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
            int min;
            int index = IFirst(a, 10, min, 0);

            Assert::AreEqual(-1, index); 
        }
    };
}