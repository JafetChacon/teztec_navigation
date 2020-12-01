#include <iostream>
#include <stdlib.h>
#include "../include/platform.h"
#include <vector>
#include <algorithm>
#include "../include/posesID.h"

using namespace std;
void get_ancestorList(platform [],char);
void get_path(platform [],char,char);
void get_pathCoordenades(platform []);
vector<char> path_aux1, path_aux2, path;
vector<posesID> pathCoordenades;

int main(){
    int num_nodos = 6;
    platform nodes[num_nodos];
    char *childList;
    char startNode,goalNode;
    startNode = 'D';
    goalNode = 'F';
    /*#################### Creación de los nodos ####################*/
    for (size_t i = 0; i < num_nodos; i++){nodes[i].set_ID(i+65);}
                                                                                    nodes['A'-65].set_childrenID("BC"); nodes['A'-65].set_outPose('B',{0.0,0.0,1.0}); nodes['A'-65].set_outPose('C',{0.0,0.0,2.0});
    nodes['B'-65].set_parentID('A');    nodes['B'-65].set_outPose({0.0,0.0,3.0});   nodes['B'-65].set_childrenID("D");  nodes['B'-65].set_outPose('D',{0.0,0.0,5.0});
    nodes['C'-65].set_parentID('A');    nodes['C'-65].set_outPose({0.0,0.0,4.0});   nodes['C'-65].set_childrenID("EF"); nodes['C'-65].set_outPose('E',{0.0,0.0,6.0}); nodes['C'-65].set_outPose('F',{0.0,0.0,7.0});
    nodes['D'-65].set_parentID('B');    nodes['D'-65].set_outPose({0.0,0.0,8.0});
    nodes['E'-65].set_parentID('C');    nodes['E'-65].set_outPose({0.0,0.0,9.0});
    nodes['F'-65].set_parentID('C');    nodes['F'-65].set_outPose({0.0,1.0,0.0});
    
    for (size_t i = 0; i < num_nodos; i++){
        cout<<'\t'<<char(i+65)<<" [parent: "<<nodes[i].get_parentID()<<"]. ("<<nodes[i].get_childrenNum()<< " children)";
        if(nodes[i].get_childrenNum()>0) cout<<"\tThere are: ";
        childList = nodes[i].get_childrenID();
        for (size_t j = 0; j < nodes[i].get_childrenNum(); j++){cout<<*(childList + j)<<" ";}
        cout<<endl;
    }
    
    /*########################### Creación de los nodos ###########################*/
    
    get_path(nodes,startNode,goalNode);
    cout<<"\nCamino para llegar de <<"<<startNode<<">> a <<"<<goalNode<<">>:"<<endl;
    for (size_t i = 0; i < path.size(); i++) cout << " -> " << path[i];
    cout<<endl;

    /*########################## Trazado de coordenadas ##########################*/
    cout<<"La serie de coordenadas a seguir son:"<<endl;
    get_pathCoordenades(nodes);
    for (size_t i = 0; i < pathCoordenades.size(); i++){    /* Show path coordenades*/
        cout<<'(';
        for (size_t j = 0; j < 3; j++){cout<<pathCoordenades[i].pose[j]; if(j<2) cout<<',';}
        cout<<')'; if(i<pathCoordenades.size()-1) cout<<" -> ";
    }
    cout<<endl;
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

void get_pathCoordenades(platform node[]){
    for (size_t j = 1; j < path.size(); j++){
        pathCoordenades.push_back(node[path[j-1]-65].get_outPose(path[j]));
        pathCoordenades.push_back(node[path[j]-65].get_outPose(path[j-1]));
    }
}
