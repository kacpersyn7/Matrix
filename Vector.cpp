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

Vector::Vector(int size, int *vector) 
{
    if(size < 1)
    {
        vector = NULL;
        size = 0;
    }
}

Vector::Vector(const Vector& orig) 
{
}

Vector::~Vector() 
{
}

