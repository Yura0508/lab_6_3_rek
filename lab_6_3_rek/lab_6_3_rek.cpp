// lab_6_3_rek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Функція для генерації масиву
void Create(int* a, const int size, const int Low, const int High, int i) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Функція для виведення масиву
void Print(const int* a, const int size, int i) {
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}


int IFirst(int* a, const int size, int& min, int i)
{
    if (a[i] % 2 != 0)
    {
        min = a[i]; 
        return i; 
    } 
    if (i < size - 1)
        return IFirst(a, size, min, i + 1);
    else
        return -1;
}
int Min(int* a, const int size, int min, int i)
{
    if (a[i] < min && a[i] % 2 != 0)
        min = a[i];
    if (i < size - 1)
        return Min(a, size, min, i + 1);
    else
        return min;
}
void SeparateOdds(int* a, int* newArray, const int size, int& index, int currentIndex) {
    if (currentIndex == size) return;

    if (a[currentIndex] % 2 != 0) {
        newArray[index++] = a[currentIndex];
    }

    SeparateOdds(a, newArray, size, index, currentIndex + 1);
}


int Min2(int* newArray, const int size, int index = 0, int min = 0) {
    if (index == size) {
        if (min == 0) {
            return 0; 
        }
        else {
            return min; 
        }
    }
    if (index == 0) {
        min = newArray[index];
    }
    if (newArray[index] < min) {
        min = newArray[index];
    }
    return Min2(newArray, size, index + 1, min);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    const int size = 10;
    int a[size];
    const int Low = -10;
    const int High = 20;

    // Генерація масиву
    Create(a, size, Low, High, 0);
    cout << "massif a:" << endl;
    Print(a, size, 0);

 
    int min; 
    int imax = IFirst(a, size, min, 0);
    if (imax == -1)
        cerr << "there are no elements that satisfy the condition" << endl;
    else
        cout << "min = " << Min(a, size, min, imax + 1) << endl;
    int newSize = 0;
    int* separatedArray = new int[size]; 
    SeparateOdds(a, separatedArray, size, newSize, 0);

    cout << "now massif:" << endl;
    Print(separatedArray, newSize, 0);
    cout << "min = " << Min2(separatedArray, newSize) << endl;

    delete[] separatedArray;
    cin.get();
    return 0;
}






/*


#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Функція для генерації масиву
template<typename T>
void Create(T* a, const T size, const T Low, const T High, T i) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Функція для виведення масиву
template<typename T>
void Print(const T* a, const T size, T i) {
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

template<typename T>
int IFirst(T* a, const T size, T& min, T i)
{
    if (a[i] % 2 != 0)
    {
        min = a[i];
        return i;
    }
    if (i < size - 1)
        return IFirst(a, size, min, i + 1);
    else
        return -1;
}

int Min(int* a, const int size, int min, int i)
{
    if (a[i] < min && a[i] % 2 != 0)
        min = a[i];
    if (i < size - 1)
        return Min(a, size, min, i + 1);
    else
        return min;
}


int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    const int size = 10;
    int a[size];
    const int Low = -10;
    const int High = 20;

    // Генерація масиву
    Create(a, size, Low, High, 0);
    cout << "massif a:" << endl;
    Print(a, size, 0);


    int min;
    int imax = IFirst(a, size, min, 0);
    if (imax == -1)
        cerr << "there are no elements that satisfy the condition" << endl;
    else
        cout << "min = " << Min(a, size, min, imax + 1) << endl;
    cin.get();
    return 0;
} */