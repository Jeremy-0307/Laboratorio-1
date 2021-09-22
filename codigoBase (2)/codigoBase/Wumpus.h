
class Wumpus {
public:

    /* CONSTRUCTORES: */
    Wumpus();
    Wumpus(const Wumpus& orig);

    /* DESTRUCTOR: */
    virtual ~Wumpus();

    // EFE: retorna la identificaci�n del cueva donde se encuentra el Wumpus.
    int obtPosicion();

    // REQ: 0 <= npw <= laberinto.
    // EFE: modifica la posici�n donde se encuentra el Wumpus a npw.
    void asgPosicion(int npw);

    // EFE: retorna true si el Wumpus est� vivo.
    bool estaVivo();

    // EFE: cambia el estado a no vivo.
    void matar();

    // EFE: retorna true si el Wumpus est� dormido.
    bool estaDormido();

    // EFE: cambia el estado a no dormido.
    void despertar();

private:
    int posicion;
    bool vivo;
    bool dormido;
};

Wumpus::Wumpus() {
      
}

Wumpus::Wumpus(const Wumpus& orig) {
    posicion = orig->posicion;
    vivo = orig->posicion;
    dormido = orig->dormido;
}

Wumpus::~Wumpus() {
    delete posicion;
    delete vivo;
    delete dormido;
}

int Wumpus::obtPosicion() {
    return posicion; // modifique con su c�digo
}

void Wumpus::asgPosicion(int npw) {
    posicion = npw;
}

bool Wumpus::estaVivo() {
    return vivo; // modifique con su c�digo
}

void Wumpus::matar() {
    vivo = false;
}

bool Wumpus::estaDormido() {
    return dormido; // modifique con su c�digo
}

void Wumpus::despertar() {
    domido = false;
}