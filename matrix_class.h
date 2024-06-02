#include "proverka_str.cpp"

using namespace std;

// класс матрица
class matrix
{
    private:
        int m_rows; // строки
        int n_cols; // столбцы
        double **m_values; //указатель на матрицу
    public:
        matrix(); // конструктор (нулевая матрица)
        matrix(string rows, string cols); // конструктор (выделяет память)
        matrix(const matrix&& other); // конструктор копирования
        double get(matrix&& other); // возврат элемента по индексу
        bool vvod_keyboard (); // чтение с клавиатуры значений матрицы
// функции для получения размерности матрицы
// const - чтобы их можно было вызывать для констанных матриц (т.к. в коде матрица передается часто по константной ссылке для избежания лишнего копирования матрицы при вызове функции
        int rows() const;
        int cols() const;
        void resize(matrix&& full_matrix); // изменение размерности матрицы
        void podmatrix(matrix&& full_matrix); // вывод подматрицы
        void print_screen(); // вывод в консоль
        ~matrix();
    protected:
};