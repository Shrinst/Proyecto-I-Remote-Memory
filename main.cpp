#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "rmlib.h"


using namespace std;
void newint(char *key, int *value){

    void *vptr = value;
    //int *x = (int *)vptr;
    //std::cout << *x << "\n";
    //rm_new(&key, vptr, sizeof(value));
}
int main(){

    rm_init(0,8879,0,0);

    char *key;
    key = "Color";
    char *value;
    value = "Verde";
    //void* vptr = &cant;

    //rm_new(key, vptr, 0);

    //newint(&key, &cant);

    void *vptr = value;
    rm_new(key, vptr, sizeof(value));

    key = "Color1";
    value = "Verde1";
    vptr = value;
    rm_new(key, vptr, sizeof(value));

    key = "Color2";
    value = "Verde2";
    vptr = value;
    rm_new(key, vptr, sizeof(value));

    key = "Color3";
    value = "Verde3";
    vptr = value;
    rm_new(key, vptr, sizeof(value));

    key = "Color4";
    value = "Verde4";
    vptr = value;
    rm_new(key, vptr, sizeof(value));

    key = "Color5";
    value = "Verde5";
    vptr = value;
    rm_new(key, vptr, sizeof(value));

    key = "Color3";
    rm_get(key);

    //void* vptr = key;
    //char *x = (char *)vptr;
    //std::cout << *x << "\n";

    //string cad1="Esta es mi primer cadena";
    //int pos = cad1.find("mi");
    //string cad4 = cad1.substr (pos);
    //std::cout << cad4 << "\n";
}
