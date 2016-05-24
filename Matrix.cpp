/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.cpp
 * Author: kacper
 * 
 * Created on 20 maja 2016, 17:48
 */

#include "Matrix.h"
#include "Vector.h"
Matrix::Matrix() 
{
    rows_m = 2;
    cols_m = 2;
    matrix_m = new Vector*[rows_m];
    //trzeba zrobic jakos obsluge bledow
    if(matrix_m != NULL)
    {
        *(matrix_m) = new Vector(cols_m);
        *(matrix_m + 1) = new Vector(cols_m);
    }
}
Matrix::Matrix(int rows, int cols)
{
    if(rows < 1 || cols < 1)
    {
        set_null();
        throw "zla liczba wierszy lub kolumn";
    }
    else 
    {
        rows_m = rows;
        cols_m = cols;
        matrix_m = new Vector*[rows_m];
        if(matrix_m != NULL)
          for(int i = 0; i < rows_m; ++i)
              *(matrix_m + i) = new Vector(cols_m);
    }
}
Matrix::Matrix(const Matrix& orig) 
{
    matrix_m = new Vector*[orig.rows_m];
    if(matrix_m != NULL)
    {
        rows_m = orig.rows_m;
        cols_m = orig.cols_m;
        for(int i = 0; i < rows_m; ++i)
                *(matrix_m + i) = new Vector(cols_m);
        for(int i = 0; i < rows_m; ++i)
            *(matrix_m)[i] = *(orig.matrix_m)[i];
    }
    else
            throw "blad alokacji";
}
Matrix::~Matrix() 
{
    for (int i = 0; i < rows_m; ++i)
        delete  *(matrix_m + i);
    delete [] matrix_m; 
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
Matrix & Matrix::operator=(const Matrix& matrix)
{
    if (this != &matrix)
    {  
        for (int i = 0; i < rows_m; i++)
            delete  *(matrix_m + i);
        delete [] matrix_m; 
        rows_m = matrix.rows_m;
        cols_m = matrix.cols_m;
        matrix_m = new Vector*[rows_m];
        if(matrix_m != NULL)
        {
            for(int i = 0; i < rows_m; ++i)
                *(matrix_m + i) = new Vector(cols_m);
            for(int i = 0; i < rows_m ; ++i)
                *(matrix_m)[i] = *(matrix.matrix_m)[i];
        }
        else
            throw "blad alokacji";
    }
    return *this;
}
Matrix Matrix::operator +(const Matrix& matrix) const
{
    if(cols_m == matrix.cols_m && rows_m == matrix.rows_m)
    {
        Matrix suma(rows_m,cols_m);
        for(int i = 0; i < rows_m; ++i)
            (*(suma.matrix_m)[i]) = (*(matrix_m)[i]) + (*(matrix.matrix_m)[i]);
        return suma;
    }
    else
    {
        throw "tak nie wolno";
        return *this;
    }
}
Matrix Matrix::operator -(const Matrix& matrix) const
{
    if(cols_m == matrix.cols_m && rows_m == matrix.rows_m)
    {
        Matrix suma(rows_m,cols_m);
        for(int i = 0; i < rows_m; ++i)
            *(suma.matrix_m)[i] = *(matrix_m)[i] - *(matrix.matrix_m)[i];
        return suma;
    }
    else
    {
        throw "tak nie wolno";
        return *this;
    }
}
Matrix Matrix::operator *(int value) const
{
    Matrix iloczyn(rows_m,cols_m);
    if(*matrix_m != NULL)
    {
        for(int i = 0; i < rows_m; ++i)
            *(iloczyn.matrix_m)[i] = value * (*(matrix_m)[i]);
    }
    else
        throw "blad alokacji";
    return iloczyn;
}
Matrix operator*(int value, const Matrix & matrix)
{
    Matrix iloczyn(matrix.rows_m,matrix.cols_m);
    if(*matrix.matrix_m != NULL)
    {
        for(int i = 0; i < matrix.rows_m; ++i)
            *(iloczyn.matrix_m)[i] = value * (*(matrix.matrix_m)[i]);
    }
    else
        throw "blad alokacji";
    return iloczyn;
}
////////////////////////////////////////////
////////////////////////////////////////////
Matrix Matrix::operator *(const Matrix& matrix) const
{
    if(cols_m == matrix.rows_m)
    {
        Matrix iloczyn(rows_m,matrix.cols_m);
        int sum = 0;
        for(int i = 0; i < rows_m; ++i)
            for(int j = 0; j < rows_m; ++j)
            {
                for(int k = 0; k < cols_m ; ++k)
                    sum = sum + ((*(matrix_m)[i])[k]) * ((*(matrix.matrix_m)[k])[j]);
                (*(iloczyn.matrix_m)[i]).change_value(j,sum);
                sum = 0;
            }
        return iloczyn;
    }       
    else
        throw "tak nie wolno, liczba kolumn musi byc rowna liczbie wierszy drugiej macierzy";
        return *this;
    
}
void Matrix::operator +=(const Matrix& matrix)
{
    *this = *this + matrix; 
}
void Matrix::operator -=(const Matrix& matrix)
{
    *this = *this - matrix; 
}
void Matrix::operator *=(int value)
{
    *this = *this * value; 
}
///////////////////////////////////////////
///////////////////////////////////////////
bool Matrix::operator==(const Matrix& matrix) const
{
    bool value = false;
    if(this == &matrix)
        value = true;
    else if (cols_m == matrix.cols_m && rows_m == matrix.rows_m)
    {  
        for(int i = 0; i < rows_m; ++i)
            if(*(matrix_m)[i] != *(matrix.matrix_m)[i])
                break;
        value = true;
    }
    
    return value;
}
bool operator!=(const Matrix & first,const Matrix & second) 
{
    return !(first == second);
}
Vector Matrix::operator [](int i) 
{
    if(i<rows_m && i>0)
        return *(matrix_m)[i];
    else
    {
        return Vector(0);
        throw "blad";
    }
}
ostream & operator<<(ostream & os, const Matrix & matrix)
{
    for(int i = 0; i < matrix.rows_m; ++i)
        os<<(*(matrix.matrix_m)[i])<<endl;
    return os;
}
istream & operator>>(istream & os, const Matrix & matrix)
{
    Vector **pointer = matrix.matrix_m;
    for (int i = 0; i < matrix.rows_m; i++)
        cin >> *(pointer)[i];
    return os;
}