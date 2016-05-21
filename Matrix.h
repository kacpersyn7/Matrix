/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.h
 * Author: kacper
 *
 * Created on 20 maja 2016, 17:48
 */

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Vector.h"
class Matrix 
{
    public:
        Matrix();
        Matrix(int rows, int cols);
       // Matrix(int rows, int cols, Vector** tab);
        Matrix(const Matrix& orig);
        virtual ~Matrix();
        
        Matrix & operator=(const Matrix & matrix);
        
        friend ostream & operator<<(ostream & os, const Matrix & matrix);
        
    private:
        Vector *matrix_m;
        int rows_m;
        int cols_m;
        void set_null(){rows_m = 0; cols_m = 0; matrix_m = NULL;}
    
};

#endif /* MATRIX_H */

