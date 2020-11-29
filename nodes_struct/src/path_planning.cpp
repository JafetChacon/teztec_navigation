#include <iostream>
#include <stdlib.h>
#include "../include/platform.h"
#include <vector>
#include <algorithm>

using namespace std;
void get_ancestorList(platform [],char);
void get_path(platform [],char,char);
vector<char> path_aux1, path_aux2, path;

int main(){
    char *childList;
    char startNode,goalNode; 
    /*#################### Creación de los nodos ####################*/
    int num_nodos = 11;
    platform nodes[num_nodos];
    for (size_t i = 0; i < num_nodos; i++){
        nodes[i].set_ID(i+65);
    }
                                        nodes['A'-65].set_childrenID("BC");
    nodes['B'-65].set_fatherID('A');    nodes['B'-65].set_childrenID("DE");
    nodes['C'-65].set_fatherID('A');    nodes['C'-65].set_childrenID("FG");
    nodes['D'-65].set_fatherID('B');    nodes['D'-65].set_childrenID("HI");
    nodes['E'-65].set_fatherID('B');    nodes['E'-65].set_childrenID("J");
    nodes['F'-65].set_fatherID('C');
    nodes['G'-65].set_fatherID('C');    nodes['G'-65].set_childrenID("K");
    nodes['H'-65].set_fatherID('D');
    nodes['I'-65].set_fatherID('D');
    nodes['J'-65].set_fatherID('E');
    nodes['K'-65].set_fatherID('G');

    for (size_t i = 0; i < num_nodos; i++){
        cout<<'\t'<<char(i+65)<<" [parent: "<<nodes[i].get_fatherID()<<"]. ("<<nodes[i].get_childrenNum()<< " children)";
        if(nodes[i].get_childrenNum()>0) cout<<"\tThere are: ";
        childList = nodes[i].get_childrenID();
        for (size_t j = 0; j < nodes[i].get_childrenNum(); j++){
            cout<<*(childList + j)<<" ";
        }
        cout<<endl;
    }
    /*#################### Creación de los nodos ####################*/
    
    startNode = 'C';
    goalNode = 'K';
    get_path(nodes,startNode,goalNode);
    cout<<"Camino para llegar de <<"<<startNode<<">> a <<"<<goalNode<<">>:"<<endl;
    for (size_t i = 0; i < path.size(); i++) cout << " -> " << path[i];
    cout<<endl;
    return 0;
}

void get_ancestorList(platform nodes[],char nodeID){
    nodeID = (nodeID-65);
    char fatherID = nodes[nodeID].get_fatherID();
    if (fatherID){
        path_aux1.push_back(fatherID);
        get_ancestorList(nodes,fatherID);
    }
}

void get_path(platform nodes[],char startID, char goalID){
    char ancestor;
    path_aux2.push_back(startID);
    get_ancestorList(nodes,startID);              //Se obtienen todos los ancestros del nodo inicial
    for (size_t i = 0; i < path_aux1.size(); i++) path_aux2.push_back(path_aux1[i]);
    path_aux1.clear();
    path_aux2.push_back(goalID);
    get_ancestorList(nodes,goalID);               //Se obtienen todos los ancestros del nodo meta
    //path_aux1 contiene los ancestros del nodo de destino
    //path_aux2 contiene los ancestros del nodo de origen
    
    /*################### Busqueda del ancestro común más cercano ###################*/
    path.clear();
    bool found = false;
    for (size_t i = 0; i < path_aux2.size(); i++){
        if(!found) path.push_back(path_aux2[i]);    //Ingreso de los primeros nodos al path
        for(size_t j = 0; j < path_aux1.size(); j++){
            if ((path_aux1[j] == path_aux2[i]) && !found){
                ancestor = path_aux2[i];
                cout << "\nAncestro común más cercano: "<<ancestor<<endl;
                found = true;
            }
        }
    }
    /*#################### Listado de ID de los nodos del camino ####################*/
    reverse(path_aux1.begin(), path_aux1.end());    // Inversión de la lista a orden descendente
    path_aux1.push_back(goalID);                    // Agregar el nodo meta a la lista
    found = false;
    for(size_t i = 0; i < path_aux1.size() ; i++){  // Iteración y seleccion de los nodos post - ancestro común
        if(found) path.push_back(path_aux1[i]);
        if(path_aux1[i]==ancestor) found = true;
    }   
}
