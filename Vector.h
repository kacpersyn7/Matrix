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

class Vector 
{
    public:
        Vector(int size, int *vector);
        Vector(const Vector& orig);
        virtual ~Vector();
         
    private:
        int *vector;
        int size;
};

#endif /* VECTOR_H */

