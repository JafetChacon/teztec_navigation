#include <iostream>
#include <stdlib.h>
#include "platform.h"

using namespace std;
/*
struct Nodo{
    char ID;                //Identificador del nodo
    string description;     //Descripción del nodo 
    char fatherID;          //ID del padre
    int Nchild;             //Cantidad de hijos que tiene el nodo
    char *childID;          //Arreglo de ID de hijos
    
};
Nodo create_node(char _ID, string _description, char _fatherID, int _Nchild){
    Nodo nodo;
    nodo.ID=_ID;
    nodo.fatherID=_fatherID;
    nodo.description=_description;
}
*/
void createNodes(platform *, int);

int main(){
    //Creación de los nodos
    int num_nodos = 10;
    platform *nodes[num_nodos];    
    for (size_t i = 0; i < num_nodos; i++){
        nodes[i] = new platform(i+65);
    }
    
    cout<<"Compila"<<endl;
}
