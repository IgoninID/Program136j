/*
Автор: Игонин Владимир Юрьевич ИВТ-23
Часть модуля, файл содержащий заголовки функций для заполнения, заполнения случайными числами, вывода массива, вычисления по формуле и проверки достоверности функций
*/
//защита от повторного подключения заголовочного файла
#pragma once
//используем пространство имен std для того, чтобы не писать перед функциями и типами стандартных библиотек(vector) std
using namespace std;
//Создаем пространство имен для модуля(пространство имен позволяет группировать индентификаторы в отдельные области, что помогает избегать конфликта имен)
namespace WorkArray
{
///Функция заполнения массива от руки
///double* array - указатель на массив, size_t size - размер массива
void fill_arr(double* array, size_t size);

///Функция заполнения массива от руки
///vector<double> &array - ссылка на динамический массив типа вектор
void fill_arr(vector<double> &array);

///Функция заполнения массива рандомно от -25 до 25
///double* array - указатель на массив, size_t size - размер массива
void fill_arr_rand(double* array, size_t size);

///Функция заполнения массива рандомно от -25 до 25
///vector<double> &array - ссылка на динамический массив типа вектор
void fill_arr_rand(vector<double> &array);

///Функция вывода массива
///double* array - указатель на массив, size_t size - размер массива
void print_arr(double* array, size_t size);

///Функция вывода массива
///const vector<double> &array - ссылка на динамический массив типа вектор, const для того, чтобы случайно не изменить массив
void print_arr(const vector<double> &array);

///Функция вычисления по формуле a1-a2+a3-...+(-1)^(n+1)an
///double* array - указатель на массив, size_t size - размер массива
double calc_answ(double* array, size_t size);

///Функция вычисления по формуле a1-a2+a3-...+(-1)^(n+1)an
///const vector<double> &array - ссылка на динамический массив типа вектор, const для того, чтобы случайно не изменить массив
double calc_answ(const vector<double> &array);

///Функция сохранения массива в файл
///const char *filename - название файла, double *array - указатель на массив, size_t size - размер массива
void SaveArrayToFile(const char *filename, double *array, size_t size);

///Функция сохранения массива в файл
///const char *filename - название файла, const vector<double> &array - ссылка на динамический массив типа вектор, const для того, чтобы случайно не изменить массив
void SaveArrayToFile(const char *filename, const vector<double> &array);

///Функция загрузки массива из файла
///const char *filename - название файла, size_t size - размер массива
double *LoadArrayFromFile(const char *filename, size_t &size);

///Функция загрузки массива из файла
///const char *filename - название файла, const vector<double> &array - ссылка на динамический массив типа вектор, const для того, чтобы случайно не изменить массив, size_t &size - размер массива
vector<double> LoadArrayFromFile(const char *filename, vector<double> array, size_t &size);

/// Функция проверки достоверности самостоятельно написанных функции
void test();
}