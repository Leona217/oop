#include "matrix_class.h"
//#include "proverka_str.cpp"


// определение конструктора (по умолчанию)
matrix::matrix()
{
    m_rows = 0;
    n_cols = 0;
    m_values = nullptr;
}

// выделение памяти (конструктор полный)
matrix::matrix(string rows, string cols)
{
    m_rows = stoi(rows); // кол-во строк
    n_cols = stoi(cols); // кол-во столбцов
    m_values = new double *[m_rows]; // выделение памяти под двумерный массив
    for (int i=0; i < m_rows; i++)
        m_values[i] = new double [n_cols];
} 

// конструктор копирования
matrix::matrix(const matrix&& other)
{
    m_rows = other.m_rows; // копирование кол-ва строк
    n_cols = other.n_cols; // копирование кол-ва столбцов
    m_values = new double *[m_rows]; // выделение памяти под двумерный массив
    for (int i=0; i < m_rows; i++)
        m_values[i] = new double [n_cols];
    for (int i=0; i < m_rows; i++)
        for (int j=0; j < n_cols; j++)
            m_values[i][j] = other.m_values[i][j]; //поэлементное копирование
}

// возврат элемента по индексу 
double matrix::get(matrix&& other) 
{
    if (other.m_values==nullptr) // проверка на существование матрицы
    {
        cout<<"Матрицы не существует"<<endl;
        return 0.000;
    }
    string i_want, j_want; // строковые переменные (позиция элемента)
    cout<<"Введите позицию элемента по строке: ";
    getline(cin,i_want); // чтение с консоли позиции элемента по строке
    cout<<endl;
    bool res = false; // флаг
    res = proverka_str_is_int (i_want); // проверка введенного значения на целое число
    while (res ==false || ((res== true) && (stoi(i_want)<0 || stoi(i_want) >= other.rows()))) // пока не целое число ИЛИ отрицательное число ИЛИ введенное число больше кол-ва строк в матрице
    {
        cout<<"Вы ввели некорректное значение позиции элемента по строке"<<endl;
        cout<<"    Значение должно находиться в диапазоне 0 - "<<other.rows()-1<<" включительно"<<endl;
        cout<<"Попробуйте снова: ";
        getline(cin,i_want); // чтение с консоли позиции элемента по строке
        res = proverka_str_is_int (i_want); // проверка введенного значения на целое число
        cout<<endl;
    }
    cout<<endl;
    res = false;
    cout<<"Введите позицию элемента по столбцу: ";
    getline(cin,j_want); // чтение с консоли позиции элемента по столбцу
    res = proverka_str_is_int (j_want);
    while (res ==false || ((res== true) && (stoi(j_want)<0 || stoi(j_want) >= other.cols()))) // пока не целое число ИЛИ отрицательное число ИЛИ введенное число больше кол-ва столбцов в матрице
    {
        cout<<"Вы ввели некорректное значение позиции элемента по столбцу"<<endl;
        cout<<"    Значение должно находиться в диапазоне 0 - "<<other.cols()-1<<" включительно"<<endl;
        cout<<"Попробуйте снова: ";
        getline(cin,j_want); // чтение с консоли позиции элемента по столбцу
        res = proverka_str_is_int (j_want); // проверка введенного значения на целое число
        cout<<endl;
    }
    cout<<endl;
    cout<<"Элемент ["<<i_want<<"]["<<j_want<<"] = "; // вывод на экран желаемого элемента
    return m_values[stoi(i_want)][stoi(j_want)];
}

