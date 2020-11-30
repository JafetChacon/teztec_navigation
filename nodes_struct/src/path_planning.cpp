#include <iostream>
#include <stdlib.h>
#include "../include/platform.h"
#include <vector>
#include <algorithm>
#include "../include/posesID.h"

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
                                                                                    nodes['A'-65].set_childrenID("BC"); nodes['A'-65].set_outPose('B',{0.0,1.0,0.0}); nodes['A'-65].set_outPose('C',{0.0,2.0,0.0});
    nodes['B'-65].set_parentID('A');    nodes['B'-65].set_outPose({0.0,3.0,0.0});   nodes['B'-65].set_childrenID("DE"); nodes['B'-65].set_outPose('D',{0.0,5.0,0.0}); nodes['B'-65].set_outPose('E',{0.0,6.0,0.0});
    nodes['C'-65].set_parentID('A');    nodes['C'-65].set_outPose({0.0,4.0,0.0});   nodes['C'-65].set_childrenID("FG"); nodes['C'-65].set_outPose('F',{0.0,7.0,0.0}); nodes['C'-65].set_outPose('G',{0.0,8.0,0.0});
    nodes['D'-65].set_parentID('B');    nodes['D'-65].set_outPose({0.0,9.0,0.0});   nodes['D'-65].set_childrenID("HI"); nodes['D'-65].set_outPose('H',{1.0,3.0,0.0}); nodes['D'-65].set_outPose('I',{1.0,4.0,0.0});
    nodes['E'-65].set_parentID('B');    nodes['E'-65].set_outPose({1.0,0.0,0.0});   nodes['E'-65].set_childrenID("J");  nodes['E'-65].set_outPose('J',{1.0,5.0,0.0});
    nodes['F'-65].set_parentID('C');    nodes['F'-65].set_outPose({1.0,1.0,0.0});
    nodes['G'-65].set_parentID('C');    nodes['G'-65].set_outPose({1.0,2.0,0.0});   nodes['G'-65].set_childrenID("K");  nodes['G'-65].set_outPose('K',{1.0,6.0,0.0});
    nodes['H'-65].set_parentID('D');    nodes['H'-65].set_outPose({1.0,7.0,0.0});
    nodes['I'-65].set_parentID('D');    nodes['I'-65].set_outPose({1.0,8.0,0.0});
    nodes['J'-65].set_parentID('E');    nodes['J'-65].set_outPose({1.0,9.0,0.0});
    nodes['K'-65].set_parentID('G');    nodes['K'-65].set_outPose({2.0,0.0,0.0});

    for (size_t i = 0; i < num_nodos; i++){
        cout<<'\t'<<char(i+65)<<" [parent: "<<nodes[i].get_parentID()<<"]. ("<<nodes[i].get_childrenNum()<< " children)";
        if(nodes[i].get_childrenNum()>0) cout<<"\tThere are: ";
        childList = nodes[i].get_childrenID();
        for (size_t j = 0; j < nodes[i].get_childrenNum(); j++){
            cout<<*(childList + j)<<" ";
        }
        cout<<endl;
    }
    /*#################### Creación de los nodos ####################*/
    startNode = 'K';
    goalNode = 'H';
    get_path(nodes,startNode,goalNode);
    cout<<"Camino para llegar de <<"<<startNode<<">> a <<"<<goalNode<<">>:"<<endl;
    for (size_t i = 0; i < path.size(); i++) cout << " -> " << path[i];
    cout<<endl;

    /*########################## Trazado de coordenadas ##########################*/
    
    posesID aux1,aux2;
    cout<<"La serie de coordenadas a seguir son:"<<endl;
    for (size_t j = 1; j < path.size(); j++){
        aux1 = nodes[path[j-1]-65].get_outPose(path[j]);
        cout<<'(';
        for (size_t i = 0; i < 3; i++){
            cout<<aux1.pose[i]; if(i<2) cout<<',';
        }
        cout<<')'<<" -> ";
        aux2 = nodes[path[j]-65].get_outPose(path[j-1]);
        cout<<'(';
        for (size_t i = 0; i < 3; i++){
            cout<<aux2.pose[i]; if(i<2) cout<<',';
        }
        cout<<')'<<endl;
    }
    
    
    return 0;
}

void get_ancestorList(platform nodes[],char nodeID){
    nodeID = (nodeID-65);
    char parentID = nodes[nodeID].get_parentID();
    if (parentID){
        path_aux1.push_back(parentID);
        get_ancestorList(nodes,parentID);
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
