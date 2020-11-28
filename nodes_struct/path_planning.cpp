#include <iostream>
#include <stdlib.h>
#include "platform.h"
#include <vector>

using namespace std;
void get_ancestorList(platform *,char);
void get_path(platform *,char,char);
vector<char> path_aux1, path_aux2, path;

int main(){
    /******************* Creación de los nodos *******************/
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
    /******************* Creación de los nodos *******************/

    /************ Impresión  de los nodos y sus padres ***********/
    for (size_t i = 0; i < num_nodos; i++){
        cout<<"Nodo "<<nodes[i]->get_ID()<<" - Padre: "<<nodes[i]->get_fatherID()<<endl;
    }
    /************ Impresión  de los nodos y sus padres ***********/

    cout<<endl;
    get_path(nodes[0],'H','E');
    //for (size_t i = 0; i < path.size(); i++){
    //    cout << " -> " << path[i];
    //}
    cout<<"\nCompila"<<endl;
    return 0;
}

void get_ancestorList(platform *nodes,char nodeID){
    nodeID = 2*(nodeID-65);
    char fatherID = nodes[nodeID].get_fatherID();
    if (fatherID != 0){
        path_aux1.push_back(fatherID);
        get_ancestorList(*&nodes,fatherID);
    }
}

void get_path(platform *nodes,char startID, char goalID){
    char ancestor;
    get_ancestorList(*&nodes,startID);              //Se obtienen todos los ancestros del nodo inicial
    for (size_t i = 0; i < path_aux1.size(); i++){
        path_aux2.push_back(path_aux1[i]);
    }
    path_aux1.clear();
    get_ancestorList(*&nodes,goalID);               //Se obtienen todos los ancestros del nodo meta

    /******************* Busqueda del ancestro común más cercano *******************/
    //path_aux1 contiene los ancestros del nodo de destino
    //path_aux2 contiene los ancestros del nodo de origen
    bool contin = true;
    for (size_t i = 0; i < path_aux2.size(); i++){
        for (size_t j = 0; j < path_aux1.size(); j++){
            if ((path_aux1[j] == path_aux2[i]) && contin){
                ancestor = path_aux2[i];
                cout << "\nAncestro común más cercano: "<<ancestor<<endl;
                contin = false;
            }
        }
    }
    

}