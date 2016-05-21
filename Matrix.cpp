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
    matrix_m = new Vector[rows_m];
    //trzeba zrobic jakos obsluge bledow
    if(matrix_m != NULL)
    {
        matrix_m[0] = Vector(cols_m);
        matrix_m[1] = Vector(cols_m);
    }
}
Matrix::Matrix(int rows, int cols)
{
    if(rows < 1 || cols < 1)
    {
        set_null();
    }
    else 
    {
        rows_m = rows;
        cols_m = cols;
        matrix_m = new Vector[rows_m];
        if(matrix_m != NULL)
          for(int i = 0; i < cols_m; ++i)
              matrix_m[i] = Vector(cols_m);
    }
}
/*Matrix::Matrix(int rows, int cols, Vector* tab)
{
    if(rows < 1 || cols < 1)
    {
        set_null();
    }
    else 
    {
        rows_m = rows;
        cols_m = cols;
        matrix_m = new Vector[rows_m];
        if(matrix_m != NULL)
          for(int i = 0; i < cols_m; ++i)
              matrix_m[i] = tab[i];
    }
}
Matrix::Matrix(const Matrix& orig) 
{
    matrix_m = new Vector(orig.rows_m);
    if(matrix_m != NULL)
    {
        rows_m = orig.rows_m;
        cols_m = orig.cols_m;
        for(int i = 0; i < cols_m; ++i)
        matrix_m[i] = orig.matrix_m[i];
    }
}*/
Matrix::~Matrix() 
{
    /*for (int i = 0; i < cols_m; i++)
        delete  (matrix_m + i);*/
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
        for (int i = 0; i < cols_m; i++)
            delete  (matrix_m + i);
        delete [] matrix_m; 
        rows_m = matrix.rows_m;
        cols_m = matrix.cols_m;
        matrix_m = new Vector[rows_m];
        if(matrix_m != NULL)
            for(int i = 0; i < cols_m ; ++i)
                matrix_m[i] = matrix.matrix_m[i];
    }
    return *this;
}
ostream & operator<<(ostream & os, const Matrix & matrix)
{
    for(int i = 0; i < matrix.cols_m; ++i)
        os<<matrix.matrix_m[i]<<endl;
    return os;
}
