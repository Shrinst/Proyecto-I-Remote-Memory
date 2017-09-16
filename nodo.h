//
// Created by vinicio on 02/09/17.
//

#ifndef ENLAZADAS_NODO_H
#define ENLAZADAS_NODO_H
#define LISTA_NODO_H
class Nodo{
private:
    char *Llave;
    int Tamano;
    char *Valor;
    Nodo *Siguiente;
public:
    Nodo(char *l, char *v, int t, Nodo *sig=NULL){
        this->Llave = l;
        this->Tamano = t;
        this->Valor = v;
        this->Siguiente = sig;
    }
    friend class Lista;
};
#endif //ENLAZADAS_NODO_H
