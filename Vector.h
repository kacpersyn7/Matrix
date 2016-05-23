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
using namespace std;
class Vector 
{
    public:
        Vector(int size, int *tab);// \/
        Vector(const Vector& orig);// \/
        Vector(int size);
        Vector();// \/
        virtual ~Vector();// \/
        
        Vector & operator=(const Vector & vector);// \/
        
        bool operator==(const Vector & vector) const;// \/
        friend bool operator!=(const Vector & first,const Vector & second) ; // \/
        
        Vector operator+(const Vector & vector) const; // \/
        Vector operator-(const Vector & vector) const; 
        Vector operator+=(const Vector & vector); // \/
        Vector operator-=(const Vector & vector);// \/ 
        Vector operator*(int value);// \/
        Vector operator*=(int value);// \/
        //moze lepiej void
        int operator[](int i);
        int change_value(int i, int value);
        friend Vector operator*(int value, const Vector & vector);
        friend ostream & operator<<(ostream & os, const Vector & vector);
        friend istream & operator>>(istream & os, const Vector & vector);
    private:
        int *vector_m;
        int size_m;
        void set_null(){size_m = 0; vector_m = NULL;}
        
};

#endif /* VECTOR_H */

