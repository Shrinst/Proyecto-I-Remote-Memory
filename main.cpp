#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "rmlib.h"
#include "rmRef_H.h"


using namespace std;

/**
*@brief Metodo principal de pruebas
*/
int main(){

    rm_init(0,8875,0,0);

    char *key;
    key = "Cantidad";
    char *value;
    value = "78";

    void *vptr = value;
    rm_new(key, vptr, sizeof(value));

    key = "ColorCasa";
    value = "Verde";
    vptr = value;
    rm_new(key, vptr, sizeof(value));

    key = "Puntos";
    value = "28573";
    vptr = value;
    rm_new(key, vptr, sizeof(value));

    key = "Nombre";
    value = "Vinicio";
    vptr = value;
    rm_new(key, vptr, sizeof(value));

    key = "Apellido";
    value = "Monge";
    vptr = value;
    rm_new(key, vptr, sizeof(value));

    key = "Edades";
    value = "20";
    vptr = value;
    rm_new(key, vptr, sizeof(value));

    //rmRef_H *handler = new rmRef_H(*key, *value);


    rm_delete(handler);

}
