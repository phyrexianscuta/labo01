#include "Lista.h"

template<typename T>
Lista<T>::Lista() {
    prim = nullptr;
    ult = nullptr;
}

// Inicializa una lista vacía y luego utiliza operator= para no duplicar el
// código de la copia de una lista.
template<typename T>
Lista<T>::Lista(const Lista<T> &l) : Lista() { *this = l; }

template<typename T>
Lista<T>::~Lista() {
    destruirNodos();
}

template<typename T>
void Lista<T>::destruirNodos() {
    Nodo* actual = prim;
    while (actual != nullptr){
         Nodo* siguiente = actual -> siguiente;
        delete actual;
        actual = siguiente;
    }
    prim = nullptr;

}

template<typename T>
Lista<T> &Lista<T>::operator=(const Lista<T> &l) {
    destruirNodos();
    copiarNodos(l);
    return *this;
}

template<typename T>
void Lista<T>::agregarAdelante(const T &elem) {
    if (longitud() == 0) {
        Nodo* nuevo = new Nodo(elem, nullptr, nullptr);
        prim = nuevo;
        ult = nuevo;

    } else {
        Nodo* nuevo = new Nodo(elem, nullptr, prim);
        prim -> anterior= nuevo;
        prim = nuevo;
    }
}

template<typename T>
void Lista<T>::agregarAtras(const T &elem) {
    if (longitud() == 0) {
        Nodo* nuevo = new Nodo(elem, nullptr, nullptr);
        prim = nuevo;
        ult = nuevo;

    } else {
        Nodo* nuevo = new Nodo(elem, ult, nullptr);
        ult -> siguiente = nuevo;
        ult = nuevo;
    }
}

template<typename T>
int Lista<T>::longitud() const {
    int contador = 0;
    Nodo *it = prim;
    while (it != nullptr) {
        contador++;
        it = it->siguiente;
    }

    return contador;
}

template<typename T>
typename Lista<T>::Nodo *Lista<T>::iesimoptr(Nat i) const {
    Nodo *it = prim;
    int contador = 0;
    while (contador != i) {
        it = it->siguiente;
        contador++;
    }
    return it;
}

template<typename T>
const T &Lista<T>::iesimo(Nat i) const {
    Nodo *it = prim;
    int contador = 0;
    while (contador != i) {
        it = it->siguiente;
        contador++;
    }
    return it->valor;
}

template<typename T>
void Lista<T>::eliminar(Nat i) {
    if(longitud()==1){
        delete prim;
        prim = nullptr;
        ult = nullptr;
    }
    else if(i == 0 ){
        Nodo* nuevoPrimero = iesimoptr(1);
        nuevoPrimero -> anterior = nullptr;
        delete prim;
        prim = nuevoPrimero;
    }
    else if(i == longitud()-1){
        Nodo* nuevoUltimo = iesimoptr(longitud()-2);
        nuevoUltimo -> siguiente = nullptr;
        delete ult;
        ult = nuevoUltimo;
    }
    else{
        Nodo* it = prim;
        int contador = 0;
        while(contador != i){
            it = it -> siguiente;
            contador++;
        }

        Nodo* anterior = it->anterior;
        Nodo* siguiente = it->siguiente;
        anterior ->siguiente = siguiente;
        siguiente ->anterior = anterior;
        delete it;
    }
}

template<typename T>
T &Lista<T>::iesimo(Nat i) {
    Nodo *it = prim;
    int contador = 0;
    while (contador != i) {
        it = it->siguiente;
        contador++;
    }
    return it->valor;
}

template<typename T>
void Lista<T>::mostrar(std::ostream &o) {
  /*  for (int i= 0; i < longitud(); i ++){
        o << iesimo(i) << std::endl;
    }*/
}

template<typename T>
void Lista<T>::copiarNodos(const Lista<T> &lista) {
    if(lista.longitud()==0){
        prim = nullptr;
        ult = nullptr;
    } else {

        for (int  i = 0; i < lista.longitud() ; i++){
            agregarAtras(lista.iesimo(i));
        }

    }

}