// ввод с клавиатуры
bool matrix::vvod_keyboard ()
{
    if (m_values == nullptr) // проверка на существование матрицы
    {
        cout << "Память под матрицу не выделена"<< endl;
        return false;
    }
    string element; // строковая переменная (значение элемента)
    bool res = false; // флаг
    cout<< "Введите матрицу"<<endl;
    for (int i = 0; i < m_rows; i++) 
    {
        for (int j = 0; j < n_cols; j++) 
        {
            cout << "[" << i << "]" << "[" << j << "] = ";
            getline(cin,element); // поэлементное считывание значения элемента с консоли
            res = proverka_str_is_double(element); // проверка введенного значения на вещественное число
            while (res != true) // пока не вещественное число
            {
                cout<<"Вводимое число должно быть целочисленним или вещественным"<<endl;
                cout<<"    Попробуйте снова: ";
                getline(cin,element); // считывание значения элемента с консоли
                res = proverka_str_is_double(element); // проверка введенного значения на вещественное число
            }
            res = false;
            string minus_value = ""; // строковая переменная (хранит модуль отрицательного числа)
            if (element[0] == '-') // если первый символ "-" (отрицательное число)
            {
                for (int k = 1; k < element.length(); k++) 
                    minus_value += element[k]; // запоминаем модуль отрицательного числа
                m_values[i][j] = (-1)*(stod(minus_value)); // умножаем модуль на -1 и зачаписываем полученное знение в матрицу
            }
            else // положительное число
                m_values[i][j] = stod(element); // зачаписываем знение в матрицу
        }
    }
    return true;
}

// Функция возврата значения количества строк в матрице
int matrix::rows() const 
{
    return m_rows;
}

// Функция возврата значения количества столбцов в матрице
int matrix::cols() const 
{
    return n_cols;
}

