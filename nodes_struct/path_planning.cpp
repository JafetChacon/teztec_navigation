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
void print_fatherIDlist(platform *,char){

int main(){
    //Creación de los nodos
    int num_nodos = 10;
    platform *nodes[num_nodos];
    for (size_t i = 0; i < num_nodos; i++){
        nodes[i] = new platform(i+65);
    }
    nodes['B'-65]->set_fatherID('A');
    nodes['C'-65]->set_fatherID('A');
    nodes['D'-65]->set_fatherID('B');
    nodes['E'-65]->set_fatherID('B');
    nodes['F'-65]->set_fatherID('C');
    nodes['G'-65]->set_fatherID('C');
    nodes['H'-65]->set_fatherID('D');
    nodes['I'-65]->set_fatherID('D');
    nodes['J'-65]->set_fatherID('G');

    for (size_t i = 0; i < num_nodos; i++){
        cout<<"Nodo "<<nodes[i]->get_ID()<<" - Padre: "<<nodes[i]->get_fatherID()<<endl;
    }
    cout<<endl;
    print_fatherIDlist(nodes[0],'H');
    cout<<"Compila"<<endl;
    return 0;
}

void print_fatherIDlist(platform *nodes,char nodeID){
    nodeID = 2*(nodeID-65);
    char fatherID = nodes[nodeID].get_fatherID();
    if (fatherID != 0){
        cout << fatherID << " - ";
        print_fatherIDlist(*&nodes,fatherID);
    }else{
        cout<<"."<<endl;
    }
}