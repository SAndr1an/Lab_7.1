#include "pch.h"
#include "CppUnitTest.h"
#include <iomanip>
#include <numeric>

extern void Sort(int** a, const int rowCount, const int colCount);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(MatrixFunctionsTests)
	{
	public:
		TEST_METHOD(TestSort)
		{
			const int rowCount = 4;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 5; a[0][1] = 2; a[0][2] = 8;
			a[1][0] = 1; a[1][1] = 3; a[1][2] = 4;
			a[2][0] = 5; a[2][1] = 2; a[2][2] = 1;
			a[3][0] = 1; a[3][1] = 3; a[3][2] = 9;

			Sort(a, rowCount, colCount);

			Assert::AreEqual(1, a[0][0]);
			Assert::AreEqual(3, a[0][1]);
			Assert::AreEqual(9, a[0][2]);

			Assert::AreEqual(1, a[1][0]);
			Assert::AreEqual(3, a[1][1]);
			Assert::AreEqual(4, a[1][2]);

			Assert::AreEqual(5, a[2][0]);
			Assert::AreEqual(2, a[2][1]);
			Assert::AreEqual(8, a[2][2]);

			Assert::AreEqual(5, a[3][0]);
			Assert::AreEqual(2, a[3][1]);
			Assert::AreEqual(1, a[3][2]);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}