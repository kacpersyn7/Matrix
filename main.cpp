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

/*
 * 
 */
int main(int argc, char** argv) {
    using namespace std;
    int tab[3] = {1,2,3};
    int table[3] = {1,4,3};
    Vector vector(3,tab);
    Vector cos(3,table);
    cout<<cos+vector;
    return 0;
}

