/*
Автор: Игонин Владимир Юрьевич ИВТ-23
Условие: Даны натуральное число n, действительные числа a1,..., an. Вычислить:
         ж) a1 - a2 + a3 - ... + (-1)^(n+1)an
*/

//библиотека C++ с классами, функциями и переменными для организации ввода-вывода(для функций cin, cout)
#include <iostream>
//Эта библиотека содержит функции для работы со временем и датой в С++. (для функции time)
#include <ctime>
//Библиотека C++ с векторами(динамический массив)
#include <vector>
//модуль с заполнением, выводом массива, вычислениями и проверкой(создан самостоятельно)
#include "workArr_temp.h"
//используем пространство имен std для того, чтобы не писать перед функциями стандартных библиотек(cin, cout и т.д.) std
using namespace std;

//используем созданное самостоятельно пространство имен для созданных функций(fill_arr, fill_arr_rand,  print_arr, calc_answ, test)
using namespace WorkArray;

int main()
{
    //system-функция, выполняющая заданную, через параметр syscom, системную команду
    //chcp 65001 > nul установливает кодировку юникод UTF8, chcp - изменить кодовую страницу
    system("chcp 65001 > nul");

    int VectorOrDinamicArr = 10;
    cout << "Вектор или Динамический массив(Введите 1 или 0): " << "1 - Вектор, " << "0 - Динамический массив\n"; //вывод подсказки
    do
    {
        cin >> VectorOrDinamicArr; // ввод пользователем работы с вектором или динамическим массивом
    } while ((VectorOrDinamicArr != 1)&&(VectorOrDinamicArr != 0)); // проверка введенного выбора

    if (VectorOrDinamicArr == 1)
    {
    vector<float> arr;
    size_t n = 0; //инициализация переменной, отвечающей за размер массива
    int LoadFileOrNot = 10;
    cout << "Загрузка массива или нет(Введите 1 или 0): " << "1 - Загрузка массива из файла, " << "0 - Нет\n"; //вывод подсказки
    do
    {
        cin >> LoadFileOrNot; // ввод пользователем метода ввода
    } while ((LoadFileOrNot != 1)&&(LoadFileOrNot != 0)); // проверка введенного метода

    if (LoadFileOrNot == 1)
    {
        char lFile[255];
        cout << "Введите название файла с массивом: ";
        cin >> lFile;
        arr.resize(n);
        arr = LoadArrayFromFile<float>(lFile, arr, n);
        print_arr<float>(arr); // вывод массива
        float ans = calc_answ<float>(arr); // вычисление по формуле a1-a2+a3-...+(-1)^(n+1)an
        cout << "Вычисление по формуле: a1-a2+a3-...+(-1)^(n+1)an = "; // вывод подсказки
        cout << ans; // вывод ответа
        arr.clear(); // освобождение памяти, занятой массивом
        return 0; // возвращаем 0 - программа завершает работу              
    }

    if (LoadFileOrNot == 0)
    {
        cout << "Введите размер массива(n>0): "; //вывод подсказки
        do
        {
            cin >> n; // ввод пользователем размера массива
        } while (n == 0); // проверка введенного выбора
        char sFile[255];
        cout << "Введите название файла для сохранения массива: ";
        cin >> sFile;
        arr.resize(n);
        int SelforRand = 10; // переменная, отвечающая за выбор метода заполнения массива
        cout << "Самостоятельный ввод или случайные числа(Введите 1 или 0): " << "1 - Самостоятельный ввод, " << "0 - Случайные числа\n"; //вывод подсказки
        do
        {
            cin >> SelforRand; // ввод пользователем метода ввода
        } while ((SelforRand != 1)&&(SelforRand != 0)); // проверка введенного метода

        if (SelforRand == 1) // если пользователь ввел 1
        {
            fill_arr<float>(arr); // вызов функции заполнения массива от руки
        }

        if (SelforRand == 0) // если пользователь ввел 1
        {
            //функция time возвращает текущее время в секундах
            //Функция srand выполняет инициализацию генератора случайных чисел rand
            srand(time(nullptr));
            fill_arr_rand<float>(arr); // вызов функции заполнения массива случайными числами
        }
        print_arr<float>(arr); // вывод массива
        SaveArrayToFile<float>(sFile, arr);
        float ans = calc_answ<float>(arr); // вычисление по формуле a1-a2+a3-...+(-1)^(n+1)an
        cout << "Вычисление по формуле: a1-a2+a3-...+(-1)^(n+1)an = "; // вывод подсказки
        cout << ans; // вывод ответа
        arr.clear(); // освобождение памяти, занятой массивом
        return 0; // возвращаем 0 - программа завершает работу
        }
    }

    if (VectorOrDinamicArr == 0)
    {
    size_t n = 0; //инициализация переменной, отвечающей за размер массива
    int LoadFileOrNot = 10;
    cout << "Загрузка массива или нет(Введите 1 или 0): " << "1 - Загрузка массива из файла, " << "0 - Нет\n"; //вывод подсказки
    do
    {
        cin >> LoadFileOrNot; // ввод пользователем метода ввода
    } while ((LoadFileOrNot != 1)&&(LoadFileOrNot != 0)); // проверка введенного метода
    if (LoadFileOrNot == 1)
    {
        char lFile[255];
        cout << "Введите название файла с массивом: ";
        cin >> lFile;
        float* arr = LoadArrayFromFile<float>(lFile, n);
        print_arr<float>(arr, n); // вывод массива
        float ans = calc_answ<float>(arr, n); // вычисление по формуле a1-a2+a3-...+(-1)^(n+1)an
        cout << "Вычисление по формуле: a1-a2+a3-...+(-1)^(n+1)an = "; // вывод подсказки
        cout << ans; // вывод ответа
        delete[] arr; // освобождение памяти, занятой массивом
        return 0; // возвращаем 0 - программа завершает работу
    }
    if (LoadFileOrNot == 0)
    {
        cout << "Введите размер массива(n>0): "; //вывод подсказки
        do
        {
            cin >> n; // ввод пользователем размера массива
        } while (n == 0); // проверка введенного выбора
        char sFile[255];
        cout << "Введите название файла для сохранения массива: ";
        cin >> sFile;
        float* arr = new float [n]; // инициализация динамического массива, размером n
        int SelforRand = 10; // переменная, отвечающая за выбор метода заполнения массива
        cout << "Самостоятельный ввод или случайные числа(Введите 1 или 0): " << "1 - Самостоятельный ввод, " << "0 - Случайные числа\n"; //вывод подсказки
        do
        {
            cin >> SelforRand; // ввод пользователем метода ввода
        } while ((SelforRand != 1)&&(SelforRand != 0)); // проверка введенного метода

        if (SelforRand == 1) // если пользователь ввел 1
        {
        fill_arr<float>(arr, n); // вызов функции заполнения массива от руки
        }
        if (SelforRand == 0) // если пользователь ввел 1
        {
            //функция time возвращает текущее время в секундах
            //Функция srand выполняет инициализацию генератора случайных чисел rand
            srand(time(nullptr));
            fill_arr_rand<float>(arr, n); // вызов функции заполнения массива случайными числами
        }
        print_arr<float>(arr, n); // вывод массива
        SaveArrayToFile<float>(sFile, arr, n);
        float ans = calc_answ<float>(arr, n); // вычисление по формуле a1-a2+a3-...+(-1)^(n+1)an
        cout << "Вычисление по формуле: a1-a2+a3-...+(-1)^(n+1)an = "; // вывод подсказки
        cout << ans; // вывод ответа
        delete[] arr; // освобождение памяти, занятой массивом
        return 0; // возвращаем 0 - программа завершает работу
    }
    }
}