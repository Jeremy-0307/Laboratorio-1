#pragma once

class Cueva {
    // Representa una cueva del laberinto.
public:
    /* TIPO PÚBLICO DE ESTADOS DE UNA CUEVA */
    enum Estado {
        // representa el estado de la cueva
        M, // representa Murciélagos transportadores
        P, // representa un Pozo
        V, // representa una cueva Vacía, sin trampas
    };
    
    /* CONSTRUCTORES: */
    // EFE: construye una cueva con id == 0 y estado == V.
    Cueva();
    
    // EFE: construye una cueva con id = idCueva y estado = V.
    Cueva(int idCueva);
    
    // EFE: construye una cueva con id == 0 y estado == e.
    Cueva(Estado e);
    
    // EFE: construye una cueva con id == idCueva y estado == e.
    Cueva(int idCueva, Estado e);
    
    // EFE: construye una cueva con estado orig.e.
    Cueva(const Cueva& orig);
    
    /* DESTRUCTOR */
    virtual ~Cueva();
    
    /* MÉTODOS OBTENEDORES: */
 
    // EFE: retorna el idCueva de *this.
    int obtIdCueva();
    
    // EFE: retorna el estado de *this.
    Estado obtEstado();
    
    /* MÉTODOS MODIFICADORES: */
    
    // REQ: 1 <= idCuevaN <= laberinto.obtCantidadCuevas().
    // MOD: *this.
    // EFE: cambia la idCueva de this.
    void asgIdCueva(int idCuevaN);
    
    // MOD: *this
    // EFE: cambia el estado de this al nuevo estado ne.
    void asgEstado(Estado ne);

    
private:
    int id; // identificación de la cueva.
    Estado e; // estado de la cueva
};

Cueva::Cueva() {
    id = 0;
    e = V;

}

Cueva::Cueva(int idCueva){
    id = idCueva;
    e = V;
}

Cueva::Cueva(Cueva::Estado eN){
    id = 0;
    e = eN;
}

Cueva::Cueva(int idCueva, Cueva::Estado eN){
    id = idCueva;
    e = eN;
}

Cueva::Cueva(const Cueva& orig) {
    id = orig.id;
    e = orig.e;
}

Cueva::~Cueva() {
   /* delete e;
    delete id;*/
}

void Cueva::asgEstado(Estado ne){
    e = ne;
}

Cueva::Estado Cueva::obtEstado(){
    return e;  
}


