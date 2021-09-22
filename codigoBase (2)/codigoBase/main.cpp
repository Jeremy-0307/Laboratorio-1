/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alan
 *
 * Created on 18 de abril de 2017, 11:13 AM
 */

#include <iostream>
using namespace std;
#include "Laberinto.h"
/*
 * 
 */
int main(int argc, char** argv) {

    string reglas = "bla bla bla";
    int opcion1;
    cout << "Desea ver las reglas?\n 1-) Si\n2-) No" << opcion1;
    if (opcion1 == 1) {
        cout << reglas << endl;
    }
    bool loop = false;
    while (loop == false) {

    }
    Laberinto laberinto;
    
    return 0;
}

