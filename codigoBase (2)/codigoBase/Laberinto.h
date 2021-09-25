#pragma once

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "ListaCuevasAdy.h"
#include "Cueva.h"
#include "Cazador.h"
#include "Wumpus.h"


class Laberinto {
    // Representa la red de cuevas o laberinto que recorre el cazador y en alguna
    // de las cuales se encuentra el Wumpus.
public:
    /* TIPO DE ESTRUCTURAS DE LABERINTOS */
    enum TipoPoliedroRegular {
       C, // representa al cubo
       D, // representa al dodecaedro
       I, // representa al icosaedro
       O, // representa al octaedro
       T  // representa al tetraedro
    };
    
    /* CONSTRUCTORES: */
    // EFE: construye un laberinto con estructura de dodecaedro.
    Laberinto();
    
    // EFE: construye un laberinto con la misma estructura y escenario que orig.
    Laberinto(const Laberinto& orig);
    
    // EFE: construye un laberinto con la estructura del poliedro p:
    Laberinto(TipoPoliedroRegular p);
    
    // EFE: construye un laberinto con la estructura representada en el archivo
    //      cuyo nombre es nombreArchivo.
    Laberinto(string nombreArchivo);
    /* DESTRUCTOR: */
    virtual ~Laberinto();
    
    /* MÉTODOS OBSERVADORES: */

    // REQ: que idCueva exista como identificación de alguna cueva en *this.
    // EFE: retorna el estado de la cueva con identificación idCueva.
    Cueva::Estado obtEstado(int idCueva) const;
    
    // EFE: retorna la cantidad de cuevas del laberinto.
    int obtCantidadCuevas() const;
    
    // REQ: que idCueva exista como identificación de alguna cueva en *this.
    // EFE: retorna un puntero a un arreglo de enteros con las identificaciones
    //      de las cuevas adyacentes a idCueva.
    // NOTA: el contexto invocador es responsable de aplicar delete[] al arreglo.
    int* obtCuevasAdy(int idCueva) const;

    // REQ: que idCueva exista como identificación de alguna cueva en *this.
    // EFE: retorna la cantidad de cuevas adyacentes a idCueva.
    int obtCantidadCuevasAdy(int idCueva) const;

    
    // REQ: que idCuevaOrigen y idCuevaObjetivo existan como identificaciones de
    //      de cueva en *this.
    // EFE: retorna -1 si el flechazo mata al cazador, 1 si el flechazo mata al
    //      Wumpus y 0 si no sucede nada con el flechazo.
    // NOTA: durante el juego idCuevaOrigen será la cueva en que se encuentra
    //       el cazador, mientras que idCuevaObjetivo es la dirección que 
    //       selecciona el jugador para la flecha, la cueva por donde sale.
    int obtResultadoFlechazo(int idCuevaOrigen, int idCuevaObjetivo) const;
    
    /* MÉTODOS MODIFICADORES: */
    
    // EFE: asigna un escenario al azar a *this.
    // NOTA: Por escenario se debe entender el estado de cada una de las cuevas 
    // incluyendo la ubicación del Wumpus y la posición inicial del cazador. 
    // La posición inicial del cazador siempre será en una cueva cuyo estado es Vacía.
    void asgEscenario();
    
    // REQ: !laberinto.wumpus.estaDormido() && laberinto.wumpus.estaVivo().
    // MOD: puede cambiar la posición del Wumpus.
    // EFE: aplica regla de movimiento al azar del Wumpus.
    int compGuess = rand() % 100 + 1; //Generates number between 1 - 100
    void moverWumpusAzar();
    
    // REQ: laberinto.cazador.estaVivo().
    // MOD: la posición del cazador.
    // EFE: traslada al cazador a otra cueva seleccionada al azar.
    //      aplica la regla de traslado del cazador por los murciélagos.
    void moverCazadorAzar();

public:
    
    /* Se hacen públicas porque ambos están en el laberinto pero son visibles 
     * desde el controlador del juego (el main).
     */
    
    Cazador cazador;
    Wumpus wumpus;
    
private:
    
    /* Estructura de datos del Laberinto */
    struct NodoLaberinto{
        Cueva cueva; // cueva en el laberinto
        ListaCuevasAdy listaCuevasAdy; // lista de idCueva de cuevas adyacentes
        NodoLaberinto(){}; // sólo constructor estándar
    };

    int cantidadCuevas; // representa la cantidad de cuevas en el laberinto
    
    // puntero al arreglo de cuevas numeradas de 1 a N. No puede ser un 
    // shared_ptr porque estos no permiten el manejo de arreglos.
    NodoLaberinto* arregloCuevas;    
};

