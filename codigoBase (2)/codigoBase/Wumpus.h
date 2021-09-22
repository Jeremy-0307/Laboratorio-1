
class Wumpus {
public:

    /* CONSTRUCTORES: */
    Wumpus();
    Wumpus(const Wumpus& orig);

    /* DESTRUCTOR: */
    virtual ~Wumpus();

    // EFE: retorna la identificación del cueva donde se encuentra el Wumpus.
    int obtPosicion();

    // REQ: 0 <= npw <= laberinto.
    // EFE: modifica la posición donde se encuentra el Wumpus a npw.
    void asgPosicion(int npw);

    // EFE: retorna true si el Wumpus está vivo.
    bool estaVivo();

    // EFE: cambia el estado a no vivo.
    void matar();

    // EFE: retorna true si el Wumpus está dormido.
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
    return posicion; // modifique con su código
}

void Wumpus::asgPosicion(int npw) {
    posicion = npw;
}

bool Wumpus::estaVivo() {
    return vivo; // modifique con su código
}

void Wumpus::matar() {
    vivo = false;
}

bool Wumpus::estaDormido() {
    return dormido; // modifique con su código
}

void Wumpus::despertar() {
    domido = false;
}