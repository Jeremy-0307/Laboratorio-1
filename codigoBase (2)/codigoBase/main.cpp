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

    int opcionLaberinto;
    cout << "En que tipo de laberinto le gustaría jugar?\n 1-) Dodecaedro\n2-) Cubo\n3-) Irregular (archivo)" << endl;

    switch(opcionLaberinto) {    
        case 1: 
        break;
        case 2: 
        break;
        default: 
        string nombreArchivo;
        cout << "Ingrese el nombre del archivo" << endl;
        cin >> nombreArchivo;
    }

    Laberinto lbrt;
    lbrt.asgEscenario();
    lbrt.cazador.asgPosicion(0);
    lbrt.moverWumpusAzar();

    //laberinto creado

    bool juegoAcabado = false;
    while(juegoAcabado == false){
        int opcion2;   
        cout << "Estas en la Cueva: "<<lbrt.cazador.obtPosicion()<<"\nDesea... \n1-) Disparar\n2-) Moverse" << endl;
        cin >> opcion2;
        if(opcion2 == 1){
            /*cout << "Desea... \n1-) Disparar\n2-) Moverse" << endl;
            int opcionFlechazo;
            switch(opcionFlechazo   ) {    
            case 1: 
            break;
            case 2: 
            break;
            default: 
        
            }*/
            //Laberinto.
        }
        else{
            int opcionMovimiento;
            bool movimientoValido = false;
            int* cuevasAdy = lbrt.obtCuevasAdy(lbrt.cazador.obtPosicion());
            for(int f = 0; f < lbrt.obtCantidadCuevasAdy(lbrt.cazador.obtPosicion()); f++){
                if(opcionMovimiento == cuevasAdy[f]){
                    movimientoValido = true;
                }
            }
            if(movimientoValido == true) lbrt.cazador.asgPosicion(opcionMovimiento);
            switch(lbrt.obtEstado(opcionMovimiento)){    
                case 1:
                    lbrt.moverCazadorAzar();
                    cout << "Habia un Murcielago en la cueva!\n Fuisto movido a la cueva: "<<lbrt.cazador.obtPosicion()<<endl;
                break;
                case 2: 
                    lbrt.cazador.matar();
                    cout << "AHHHHHHHHHHHHHHHHHHHHHH\nWOOPS! Caiste en un Pozo!"<<endl;
                break;      
            }
            juegoAcabado = (lbrt.cazador.estaVivo() == false ||  lbrt.wumpus.estaVivo() == false) ? true : juegoAcabado;
        }



        lbrt.obtCuevasAdy(0);
    }
    
    return 0;

}

