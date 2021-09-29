
#include <memory>
#include <string>
#include <iostream>
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
        NodoListaCuevasAdy(): idCueva(-1), sgtCueva(nullptr){};
        NodoListaCuevasAdy(int id): idCueva(id), sgtCueva(nullptr){};
        NodoListaCuevasAdy(const NodoListaCuevasAdy& orig): idCueva(orig.idCueva), sgtCueva(orig.sgtCueva){};
    };
    
    shared_ptr<NodoListaCuevasAdy> inicio; // puntero al primer nodo
    int cantidadAdy; // cantidad de adyacencias en la lista
};

ListaCuevasAdy::ListaCuevasAdy() {
    cantidadAdy = 0;
    inicio = shared_ptr<NodoListaCuevasAdy>(new NodoListaCuevasAdy());
}

ListaCuevasAdy::ListaCuevasAdy(const ListaCuevasAdy& orig) {
    cantidadAdy = orig.cantidadAdy;
    inicio = orig.inicio;
}

ListaCuevasAdy::~ListaCuevasAdy() {
}

void ListaCuevasAdy::agrIdCuevaAdy(int id) {
    if (inicio->idCueva == -1) {
        inicio = shared_ptr<NodoListaCuevasAdy>(new NodoListaCuevasAdy(id));
        cantidadAdy++;
    }
    else{
        cantidadAdy++;
        shared_ptr<NodoListaCuevasAdy> ultimo = inicio;
        while(ultimo != nullptr){
            ultimo = ultimo->sgtCueva;
        }
        ultimo = shared_ptr<NodoListaCuevasAdy>(new NodoListaCuevasAdy(id));
        ultimo->sgtCueva = inicio;
        inicio = ultimo;
    }

}

int ListaCuevasAdy::obtCantidadAdy(){  
    return cantidadAdy;  
}
    // EFE: retorna un puntero a un arreglo de enteros que contiene los identificadores
    //      de las cuevas adyacentes.
    // NOTA 1: retorna null si *this está vacía.
    // NOTA 2: el contexto invocador es responsable de aplicar delete[] al arreglo.

int* ListaCuevasAdy::obtAdyacencias(){
    int* arreglo;
    arreglo[10];
    if(cantidadAdy == 0){
        return nullptr;
    }
    else{
        shared_ptr<NodoListaCuevasAdy> ultimo = inicio; 
        for(int c = 1; c<=cantidadAdy;c++){
            int numero =  ultimo->idCueva;
            arreglo[c] = numero;
            ultimo = ultimo->sgtCueva;
            cout<<arreglo[c]<<" si no funciona me mato"<<endl;
        }     
    }
    return arreglo; 
}



string ListaCuevasAdy::toString() {
    string resultado = "";
    if (inicio == 0) {
    }
    else {      
        shared_ptr<NodoListaCuevasAdy> ultimo = inicio;
        while (ultimo != nullptr) {
            resultado +=  to_string(ultimo->idCueva) + ", ";
            ultimo = ultimo->sgtCueva;
        }
    }
    return resultado; 
}
