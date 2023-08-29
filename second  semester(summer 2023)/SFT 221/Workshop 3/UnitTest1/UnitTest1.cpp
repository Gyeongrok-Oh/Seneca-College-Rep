#include "pch.h"
#include "CppUnitTest.h"
#include "mathfuncs_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathTestSuite
{
    TEST_CLASS(MathFuncsCTest)
    {
    public:

        TEST_METHOD(lastTest)
        {
           

            const char* validLast = "ABC";
            const char* invalidLast = "123";

            bool isValid = isValidLast(validLast);
            Assert::IsTrue(isValid); 

            isValid = isValidLast(invalidLast);
            Assert::IsFalse(isValid); 
        }

        TEST_METHOD(postalTest)
        {

            const char* validPostal = "A1B 2C3";
            const char* invalidPostal = "12345";

            bool isValid = isValidPostal(validPostal);
            Assert::IsTrue(isValid);

            isValid = isValidPostal(invalidPostal);
            Assert::IsFalse(isValid); 
        }
    };
}
