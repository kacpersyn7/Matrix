/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kacper
 *
 * Created on 10 maja 2016, 10:53
 */

#include <cstdlib>
#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include <stdlib.h>
/*
 * 
 */
int main(int argc, char** argv) {
    using namespace std;
    try
    {
        Matrix m1(2,2);
        Matrix m2(2,2);
        cout<<"Podaj pierwsza macierz\n";
        cin>>m1;
        cout<<"Podaj druga macierz\n";
        cin>>m2;
        cout<<"mnozenie\n";
        cout<<(m1*m2);
        cout<<"dodawanie\n";
        cout<<(m1+m2);
        cout<<"odejmowanie\n";
        cout<<(m1-m2);
        cout<<"mnozenine przez skalar 2*m1*2\n";
        cout<<(2*m1*2);
        cout<<"przypisanie v1 = v2\n";
        m1 = m2;
        cout<<m1;
        Matrix m3(m1);
        cout<<"konstruktor kopiujacy\n";
        cout<<m3;
        
    }
    catch(const char * s)
    { 
        cout<<s<<endl;
        cout<<"Koncze wykonywanie programu\n\n ";
        exit(EXIT_FAILURE);
    }

    catch(std::bad_alloc & c)
    {
        cout << c.what()<<endl;
        cout << "Koncze wykonywanie programu\n\n";
    }
    return 0;
}

