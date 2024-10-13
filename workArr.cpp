/*
Автор: Игонин Владимир Юрьевич ИВТ-23
Часть модуля, файл содержащий заголовки функций и тела функций для заполнения, заполнения случайными числами, вывода массива, вычисления по формуле и проверки достоверности функций
*/
//директива include отвечает за включение содержимого другого файла в компилируемый файл
//библиотека C++ с классами, функциями и переменными для организации ввода-вывода(для функций cin, cout)
#include <iostream>
//библиотека C++ с функциями общих математических операций и преобразований(для abs)
#include <cmath>
//библиотека C++ с функцией с инструментом отладки(для assert)
#include <cassert>
//Библиотека C++ для работы с векторами(динамический массив)
#include <vector>
//Библиотека C++ для работы с файловыми потоками(функции ofstream, ifstream)
#include <fstream>
//используем пространство имен std для того, чтобы не писать перед функциями стандартных библиотек(cin, cout и т.д.) std
using namespace std;

//Создаем пространство имен для модуля(пространство имен позволяет группировать индентификаторы в отдельные области, что помогает избегать конфликта имен)
namespace WorkArray
{
///Функция заполнения массива от руки
///double* array - указатель на массив, size_t size - размер массива
void fill_arr(double* array, size_t size)
{
    cout << "Заполнение массива: ";
    for (size_t i = 0; i < size; i++) // пробегаем по всему массиву
    {
        cin >> array[i]; // ввод элемента массива
    }
}

///Функция заполнения массива от руки
///vector<double> &array - ссылка на динамический массив типа вектор
void fill_arr(vector<double> &array)
{
    cout << "Заполнение массива: ";
    for (size_t i = 0; i < array.size(); i++) // пробегаем по всему массиву
    {
        cin >> array[i]; // ввод элемента массива
    }
}

///Функция заполнения массива рандомно от -25 до 25
///double* array - указатель на массив, size_t size - размер массива
void fill_arr_rand(double* array, size_t size)
{
    for (size_t i = 0; i < size; i++) // пробегаем по всему массиву
    {
        array[i] = (rand()%50-25); // рандомно задаем элементы массива в диапазоне от -25 до 25(функция rand отвечает за подбор случайных чисел)
    }    
}

///Функция заполнения массива рандомно от -25 до 25
///vector<double> &array - ссылка на динамический массив типа вектор
void fill_arr_rand(vector<double> &array)
{
    for (size_t i = 0; i < array.size(); i++) // пробегаем по всему массиву
    {
        array[i] = (rand()%50-25); // рандомно задаем элементы массива в диапазоне от -25 до 25(функция rand отвечает за подбор случайных чисел)
    }    
}

///Функция вывода массива
///double* array - указатель на массив, size_t n - размер массива
void print_arr(double* array, size_t size)
{
    cout << "Массив: "; // вывод в консоль
    for (size_t i = 0; i < size; i++) // пробегаем по всему массиву
    {
        cout << array[i] << " "; // выводим элементы массива через пробелы
    }
    cout << "\n"; // перенос на строку
}

///Функция вывода массива
///const vector<double> &array - ссылка на динамический массив типа вектор, const для того, чтобы случайно не изменить массив
void print_arr(const vector<double> &array)
{
    cout << "Массив: "; // вывод в консоль
    for (size_t i = 0; i < array.size(); i++) // пробегаем по всему массиву
    {
        cout << array[i] << " "; // выводим элементы массива через пробелы
    }
    cout << "\n"; // перенос на строку
}

///Функция вычисления по формуле a1-a2+a3-...+(-1)^(n+1)an
///double* array - указатель на массив, size_t size - размер массива
double calc_answ(double* array, size_t size)
{
    double minus = -1; // переменная для смены знака
    double rez = array[0]; // первый элемент
    for (size_t i = 1; i < size; i++) // пробегаем по массиву не включая первый элемент
    {
        minus = -minus; // смена знака
        rez -= minus*array[i]; // рассчет по формуле a1-a2+a3-...+(-1)^(n+1)an
    }
    return rez; // возвращает результат вычислений   
}

///Функция вычисления по формуле a1-a2+a3-...+(-1)^(n+1)an
///const vector<double> &array - ссылка на динамический массив типа вектор, const для того, чтобы случайно не изменить массив
double calc_answ(const vector<double> &array)
{
    double minus = -1; // переменная для смены знака
    double rez = array[0]; // первый элемент
    for (size_t i = 1; i < array.size(); i++) // пробегаем по массиву не включая первый элемент
    {
        minus = -minus; // смена знака
        rez -= minus*array[i]; // рассчет по формуле a1-a2+a3-...+(-1)^(n+1)an
    }
    return rez; // возвращает результат вычислений   
}

///Функция сохранения массива в файл
///const char *filename - название файла, double *array - указатель на массив, size_t size - размер массива
void SaveArrayToFile(const char *filename, double *array, size_t size)
{
    ofstream SaveFile(filename); // открываем или создаем файл с переданным названием для записи
    if (!SaveFile) // если файл не открылся
    {
        cout << "Не удается открыть файл для записи: " << filename << "\n"; // выводим сообщение
        return; // функция завершает работу
    }
    for (size_t i = 0; i < size; i++) // пробегаем по всему массиву
    {
        SaveFile << array[i] << " "; // записываем элементы в файл
    }
    SaveFile.close(); // закрываем файл
}

///Функция сохранения массива в файл
///const char *filename - название файла, const vector<double> &array - ссылка на динамический массив типа вектор, const для того, чтобы случайно не изменить массив
void SaveArrayToFile(const char *filename, const vector<double> &array)
{
    ofstream SaveFile(filename); // открываем или создаем файл с переданным названием для записи
    if (!SaveFile) // если файл не открылся
    {
        cout << "Не удается открыть файл для записи: " << filename << "\n"; // выводим сообщение
        return; // функция завершает работу
    }
    for (size_t i = 0; i < array.size(); i++) // пробегаем по всему массиву
    {
        SaveFile << array[i] << " "; // записываем элементы в файл
    }
    SaveFile.close(); // закрываем файл
}

///Функция загрузки массива из файла
///const char *filename - название файла, size_t size - размер массива
double *LoadArrayFromFile(const char *filename, size_t &size)
{
    size = 0; // изменяем размер на 0
    ifstream inFile(filename); // открываем файл с переданным названием для чтения
    if (!inFile) // если файл не открылся
    {
        cout << "Не удается открыть файл для записи: " << filename << "\n"; // выводим сообщение
        return nullptr; // функция завершает работу
    }
    double temp; // буферная переменная для размера массива из файла
    while (inFile >> temp) // подсчет количества чисел в файле
    {
        size++; // увеличиваем размер массива
    }
    inFile.clear(); // сброс состояния потока
    inFile.seekg(0); // перемещение указателя на начало файла
    double *array = new double[size]; // буферный массив
    for (size_t i = 0;i < size; i++) // пробегаем по всему массиву
    {
        inFile >> array[i]; // считываем из файла числа в буферный массив
    }
    inFile.close(); // закрываем файл
    return array; // возвращаем буферный массив
}

///Функция загрузки массива из файла
///const char *filename - название файла, const vector<double> &array - ссылка на динамический массив типа вектор, const для того, чтобы случайно не изменить массив, size_t &size - размер массива
vector<double> LoadArrayFromFile(const char *filename, const vector<double> array, size_t &size)
{
    size = 0; // изменяем размер на 0
    vector<double> tempArray; // буферный массив
    ifstream inFile(filename); // открываем файл с переданным названием для чтения
    if (!inFile) // если файл не открылся
    {
        cout << "Не удается открыть файл для записи: " << filename << "\n"; // выводим сообщение
        return tempArray; // функция возвращает пустой массив
    }
    double temp; // буферная переменная для размера массива из файла
    while (inFile >> temp) // подсчет количества чисел в файле
    {
        size++; // увеличиваем размер массива
    }
    inFile.clear(); // сброс состояния потока
    inFile.seekg(0); // перемещение указателя на начало файла
    tempArray.resize(size); // изменяем размер буферного массива
    for (size_t i = 0;i < size; i++) // пробегаем по всему массиву
    {
        inFile >> tempArray[i]; // считываем из файла числа в буферный массив
    }
    inFile.close(); // закрываем файл
    return tempArray; // возвращаем буферный массив
}

/// Функция проверки достоверности самостоятельно написанных функции
void test()
{
    double* testarr1 = new double [3]; // создаем массив для 1 проверки размером 3
    testarr1[0] = 56; // заполнение элементов массива
    testarr1[1] = 43.1;
    testarr1[2] = 83.6;
    vector<double> testv1 = {56, 43.1, 83.6};
    double* testarr2 = new double [8]; // создаем массив для 2 проверки размером 8
    testarr2[0] = -6; // заполнение элементов массива
    testarr2[1] = -31.6;
    testarr2[2] = -4;
    testarr2[3] = -81.4;
    testarr2[4] = -8;
    testarr2[5] = -5;
    testarr2[6] = -1;
    testarr2[7] = -0.54;
    vector<double> testv2 = {-6, -31.6, -4, -81.4, -8, -5, -1, -0.54};
    double* testarr3 = new double [6]; // создаем массив для 3 проверки размером 6
    testarr3[0] = 6; // заполнение элементов массива
    testarr3[1] = -7;
    testarr3[2] = 8;
    testarr3[3] = 9;
    testarr3[4] = -6;
    testarr3[5] = -7.31;
    vector<double> testv3 = {6, -7, 8, 9, -6, -7.31};
    assert(fabs(calc_answ(testarr1, 3)-96.5)<0.001); // Три проверки на достоверность функции вычисления по формуле a1-a2+a3-...+(-1)^(n+1)an (|результат функции-ожидаемый результат|<погрешность вычисления)
    assert(fabs(calc_answ(testarr2, 8)-99.54)<0.001);
    assert(fabs(calc_answ(testarr3, 6)-13.31)<0.001);
    assert(fabs(calc_answ(testv1)-96.5)<0.001); // Три проверки на достоверность функции(вектор) вычисления по формуле a1-a2+a3-...+(-1)^(n+1)an (|результат функции-ожидаемый результат|<погрешность вычисления)
    assert(fabs(calc_answ(testv2)-99.54)<0.001);
    assert(fabs(calc_answ(testv3)-13.31)<0.001);
    delete[] testarr1; // освобождение памяти занятой массивом для первой проверки
    delete[] testarr2; // освобождение памяти занятой массивом для второй проверки
    delete[] testarr3; // освобождение памяти занятой массивом для третьей проверки
    testv1.clear();
    testv2.clear();
    testv3.clear();
}
}