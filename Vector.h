/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector.h
 * Author: kacper
 *
 * Created on 10 maja 2016, 10:59
 */

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdexcept>
using namespace std;
class Vector 
{
    public:
        Vector(int size, int *vector);
        Vector(const Vector& orig);
        Vector();
        virtual ~Vector();
        
        bool operator==(const Vector & vector) const;
        bool operator!=(const Vector & vector) const; 
        Vector operator+(const Vector & vector) const; 
        Vector operator-(const Vector & vector) const; 
        Vector operator+=(const Vector & vector); 
        Vector operator-=(const Vector & vector); 
        Vector operator*(int value);
        Vector operator*=(int value);
        
        friend ostream & operator<<(ostream & os, const Vector & vector);
        friend istream & operator>>(istream & os, const Vector & vector);
    private:
        int *vector_m;
        int size_m;
};

#endif /* VECTOR_H */

