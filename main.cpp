#include <iostream>
#include "rmlib.h"

using namespace std;

int main(){
    rm_init(0,8888,0,0);
    char name[1000];
    cin >> name;
    int value = 8;
    int size = sizeof(value);

    void* vptr = &name;

    rm_new(name, vptr, size);

}
