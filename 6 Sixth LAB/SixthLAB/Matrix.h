#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix{
protected:
    int m_n;
    double **marr;
public:

    // Конструкторы

    Matrix (int n, int){
        m_n = n;
        marr = new double *[m_n];
        for(int i = 0; i < m_n; ++i)
            marr[i] = new double[m_n];
        for (int i = 0; i < m_n; i++)
            for (int j = 0; j < m_n; j++){
                std::cout << "marr [" << i << "][" << j <<"] = ";
                std::cin >> marr[i][j];
            }
    }

    Matrix (int n, double){
        m_n = n;
        marr = new double *[m_n];
        for (int i = 0; i < m_n; i++){
            marr[i] = new double[m_n];
            for (int j = 0; j < m_n; j++)
                marr[i][j] = 1. / (i + j + 1);
        }
    }
    Matrix (int n = 2){
        m_n = n;
        marr = new double *[m_n];
        for(int i = 0; i < m_n; ++i)
            marr[i] = new double[m_n];
        for (int i = 0; i < m_n; i++)
            for (int j = 0; j < m_n; j++){
                marr[i][j] = (i==j)?1:0;
            }
    }

    // Методы

    void maximumElement(){
        int m = marr[0][0], im = 0, jm = 0;
        for (int i = 0; i < m_n; i++)
            for (int j = 0; j < m_n; j++)
                if (marr[i][j] > m){
                    m = marr[i][j];
                    im = i;
                    jm = j;
                }
        std::cout << "Максимальный элемент матрицы - marr[" << im << "][" << jm <<"] = " << m << std::endl;
    }

    void minimumElement(){
        int m = marr[0][0], im = 0, jm = 0;
        for (int i = 0; i < m_n; i++)
            for (int j = 0; j < m_n; j++)
                if (marr[i][j] < m){
                    m = marr[i][j];
                    im = i;
                    jm = j;
                }
        std::cout << "Минимальный элемент матрицы - marr[" << im << "][" << jm <<"] = " << m << std::endl;
    }

    void spur(){
        int s = 0;
        for (int i = 0; i < m_n; i++)
            s += marr[i][i];
        std::cout << "След матрицы = " << s << std::endl;
    }

    void rowSwap(int row1, int row2){
        double *temp = marr[row1];
        marr[row1] = marr[row2];
        marr[row2] = temp;
    }

    void print(){
        for (int i = 0; i < m_n; i++){
            std::cout << "| ";
            for (int j = 0; j < m_n; j++)
                std::cout << marr [i][j] << " | ";

            std::cout << std::endl;
        }
    }

    // Деструктор

    ~Matrix(){
        for (int i = 0; i < m_n; i++)
            delete [] marr[i];
        delete [] marr;
    }

};

#endif // MATRIX_H
