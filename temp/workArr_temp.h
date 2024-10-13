/*
Автор: Игонин Владимир Юрьевич ИВТ-23
модуль, файл содержащий заголовки функций и тела шаблонных функций для заполнения, заполнения случайными числами, вывода массива, вычисления по формуле и проверки достоверности функций
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
// template - шаблон функции
// typename - создаем свой тип
// Type - аргумент шаблона
template <typename Type>
///Шаблон функции заполнения массива от руки
///Type* array - указатель на массив, size_t size - размер массива
void fill_arr(Type* array, size_t size)
{
    cout << "Заполнение массива: ";
    for (size_t i = 0; i < size; i++) // пробегаем по всему массиву
    {
        cin >> array[i]; // ввод элемента массива
    }
}

// template - шаблон функции
// typename - создаем свой тип
// Type - аргумент шаблона
template <typename Type>
///Шаблон функции заполнения массива от руки
///vector<Type> &array - ссылка на динамический массив типа вектор
void fill_arr(vector<Type> &array)
{
    cout << "Заполнение массива: ";
    for (size_t i = 0; i < array.size(); i++) // пробегаем по всему массиву
    {
        cin >> array[i]; // ввод элемента массива
    }
}

// template - шаблон функции
// typename - создаем свой тип
// Type - аргумент шаблона
template <typename Type>
///Шаблон функции заполнения массива рандомно от -25 до 25
///Type* array - указатель на массив, size_t size - размер массива
void fill_arr_rand(Type* array, size_t size)
{
    for (size_t i = 0; i < size; i++) // пробегаем по всему массиву
    {
        array[i] = (rand()%50-25); // рандомно задаем элементы массива в диапазоне от -25 до 25(функция rand отвечает за подбор случайных чисел)
    }    
}

// template - шаблон функции
// typename - создаем свой тип
// Type - аргумент шаблона
template <typename Type>
///Шаблон функции заполнения массива рандомно от -25 до 25
///vector<Type> &array - ссылка на динамический массив типа вектор
void fill_arr_rand(vector<Type> &array)
{
    for (size_t i = 0; i < array.size(); i++) // пробегаем по всему массиву
    {
        array[i] = (rand()%50-25); // рандомно задаем элементы массива в диапазоне от -25 до 25(функция rand отвечает за подбор случайных чисел)
    }    
}

// template - шаблон функции
// typename - создаем свой тип
// Type - аргумент шаблона
template <typename Type>
///Шаблон функции вывода массива
///Type* array - указатель на массив, size_t n - размер массива
void print_arr(Type* array, size_t size)
{
    cout << "Массив: "; // вывод в консоль
    for (size_t i = 0; i < size; i++) // пробегаем по всему массиву
    {
        cout << array[i] << " "; // выводим элементы массива через пробелы
    }
    cout << "\n"; // перенос на строку
}

// template - шаблон функции
// typename - создаем свой тип
// Type - аргумент шаблона
template <typename Type>
///Шаблон функции вывода массива
///const vector<Type> &array - ссылка на динамический массив типа вектор, const для того, чтобы случайно не изменить массив
void print_arr(const vector<Type> &array)
{
    cout << "Массив: "; // вывод в консоль
    for (size_t i = 0; i < array.size(); i++) // пробегаем по всему массиву
    {
        cout << array[i] << " "; // выводим элементы массива через пробелы
    }
    cout << "\n"; // перенос на строку
}

// template - шаблон функции
// typename - создаем свой тип
// Type - аргумент шаблона
template <typename Type>
///Шаблон функции вычисления по формуле a1-a2+a3-...+(-1)^(n+1)an
///Type* array - указатель на массив, size_t size - размер массива
Type calc_answ(Type* array, size_t size)
{
    Type minus = -1; // переменная для смены знака
    Type rez = array[0]; // первый элемент
    for (size_t i = 1; i < size; i++) // пробегаем по массиву не включая первый элемент
    {
        minus = -minus; // смена знака
        rez -= minus*array[i]; // рассчет по формуле a1-a2+a3-...+(-1)^(n+1)an
    }
    return rez; // возвращает результат вычислений   
}

// template - шаблон функции
// typename - создаем свой тип
// Type - аргумент шаблона
template <typename Type>
///Шаблон функции вычисления по формуле a1-a2+a3-...+(-1)^(n+1)an
///const vector<Type> &array - ссылка на динамический массив типа вектор, const для того, чтобы случайно не изменить массив
Type calc_answ(const vector<Type> &array)
{
    Type minus = -1; // переменная для смены знака
    Type rez = array[0]; // первый элемент
    for (size_t i = 1; i < array.size(); i++) // пробегаем по массиву не включая первый элемент
    {
        minus = -minus; // смена знака
        rez -= minus*array[i]; // рассчет по формуле a1-a2+a3-...+(-1)^(n+1)an
    }
    return rez; // возвращает результат вычислений   
}

// template - шаблон функции
// typename - создаем свой тип
// Type - аргумент шаблона
template <typename Type>
///Шаблон функции сохранения массива в файл
///const char *filename - название файла, Type *array - указатель на массив, size_t size - размер массива
void SaveArrayToFile(const char *filename, Type *array, size_t size)
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

// template - шаблон функции
// typename - создаем свой тип
// Type - аргумент шаблона
template <typename Type>
///Шаблон функции сохранения массива в файл
///const char *filename - название файла, const vector<Type> &array - ссылка на динамический массив типа вектор, const для того, чтобы случайно не изменить массив
void SaveArrayToFile(const char *filename, const vector<Type> &array)
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

// template - шаблон функции
// typename - создаем свой тип
// Type - аргумент шаблона
template <typename Type>
///Шаблон функции загрузки массива из файла
///const char *filename - название файла, size_t size - размер массива
Type *LoadArrayFromFile(const char *filename, size_t &size)
{
    size = 0; // изменяем размер на 0
    ifstream inFile(filename); // открываем файл с переданным названием для чтения
    if (!inFile) // если файл не открылся
    {
        cout << "Не удается открыть файл для записи: " << filename << "\n"; // выводим сообщение
        return nullptr; // функция завершает работу
    }
    Type temp; // буферная переменная для размера массива из файла
    while (inFile >> temp) // подсчет количества чисел в файле
    {
        size++; // увеличиваем размер массива
    }
    inFile.clear(); // сброс состояния потока
    inFile.seekg(0); // перемещение указателя на начало файла
    Type *array = new Type[size]; // буферный массив
    for (size_t i = 0;i < size; i++) // пробегаем по всему массиву
    {
        inFile >> array[i]; // считываем из файла числа в буферный массив
    }
    inFile.close(); // закрываем файл
    return array; // возвращаем буферный массив
}

// template - шаблон функции
// typename - создаем свой тип
// Type - аргумент шаблона
template <typename Type>
///Шаблон функции загрузки массива из файла
///const char *filename - название файла, const vector<Type> &array - ссылка на динамический массив типа вектор, const для того, чтобы случайно не изменить массив, size_t &size - размер массива
vector<Type> LoadArrayFromFile(const char *filename, const vector<Type> array, size_t &size)
{
    size = 0; // изменяем размер на 0
    vector<Type> tempArray; // буферный массив
    ifstream inFile(filename); // открываем файл с переданным названием для чтения
    if (!inFile) // если файл не открылся
    {
        cout << "Не удается открыть файл для записи: " << filename << "\n"; // выводим сообщение
        return tempArray; // функция возвращает пустой массив
    }
    Type temp; // буферная переменная для размера массива из файла
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
}