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
/*
 * 
 */
int main(int argc, char** argv) {
    using namespace std;
    Matrix m1(1,3);
    Matrix m2(3,1);
    cin>>m1;
    cin>>m2;
    cout<<(m1*m2);
    
    
    //cout<<macierz;
    /*cos += heheh;
    cout<<cos;
    cout<<(cos != heheh);
    
   /* Matrix ma;
    cin>>ma;
    cout<<ma;
    /*Matrix cos;
    cos = ma;
    cout<<cos;
    cout<<ma + cos + cos;
    cout<<"Dodawanie (+)\n";
    cout<<v1<<" + "<<v1<<" = "<<v1+v1<<endl;
    cout<<"odejmowanie (+)\n";
    cout<<v1<<" - "<<v2<<" = "<<v1-v2<<endl;
    cout<<"Dodawanie (+=)\n";
    v1+=v2;
    cout<<"v1"<<" +=  "<<"v2"<<" = "<<v1<<endl;
    cout<<"mnozenie (*)\n";
    cout<<2*v1*2<<endl;
    
    //cout<<ma;
  /*  cout<<v1<<" += "<<v2<<" = "<<v1+=v2;
    cout<<"odejmowanie (-=)\n";
    cout<<v1<<" -= "<<v2<<" = "<<v1-=v2;
    cout<<"mnozenie (*)\n";
    cout<<"2"<<" * "<<v2<<" = "<<(2*v2);
    cout<<"mnozenie (=)\n";
    cout<<"2"<<" =* "<<v2<<" = "<<(2*v2);*/  //cout<<"A\n"<<v1<<
    return 0;
}