Laberinto::Laberinto(){
    cantidadCuevas = 8;
    for (int c = 0; c < cantidadCuevas; c++) {
        //los valores son la distancia entre las 3 cuevas adyacentes
        int valor1 = 2, valor2 = 2, valor3 = 1;
        if (c <= 9) {
            if (c % 2 != 0) {
                valor1 = 9, valor2 = 7, valor3 = -1;
            }
        }
        else {
            if (c % 2 != 0) {
                valor3 = -1;
            }
            else {
                valor1 = 9; valor2 = 7;
            }
        }
        if (c == 0 || c == 11) {
            valor3 = 8;
        }
        else if (c == 1) {
            valor3 = 17;
        }
        arregloCuevas[c].cueva.asgIdCueva(c);
        arregloCuevas[c].listaCuevasAdy.agrIdCuevaAdy(c+valor1);
        arregloCuevas[c].listaCuevasAdy.agrIdCuevaAdy(c+valor2);
        arregloCuevas[c].listaCuevasAdy.agrIdCuevaAdy(c+valor3);
    }

}

Laberinto::Laberinto(const Laberinto& orig){
}

Laberinto::~Laberinto() {
    /*delete cazador;
    delete wumpus;
    if (arregloCuevas == 0) {
        delete inicio;
    }
    else {
        NodoLaberinto* ultimo = arregloCuevas;
        while (ultimo->idCueva->listaCuevaAdy->cantidadAdy != 0) {
            ultimo = ultimo->sgtCueva;
            delete arregloCuevas;
            arregloCuevas = ultimo;
        }
    }
    delete cantidadAdy;*/
}

Laberinto::Laberinto(TipoPoliedroRegular p) {
}

Laberinto::Laberinto(string nombreArchivo) {
    int cantidadCuevas = 0;
    string linea;
    string entero;
    ifstream archivo(nombreArchivo, ios::in);

    if (!archivo) {
        cout << "no se pudo abrir el archivo "<<nombreArchivo<<".txt " << endl;
        exit(1);
    }
    // luego se agregan las adyacencias salientes y entrantes:
    while (archivo >> linea) {
        cantidadCuevas++;
        stringstream s(linea);
        while (getline(s, entero, ',')) {
            int d = stoi(entero);
            cout << d << ',';
        }
        cout << endl;
    }
}

Cueva::Estado Laberinto::obtEstado(int idCueva) const {
     return arregloCuevas[idCueva].cueva.obtEstado();
    /*if(idCueva >= 0 && idCueva <= cantidadCuevas){
        return arregloCuevas[idCueva].cueva.obtEstado();
    }
    else{
        return null;
        //No se que retornar en caso de que la cueva no exista :/
    } */ 
}

int Laberinto::obtCantidadCuevas() const {
    return cantidadCuevas;  // sustituya con su propio codigo
}

int* Laberinto::obtCuevasAdy(int idCueva) const {
    int* arreglo;

   /* ListaCuevasAdy ultimo;
    ultimo = arregloCuevas[idCueva].listaCuevasAdy;
    if(idCueva >= 0 && idCueva <= cantidadCuevas){
        int c = 0;
        while(ultimo!=nullptr){
            arreglo[c] = ultimo->idCueva;
            ultimo = ultimo->sgtCueva;
            c++;
        }
    }
    hay que mejorar este codigo, queda muy raro/no funciona*/
    return arreglo;
}

int Laberinto::obtCantidadCuevasAdy(int idCueva) const{
    int resultado = arregloCuevas[idCueva].listaCuevasAdy.obtCantidadAdy();
    return resultado;
}

// REQ: que idCuevaOrigen y idCuevaObjetivo existan como identificaciones de
    //      de cueva en *this.
    // EFE: retorna -1 si el flechazo mata al cazador, 1 si el flechazo mata al
    //      Wumpus y 0 si no sucede nada con el flechazo.
    // NOTA: durante el juego idCuevaOrigen será la cueva en que se encuentra
    //       el cazador, mientras que idCuevaObjetivo es la dirección que 
    //       selecciona el jugador para la flecha, la cueva por donde sale.

int Laberinto::obtResultadoFlechazo(int idCuevaOrigen, int idCuevaObjetivo) const {
    return 0;  // sustituya con su propio codigo
}

void Laberinto::asgEscenario() {
    /*int contadorCuevas = 0, contadorPozos = 0, c = 0;
    while(contadorCuevas <= cantidadCuevas){
        int random = rand() % 4;
        if(random == 4){
            arregloCuevas[c].cueva.Estado = 0;
        }
        else{
            arregloCuevas[c].cueva.Estado = V;       
        }
    }*/

    
}
void Laberinto::moverWumpusAzar() {
    if (wumpus.estaVivo()) {
        int nuevaPosicion = rand() % obtCantidadCuevas();
        wumpus.asgPosicion(nuevaPosicion);
    }
}

void Laberinto::moverCazadorAzar() {
    int nuevaPosicion = rand() % obtCantidadCuevas();
    cazador.asgPosicion(nuevaPosicion);
}