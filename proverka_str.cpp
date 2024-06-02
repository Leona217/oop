#include <iostream>
#include <iomanip>
#include <string>
#include <istream>
#include <fstream>

using namespace std;

// меню
void interface()
{
    cout<<"Перечень доступных действий: "<<endl;
    cout<<"1 - вывод на экран всей(полной) матрицы"<<endl;
    cout<<"2 - вывод на экран желаемого элемента"<<endl;
    cout<<"3 - вывод на экран подматрицы"<<endl;
    cout<<"4 - изменение размерности матрицы"<<endl;
    cout<<"5 - завершение работы программы"<<endl;
    cout<<""<<endl;
}

// функция проверки, являентся ли введенная строка целым числом
bool proverka_str_is_int (string str)
{
    bool res = false; // флаг
    for (int i=0; i<str.length(); i++)
    {
        if (int(str[i]) > 47 && int(str[i])<59) // цифры 0 - 9
        {
            res = true;
        }
        else
            return false; // если встретился недопустимый знак
    }
    return res;
}

// функция проверки, являентся ли введенная строка вещественным числом
bool proverka_str_is_double (string str)
{
    bool res = false; // флаг
    for (int i=0; i<str.length(); i++)
    {
        if ((int(str[i]) > 47 && int(str[i])<59) || (int(str[i])==46 && i!=0) || (i==0 && str[i]=='-')) // цифры 0 - 9, ".", "-"
        {
            res = true;
        }
        else
            return false; // если встретился недопустимый знак
    }
    return res;
}