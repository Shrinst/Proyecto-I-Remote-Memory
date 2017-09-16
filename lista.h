//
// Created by vinicio on 02/09/17.
//

#ifndef ENLAZADAS_LISTA_H
#define ENLAZADAS_LISTA_H

#include "nodo.h"
using namespace std;
class Lista{

    private:
        Nodo *Primero;
        Nodo *Actual;
        bool ListaVacia(){
            return (this->Primero == NULL);
        }

    public:
        Lista(){
            this->Primero = NULL;
            this->Actual = NULL;
        }

    void Insertar(char *l, char *v, int t){
        Nodo *nuevo = new Nodo(l, v, t);
        if(ListaVacia()){
            this->Primero = nuevo;
        }else{
            this->Actual->Siguiente = nuevo;
        }
        this->Actual = nuevo;
    }

    void Mostrar(){
        Nodo *tmp = this->Primero;
        while(tmp){
            cout << tmp->Tamano << "--> ";
            tmp = tmp->Siguiente;
        }
        cout << "NULL\n";
    }
};
#endif //ENLAZADAS_LISTA_H
