#pragma once

class Cazador {
    // Representa el estado del cazador.
public:

    /* CONSTRUCTORES: */

    // EFE: construye un cazador no ubicado en el laberinto (posición == 0) con 
    // y con 5 flechas.
    Cazador();

    // EFE: construye una copia de cazador idéntica a orig.
    Cazador(const Cazador& orig);

    /* DESTRUCTOR: */
    virtual ~Cazador();

    /* MÉTODOS OBSERVADORES: */

    // EFE: retorna la identificación de la cueva ocupada por el cazador.
    int obtPosicion();

    // EFE: retorna la cantidad de flechas disponibles para el cazador.
    int obtFlechas();

    // EFE: retorna true si el cazador está vivo y false en caso contrario.
    bool estaVivo();

    // EFE: cambia el estado del cazador a no vivo.
    void matar();
    /* MÉTODOS MODIFICADORES: */

    // REQ: que 1 <= np <= N, con N == laberinto.cantidadCuevas().
    // MOD: posición de *this.
    // EFE: cambia la posición del cazador a np.
    void asgPosicion(int np);

    // REQ: 1 <= this->obtFlechas().
    // MOD: flechas disponibles para *this (el cazador).
    // EFE: reduce en UNO las flechas disponibles para el cazador (*this).
    void reducirFlechas();

private:
    int posicion; // de 1 a N según estructura del laberinto.
    int flechas; // cantidad de flechas disponibles: 0..5; empieza en 5
    bool vivo;
};

Cazador::Cazador() {
    posicion = 0;
    flechas = 5;
    vivo = true;
}

Cazador::Cazador(const Cazador& orig) {
    posicion = orig.posicion;
    flechas = orig.flechas;
    vivo = orig.vivo;
}
Cazador::~Cazador() {
    int* pointer1 = &posicion;
    int* pointer2 = &flechas;
    bool* pointer3 = &vivo;
    delete pointer1;
    delete pointer2;
    delete pointer3;
}

int Cazador::obtPosicion() {
    return posicion; // modifique con su código
}

int Cazador::obtFlechas() {
    return flechas; // modifique con su código
}

bool Cazador::estaVivo() {
    return vivo; // modifique con su código
}

void Cazador::matar() {
    vivo = false;
}

void Cazador::asgPosicion(int np) {
    posicion = np;
}

void Cazador::reducirFlechas() {
    flechas = flechas - 1;
}


