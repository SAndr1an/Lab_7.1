#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h> 
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand((unsigned)time(NULL));
    const int Low = -41;
    const int High = 23;
    const int rowCount = 7;
    const int colCount = 9;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    cout << "Початкова матриця:\n";
    Print(a, rowCount, colCount);

    int S = 0, k = 0;
    Calc(a, rowCount, colCount, S, k);
    cout << "Сума елементів за умовою: " << S << endl;
    cout << "Кількість елементів за умовою: " << k << endl;

    cout << "Матриця після обнулення:\n";
    Print(a, rowCount, colCount);

    Sort(a, rowCount, colCount);
    cout << "Матриця після впорядкування:\n";
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Change(int** a, const int row1, const int row2, const int colCount)
{
    for (int j = 0; j < colCount; j++)
        swap(a[row1][j], a[row2][j]);
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] > 0 && (i % 2 == 1 || j % 2 == 1))
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
        }
    }
}

void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount - 1; i++)
    {
        for (int j = 0; j < rowCount - i - 1; j++)
        {
            if ((a[j][0] > a[j + 1][0]) ||
                (a[j][0] == a[j + 1][0] && a[j][1] > a[j + 1][1]) ||
                (a[j][0] == a[j + 1][0] && a[j][1] == a[j + 1][1] && a[j][2] < a[j + 1][2]))
            {
                Change(a, j, j + 1, colCount);
            }
        }
    }
}
