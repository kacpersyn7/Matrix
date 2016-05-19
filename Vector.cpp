/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector.cpp
 * Author: kacper
 * 
 * Created on 10 maja 2016, 10:59
 */

#include "Vector.h"
Vector::Vector()
{
    size_m = 2; 
    vector_m = new int[2];
    vector_m[0] = 0;
    vector_m[1] = 0;
}
Vector::Vector(int size, int *vector) 
{
    if(size < 1)
    {
        size_m = 2; 
        vector_m = new int[2];
        vector_m[0] = 0;
        vector_m[1] = 0;
    }
    else
    {
        size_m = size;
        vector_m = new int[size_m];
        for(int i = 0; i < size_m; ++i)
            vector_m[i] = vector[i];
    }
}
Vector::Vector(const Vector& orig) 
{
}
ostream & operator<<(ostream & os, const Vector & vector)
{
    for(int i = 0; i < vector.size_m; ++i)
        os<<vector.vector_m[i]<<"\n";
    return os;
}
istream & operator>>(istream & os, const Vector & vector)
{
    int *pointer = vector.vector_m;
    for (int i = 0; i < vector.size_m; i++)
        cin >> pointer[i];
    return os;
}
Vector::~Vector() 
{
    size_m = 0;
    delete [] vector_m;
}

