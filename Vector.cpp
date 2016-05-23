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
        throw "Nieudana operacja";
        set_null();
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
        set_null();
        throw "Nieudana operacja";
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
    if(orig.size_m > 0 && orig.vector_m != NULL)
    {
        vector_m = new int[orig.size_m];
        size_m = orig.size_m;
        for(int i = 0; i < size_m; ++i)
            vector_m[i] = orig.vector_m[i];
    }
    else
    {
        set_null();
        throw "Blad ";
    }
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
    Vector suma(0);
    if(size_m == vector.size_m)
    {
        suma = Vector(size_m);
        for(int i = 0; i < size_m; ++i)
            suma.vector_m[i] = vector_m[i] + vector.vector_m[i];
    }
    return suma;
}
Vector Vector::operator -(const Vector& vector) const
{
    Vector suma(0);
    if(size_m == vector.size_m)
    {
        suma = Vector(size_m);
        for(int i = 0; i < size_m; ++i)
            suma.vector_m[i] = vector_m[i] - vector.vector_m[i];
    }
    return suma;
}
Vector Vector::operator +=(const Vector& vector)
{
    if(size_m == vector.size_m)
    {
        for(int i = 0; i < size_m; ++i)
            vector_m[i] += vector.vector_m[i];
    }
    return *this;
}
Vector Vector::operator -=(const Vector& vector)
{
    if(size_m == vector.size_m)
    {
        for(int i = 0; i < size_m; ++i)
            vector_m[i] -= vector.vector_m[i];
    }
    return *this;
}
Vector Vector::operator *(int value)
{
    Vector iloczyn(size_m);
    if(vector_m != NULL)
    {
        for(int i = 0; i < size_m; ++i)
            iloczyn.vector_m[i] = value * vector_m[i];
    }
    return iloczyn;
}
Vector operator*(int value, const Vector & vector)
{
    Vector iloczyn(vector.size_m);
    if(vector.vector_m != NULL)
    {
        for(int i = 0; i < vector.size_m; ++i)
            iloczyn.vector_m[i] = value * vector.vector_m[i];
    }
    return iloczyn;
}
Vector Vector::operator *=(int value)
{
    if(vector_m != NULL)
    {
        for(int i = 0; i < size_m; ++i)
            vector_m[i] *= value;
    }
    return *this;
}
int Vector::operator [](int i) const
{
        return vector_m[i];
}
ostream & operator<<(ostream & os, const Vector & vector)
{
    for(int i = 0; i < vector.size_m; ++i)
        os<<vector.vector_m[i]<<" ";
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