// изменение размерности матрицы
void matrix::resize(matrix&& full_matrix)
{
  if (full_matrix.m_values==nullptr) // проверка на существование матрицы
    {
        cout<<"Матрицы не существует"<<endl;
        return;
    }
    bool res = false; // флаг
    cout<<"В случае добавления новых элементов их необходимо будут ввести вручную"<<endl;
    string m1, n1, i_want, j_want;  // строковые переменный (размерность матрицы, позиция элемента)
    cout<<"Введите размерность новой матрицы"<<endl;
    cout<<"Введите кол-во строк: ";
    getline(cin,m1); // считывание с консоли кол-ва строк
    res = proverka_str_is_int(m1); // проверка введенного значения на целое число
    while (res != true || (res == true && m1=="0")) // пока не положительное целое число
    {
        cout<<"Вводимое число должно быть целочисленним и больше 0"<<endl;
        cout<<"    Попробуйте снова: ";
        getline(cin,m1); // считывание с консоли кол-ва строк
        res = proverka_str_is_int(m1); // проверка введенного значения на целое число
    }
    cout<<endl;
    res = false;
    cout<<"Введите кол-во столбцов: ";
    getline(cin,n1); // считывание с консоли кол-ва столбцов
    res = proverka_str_is_int(n1); // проверка введенного значения на целое число
    while (res != true || (res == true && n1=="0")) // пока не положительное целое число
    {
        cout<<"Вводимое число должно быть целочисленним и больше 0"<<endl;
        cout<<"    Попробуйте снова: ";
        getline(cin,n1); // считывание с консоли кол-ва столбцов
        res = proverka_str_is_int(n1); // проверка введенного значения на целое число
    }
    res = false;
    cout<<endl;
    cout<<"Введите позицию элемента. Эта позиция означает, что начиная с данного элемента будут скопированы значения исходной матрицы"<<endl;
    cout<<"Введите позицию элемента по строке: ";
    getline(cin,i_want); // считывание с консоли позиции элемента по строке
    cout<<endl;
    res = false;
    res = proverka_str_is_int (i_want); // проверка введенного значения на целое число
    while (res ==false || ((res== true) && (stoi(i_want) >= full_matrix.rows()))) // пока не положительное целое или введенное значение больше кол-ва строк в матрице
    {
        cout<<"Вы ввели некорректное значение позиции элемента по строке"<<endl;
        cout<<"    Значение должно находиться в диапазоне 0 - "<<full_matrix.rows()-1<<" включительно"<<endl;
        cout<<"Попробуйте снова: ";
        getline(cin,i_want); // считывание с консоли позиции элемента по строке
        res = proverka_str_is_int (i_want); // проверка введенного значения на целое число
        cout<<endl;
    }
    cout<<endl;
    res = false;
    cout<<"Введите позицию элемента по столбцу: ";
    getline(cin,j_want); // считывание с консоли позиции элемента по столбцу
    res = proverka_str_is_int (j_want); // проверка введенного значения на целое число
    while (res ==false || ((res== true) && (stoi(j_want) >= full_matrix.cols()))) // пока не положительное целое или введенное значение больше кол-ва столбцов в матрице
    {
        cout<<"Вы ввели некорректное значение позиции элемента по столбцу"<<endl;
        cout<<"    Значение должно находиться в диапазоне 0 - "<<full_matrix.cols()-1<<" включительно"<<endl;
        cout<<"Попробуйте снова: ";
        getline(cin,j_want); // считывание с консоли позиции элемента по столбцу
        res = proverka_str_is_int (j_want); // проверка введенного значения на целое число
        cout<<endl;
    }
    res = false;
    cout<<endl;


    string m_want, n_want;
    cout<<"Введите размерность подматрицы, которая останется в новой матрице."<<endl;
    cout<<"Введите кол-во строк: ";
    getline(cin,m_want); // считывание с консоли кол-ва строк
    res = proverka_str_is_int(m_want); // проверка введенного значения на целое число
    while (res != true || (res == true && m_want=="0") ||(res == true && (stoi(i_want)!=0) && !(stoi(m_want) < full_matrix.rows()-stoi(i_want)+1)) ||(res == true && (stoi(i_want)==0) && !(stoi(m_want) <= full_matrix.rows()-stoi(i_want)+1))) // пока не положительное целое число
    {
        cout<<"Вводимое число должно быть в диапазоне 1 - "<<full_matrix.rows()-stoi(i_want)<<" включительно"<<endl;
        cout<<"    Попробуйте снова: ";
        getline(cin,m_want); // считывание с консоли кол-ва строк
        res = proverka_str_is_int(m_want); // проверка введенного значения на целое число
    }
    cout<<endl;
    res = false;
    cout<<"Введите кол-во столбцов: ";
    getline(cin,n_want); // считывание с консоли кол-ва столбцов
    res = proverka_str_is_int(n_want); // проверка введенного значения на целое число
    while (res != true || (res == true && n_want=="0") || (res == true && stoi(j_want)==0 && !(stoi(n_want) <=full_matrix.cols()-stoi(j_want)+1)) || (res == true && (stoi(j_want)!=0) && !(stoi(n_want) < full_matrix.cols()-stoi(j_want)+1))) // пока не положительное целое число
    {
        cout<<"Вводимое число должно быть в диапазоне 1 - "<<full_matrix.cols()-stoi(j_want)<<" включительно"<<endl;
        cout<<"    Попробуйте снова: ";
        getline(cin,n_want); // считывание с консоли кол-ва столбцов
        res = proverka_str_is_int(n_want); // проверка введенного значения на целое число
    }
    res = false;
    cout<<endl;
    matrix new_matrix(m1,n1); // выделение памяти под двумерный массив
    string i_new, j_new;
    cout<<"Введите позицию элемента. Это значение будет являться позицией выбранного выше элемента исходной матрицы в новой матрице"<<endl;
    cout<<"Введите позицию элемента по строке: ";
    getline(cin,i_new); // считывание с консоли позиции элемента по строке
    cout<<endl;
    res = false;
    res = proverka_str_is_int (i_new); // проверка введенного значения на целое число
    while (res ==false || ((res== true) && (stoi(i_new) >= new_matrix.rows()))) // пока не положительное целое или введенное значение больше кол-ва строк в матрице
    {
        cout<<"Вы ввели некорректное значение позиции элемента по строке"<<endl;
        cout<<"    Значение должно находиться в диапазоне 0 - "<<new_matrix.rows()-1<<" включительно"<<endl;
        cout<<"Попробуйте снова: ";
        getline(cin,i_new); // считывание с консоли позиции элемента по строке
        res = proverka_str_is_int (i_new); // проверка введенного значения на целое число
        cout<<endl;
    }
    cout<<endl;
    res = false;
    cout<<"Введите позицию элемента по столбцу: ";
    getline(cin,j_new); // считывание с консоли позиции элемента по столбцу
    res = proverka_str_is_int (j_new); // проверка введенного значения на целое число
    while (res ==false || ((res== true) && (stoi(j_new) >= new_matrix.cols()))) // пока не положительное целое или введенное значение больше кол-ва столбцов в матрице
    {
        cout<<"Вы ввели некорректное значение позиции элемента по столбцу"<<endl;
        cout<<"    Значение должно находиться в диапазоне 0 - "<<new_matrix.cols()-1<<" включительно"<<endl;
        cout<<"Попробуйте снова: ";
        getline(cin,j_new); // считывание с консоли позиции элемента по столбцу
        res = proverka_str_is_int (j_new); // проверка введенного значения на целое число
        cout<<endl;
    }
    res = false;
    cout<<endl;
    string element;
    for (int i=0; i < stoi(m1); i++)
    {
        for (int j=0; j < stoi(n1); j++)
        {
            // ввод недостающих значению вручную
            if (i<stoi(i_new) || (stoi(i_want)!=0 && i>stoi(m_want)+stoi(i_new)-stoi(i_want)) || (stoi(i_want)==0 && i>=stoi(m_want)+stoi(i_new)-stoi(i_want)) || j<stoi(j_new) || (stoi(j_want)==0 && j>=stoi(j_new)+stoi(n_want)-stoi(j_want)) ||(stoi(j_want)!=0 && j>stoi(j_new)+stoi(n_want)-stoi(j_want)))
            {
                string element;
                cout << "[" << i << "]" << "[" << j << "] = ";
                getline(cin,element); // поэлементное считывание значения элемента с консоли
                res = proverka_str_is_double(element); // проверка введенного значения на вещественное число
                while (res != true) // пока не вещественное число
                {
                    cout<<"Вводимое число должно быть целочисленним или вещественным"<<endl;
                    cout<<"    Попробуйте снова: ";
                    getline(cin,element); // считывание значения элемента с консоли
                    res = proverka_str_is_double(element); // проверка введенного значения на вещественное число
                }   
                res = false;
                string minus_value = ""; // строковая переменная (хранит модуль отрицательного числа)
                if (element[0] == '-') // если первый символ "-" (отрицательное число)
                {
                    for (int k = 1; k < element.length(); k++) 
                        minus_value += element[k]; // запоминаем модуль отрицательного числа
                    new_matrix.m_values[i][j] = (-1)*(stod(minus_value)); // умножаем модуль на -1 и зачаписываем полученное знение в матрицу
                }
                else // положительное число
                    new_matrix.m_values[i][j] = stod(element); // зачаписываем знение в матрицу
            }
            else
            {
                    new_matrix.m_values[i][j] = full_matrix.m_values[stoi(i_want)+i-stoi(i_new)][stoi(j_want)+j-stoi(j_new)]; // заполняем подматрицу необходимыми значениями
            }
            
        }
    }
    new_matrix.print_screen(); // вывод подматрицы на экран
}

