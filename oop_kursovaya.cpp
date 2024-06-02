//#include "matrix_class.h"
#include "matrix_class.cpp"
//#include "proverka_str.cpp"
//using namespace std;


int main()
{
    bool res = false; // флаг
    cout<<"Cоздание матрицы (ввод с клавиатуры значений):"<<endl;
    string m, n; // строковые перемнные (размерность матрицы)
    cout<<"Введите размерность подматрицы"<<endl;
    cout<<"Введите кол-во строк: ";
    getline(cin,m); // считывание с консоли кол-ва строк
    res = proverka_str_is_int(m); // проверка введенного значения на целое число
    while (res != true || m=="0") // пока не положительное целое число
    {
        cout<<"Вводимое число должно быть целочисленним и больше 0"<<endl;
        cout<<"    Попробуйте снова: ";
        getline(cin,m); // считывание с консоли кол-ва строк
        res = proverka_str_is_int(m); // проверка введенного значения на целое число
    }
    cout<<endl;
    res = false;
    cout<<"Введите кол-во столбцов: ";
    getline(cin,n); // считывание с консоли кол-ва столбцов
    res = proverka_str_is_int(n); // проверка введенного значения на целое число
    while (res != true || n=="0") // пока не положительное целое число
    {
        cout<<"Вводимое число должно быть целочисленним и больше 0"<<endl;
        cout<<"    Попробуйте снова: ";
        getline(cin,n); // считывание с консоли кол-ва столбцов
        res = proverka_str_is_int(n); // проверка введенного значения на целое число
    }
    res = false;
    cout<<endl;
    matrix matr(m,n); // создание подматрицы
    matr.vvod_keyboard(); // вызов функции ввода с клавиатуры значений
    string command; // строковая переменная команды
    interface(); // вызов функции меню
    cout<<"Введите цифру для выбора действия: ";
    getline(cin,command);  // считывание с консоли команды
    res = proverka_str_is_int(command); // проверка введенного значения на целое число
    while (res != true) // пока не целое число
    {
        cout<<"Вводимое число должно быть от 1 до 4 включительно"<<endl;
        cout<<"    Попробуйте снова: ";
        getline(cin,command); // считывание с консоли команды
        res = proverka_str_is_int(command); // проверка введенного значения на целое число
    } 
    res = false;
    while (command!="5") // пока не команда "4"
    {
        switch(stoi(command)) // проверка, какая введена команда
        {
            case 1:
                {
                    matr.print_screen(); // вызов функции вывода в консоль матрицы
                    break;
                }    
            case 2:
                {
                    cout<<matr.get(forward<matrix&&>(matr))<<endl<<endl; // вызов функции вывода в консоль желаемого значения
                    break;    
                }
            case 3:
                {
                    matr.podmatrix(forward<matrix&&>(matr)); // вызов функции создания подматрицы
                    break; 
                }
            case 4:
                {
                    matr.resize(forward<matrix&&>(matr)); // вызов функции изменения размерности матрицы
                    break;
                }    
            default:
                cout<<"Неправильный ввод команды, попробуйте снова"<<endl;
                break; 
        }
        interface(); // вызов функции меню
        cout<<"Введите цифру для выбора действия: ";
        getline(cin,command); // считывание с консоли команды
        res = proverka_str_is_int(command); // проверка введенного значения на целое число
        while (res != true) // пока не целое число
        {
            cout<<"Вводимое число должно быть от 1 до 4 включительно"<<endl;
            cout<<"    Попробуйте снова: ";
            getline(cin,command); // считывание с консоли команды
            res = proverka_str_is_int(command); // проверка введенного значения на целое число
        }
    res = false;
    }
    return 0;
}
