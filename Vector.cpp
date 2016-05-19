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
////////////////////
////////////////////
//konstruktory
Vector::Vector()
{
    size_m = 2; 
    vector_m = new int[size_m];
    vector_m[0] = 0;
    vector_m[1] = 0;
}
Vector::Vector(int size)
{
    if(size < 1)
    {
        size_m = 0; 
        vector_m = NULL;
    }
    else
    {
        size_m = size;
        vector_m = new int[size_m];
        for(int i = 0; i < size_m; ++i)
            vector_m[i] = 0;
    }
}
Vector::Vector(int size, int *tab) 
{
    if(size < 1)
    {
        size_m = 0; 
        vector_m = NULL;
    }
    else
    {
        size_m = size;
        vector_m = new int[size_m];
        for(int i = 0; i < size_m; ++i)
            vector_m[i] = tab[i];
    }
}
Vector::Vector(const Vector& orig) 
{
    vector_m = new int[orig.size_m];
    size_m = orig.size_m;
    for(int i = 0; i < size_m; ++i)
        vector_m[i] = orig.vector_m[i];
}
////////////////////
////////////////////
//przeciazenia operatorow
Vector & Vector::operator=(const Vector& vector)
{
    if (this != &vector)
    {  
        delete [] vector_m;
        size_m = vector.size_m;
        vector_m = new int[vector.size_m];
        for(int i = 0; i < vector.size_m; ++i)
            vector_m[i] = vector.vector_m[i];
    }
    return *this;
}
bool Vector::operator==(const Vector& vector) const
{
    bool value = false;
    if(this == &vector)
        value = true;
    else if (size_m == vector.size_m)
    {  
        for(int i = 0; i < size_m; ++i)
            if(vector_m[i] != vector.vector_m[i])
                break;
        value = true;
    }
    
    return value;
}
bool operator!=(const Vector & first,const Vector & second) 
{
    return !(first == second);
}
Vector Vector::operator +(const Vector& vector) const
{
    static Vector suma;
    suma.~Vector();
    if(size_m == vector.size_m)
    {
        suma = Vector(size_m);
        for(int i = 0; i < size_m; ++i)
            suma.vector_m[i] = vector_m[i] + vector.vector_m[i];
    }
    else
    {
        suma.size_m = 0; 
        suma.vector_m = NULL;
    }
    return suma;
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

