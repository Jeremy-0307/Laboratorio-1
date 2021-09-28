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
#include "Laberinto.h"

 */
#include "Laberinto.h"
#include <iostream>
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {


    string reglas = "Bienvenido a ´Caza el Wumpus´\n";
    int opcion1;
    cout << "Desea ver las reglas?\n 1-) Si\n2-) No" << endl;
    cin >> opcion1;
    if (opcion1 == 1) {
        cout << reglas << endl;
    }
    //laberinto creado
    Laberinto lbrt;
    lbrt.cazador.asgPosicion(0);
    for(int c = 0; c<100; c++){
        cout << "cueva: "<<rand() % (lbrt.obtCantidadCuevas()) <<endl;
    }
    //int randNum = rand()%(max-min + 1) + min;
    cout << " obtCantidadCuevas: "<< lbrt.obtCantidadCuevas();
    int posicionInicialW = rand() % lbrt.obtCantidadCuevas();
    lbrt.wumpus.asgPosicion(2);


    bool JuegoTerminado = false;

    while (JuegoTerminado == false) {
        int opcion2;
        //cout << "Tienes " << laberinto.cazador.obtCantidadFlechas() << endl;
        cout << "Disparar o Moverse?\n 1-) Disparar \n2-) Moverse" << endl;
        cin >> opcion2;
        if(opcion2 == 1){
            //Disparar flecha, aun no estoy muy seguro de como funciona :/

        }
        else{    
            cout << "A cual cueva desea moverse?" ;
        }
        JuegoTerminado=true;

    }
    return 0;

}