// вывод подматрицы
void matrix::podmatrix(matrix&& full_matrix)
{
    if (full_matrix.m_values==nullptr) // проверка на существование матрицы
    {
        cout<<"Матрицы не существует"<<endl;
        return;
    }
    bool res = false; // флаг
    //cout<<"В случае добавления новых элементов они будут инициализированы нулями"<<endl;
    cout<<"В случае добавления новых элементов их необходимо будут ввести вручную"<<endl;
    string m1, n1, i_want, j_want;  // строковые переменный (размерность матрицы, позиция элемента)
    cout<<"Введите размерность подматрицы"<<endl;
    cout<<"Введите кол-во строк: ";
    getline(cin,m1); // считывание с консоли кол-ва строк
    res = proverka_str_is_int(m1); // проверка введенного значения на целое число
    while (res != true || (res == true && m1=="0")) // пока не положительное целое число
    {
        cout<<"Вводимое число должно быть целочисленним и больше 0"<<endl;
        cout<<"    Попробуйте снова: ";
        getline(cin,m1); // считывание с консоли кол-ва строк
        res = proverka_str_is_int(m1); // проверка введенного значения на целое число
    }
    cout<<endl;
    res = false;
    cout<<"Введите кол-во столбцов: ";
    getline(cin,n1); // считывание с консоли кол-ва столбцов
    res = proverka_str_is_int(n1); // проверка введенного значения на целое число
    while (res != true || (res == true && n1=="0")) // пока не положительное целое число
    {
        cout<<"Вводимое число должно быть целочисленним и больше 0"<<endl;
        cout<<"    Попробуйте снова: ";
        getline(cin,n1); // считывание с консоли кол-ва столбцов
        res = proverka_str_is_int(n1); // проверка введенного значения на целое число
    }
    res = false;
    cout<<endl;
    cout<<"Введите позицию элемента. эта позиция означает, что данный элемент будет первым(верхним левым) в выводимой подматрице"<<endl;
    cout<<"Введите позицию элемента по строке: ";
    getline(cin,i_want); // считывание с консоли позиции элемента по строке
    cout<<endl;
    res = false;
    res = proverka_str_is_int (i_want); // проверка введенного значения на целое число
    while (res ==false || ((res== true) && (stoi(i_want) >= full_matrix.rows()))) // пока не положительное целое или введенное значение больше кол-ва строк в матрице
    {
        cout<<"Вы ввели некорректное значение позиции элемента по строке"<<endl;
        cout<<"    Значение должно находиться в диапазоне 0 - "<<full_matrix.rows()-1<<" включительно"<<endl;
        cout<<"Попробуйте снова: ";
        getline(cin,i_want); // считывание с консоли позиции элемента по строке
        res = proverka_str_is_int (i_want); // проверка введенного значения на целое число
        cout<<endl;
    }
    cout<<endl;
    res = false;
    cout<<"Введите позицию элемента по столбцу: ";
    getline(cin,j_want); // считывание с консоли позиции элемента по столбцу
    res = proverka_str_is_int (j_want); // проверка введенного значения на целое число
    while (res ==false || ((res== true) && (stoi(j_want) >= full_matrix.cols()))) // пока не положительное целое или введенное значение больше кол-ва столбцов в матрице
    {
        cout<<"Вы ввели некорректное значение позиции элемента по столбцу"<<endl;
        cout<<"    Значение должно находиться в диапазоне 0 - "<<full_matrix.cols()-1<<" включительно"<<endl;
        cout<<"Попробуйте снова: ";
        getline(cin,j_want); // считывание с консоли позиции элемента по столбцу
        res = proverka_str_is_int (j_want); // проверка введенного значения на целое число
        cout<<endl;
    }
    res = false;
    cout<<endl;
    matrix pod_matrix(m1,n1); // выделение памяти под двумерный массив
    string element;
    for (int i=0; i < stoi(m1); i++)
    {
        for (int j=0; j < stoi(n1); j++)
        {
            if (stoi(i_want)+i<full_matrix.m_rows && stoi(j_want)+j<full_matrix.n_cols) // есть значения по требуемым позициям в первоначальной матрице
                pod_matrix.m_values[i][j] = full_matrix.m_values[stoi(i_want)+i][stoi(j_want)+j]; // заполняем подматрицу необходимыми значениями
            else
            {
                pod_matrix.m_values[i][j] = 0.0; // заполнение нулями элементов, которых нет в изначальной матрице
            } 
        }
    }
    pod_matrix.print_screen(); // вывод подматрицы на экран
}

// вывод в консоль
void matrix::print_screen() 
{
    if (m_values==nullptr) // проверка на существование матрицы
    {
        cout<<"Матрицы не существует"<<endl;
        return;
    } 
    bool flag; // флаг
    cout<< setw( 8 )<<" "; // вывод пробелов
    for (int j = 0; j < n_cols; j++) 
    cout<< setw( 8 )<<j; // вывод нумерации столбцов
    cout<<endl; 
    for (int i = 0; i < m_rows; i++)
    {
        flag = true;
        for (int j = 0; j < n_cols; j++) 
        {
            if (flag == true) // для того, чтобы единожды выводить нумерацию
            {
                cout<<setw( 8 )<<i; // вывод нумерации строк
                flag = false;
            }    
            cout << setw( 8 ) << fixed << setprecision(3) << m_values[i][j] << " "; // поэлементный вывод на экран матрицы
        }
        cout << endl;
    }
    cout << endl;
}

// деструктор
matrix::~matrix() 
{
    if (m_values != nullptr) // если матрица существует
    {
        for (int i = 0; i < m_rows; i++) 
            delete[] m_values[i]; // удаление памяти, выделенной под матрицу
        delete[] m_values;
    } 
}

