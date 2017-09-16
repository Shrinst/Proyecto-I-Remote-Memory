#include <iostream>
#include "lista.h"
int main() {
    Lista list;
    char *key = "CASA";
    list.Insertar(key,"rojo", sizeof(key));
    list.Mostrar();
}