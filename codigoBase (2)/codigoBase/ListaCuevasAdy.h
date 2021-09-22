
#include <memory>
#include <string>
using namespace std;

class ListaCuevasAdy {
    // Representa una lista ligada con las identificaciones de las cuevas 
    // adyacentes a una cueva dada en el laberinto.

public:
    
    /* CONSTRUCTORES: */
    
    // EFE: construye una ListaCuevasAdy vacía. Cantidad de adyacencias en cero.
    ListaCuevasAdy();
    
    // EFE: construye una ListaCuevasAdy idéntica a orig (mismo contenido).
    ListaCuevasAdy(const ListaCuevasAdy& orig);
    
    /* DESTRUCTOR: */
    virtual ~ListaCuevasAdy();

    /* MÉTODOS OBSERVADORES: */
 
    // EFE: retorna la cantidad de adyacencias en *this.
    int obtCantidadAdy();
    
    // EFE: retorna un puntero a un arreglo de enteros que contiene los identificadores
    //      de las cuevas adyacentes.
    // NOTA 1: retorna null si *this está vacía.
    // NOTA 2: el contexto invocador es responsable de aplicar delete[] al arreglo.
    int* obtAdyacencias();
    
    // EFE: retorna una hilera con las identificaciones de las cuevas en *this separadas por coma.
    string toString();
    
    /* MÉTODOS MODIFICADORES: */
    
    // EFE: agrega un elemento a *this con idCueva == id.
    //      incrementa en uno la cantidad de adyacencias.
    void agrIdCuevaAdy(int id);


private:

    struct NodoListaCuevasAdy {
        // atributos del nodo:
        int idCueva; // identificación de cueva adyacente
        shared_ptr<NodoListaCuevasAdy> sgtCueva; // siguiente nodo de la ListaCuevasAdy
        
        // constructores del nodo:
        NodoListaCuevasAdy(): idCueva(0), sgtCueva(nullptr){};
        NodoListaCuevasAdy(int id): idCueva(id), sgtCueva(nullptr){};
        NodoListaCuevasAdy(const NodoListaCuevasAdy& orig): idCueva(orig.idCueva), sgtCueva(orig.sgtCueva){};
    };
    
    shared_ptr<NodoListaCuevasAdy> inicio; // puntero al primer nodo
    int cantidadAdy; // cantidad de adyacencias en la lista
};

ListaCuevasAdy::ListaCuevasAdy() {
    cantidadAdy = 0;
    inicio = NodoListaCuevasAdy();
}

ListaCuevasAdy::ListaCuevasAdy(const ListaCuevasAdy& orig) {
    cantidadAdy = orig->cantidadAdy;
    inicio = orig->inicio;
}

ListaCuevasAdy::~ListaCuevasAdy() {

    if (inicio == 0) {
        delete inicio;
    }
    else {
        shared_ptr<NodoListaCuevasAdy>* ultimo = inicio;
        while (ultimo->idCueva != 0) {
            ultimo = ultimo->sgtCueva;
            delete inicio;
            inicio = ultimo;
        }
    }
    delete cantidadAdy;
}

void ListaCuevasAdy::agrIdCuevaAdy(int id) {
   
    if (inicio == 0) {
        inicio = NodoListaCuevasAdy(id);
    }
    else {
        shared_ptr<NodoListaCuevasAdy>* ultimo = inicio->sgtCueva;
        while (ultimo->idCueva != 0) {
            ultimo = ultimo->sgtCueva;
        }
        ultimo = NodoListaCuevasAdy(id);
    }
}

int ListaCuevasAdy::obtCantidadAdy(){  
    return cantidadAdy;  
}

int* ListaCuevasAdy::obtAdyacencias(){
    int* arreglo = 0;
    return arreglo; 
}

string ListaCuevasAdy::toString() {
    string resultado = "";
    shared_ptr<NodoListaCuevasAdy>* ultimo = inicio->sgtCueva;
    if (inicio == 0) {
        //do nothing
    }
    else {
        resultado = inicio->idCueva;
        while (ultimo->idCueva != 0) {
            resultado = resultado << ", " << ultimo;
            ultimo = ultimo->sgtCueva;
        }
    }
    return resultado; 
}
