#ifndef TREE_H
#define TREE_H

#include <map>
#include "../include/posesID.h"     //Estructura para guardar las poses de cada ID
#include "../include/node.h"        //Estructura para guardar los datos de cada nodo
using namespace std;

class tree{
    private:
        int nodesNum;
        node *nodes;
        char rootID;
    public:
        tree(){
            
        }
        tree(char _nodes[]){
            nodesNum = 0;
            while (_nodes[nodesNum] != '\0'){
                nodesNum++;
            }
            nodes = new node[nodesNum];
            for (size_t i = 0; i < nodesNum; i++){
                nodes[i].ID = _nodes[i];
            }
            
        }
        int get_nodesNum();
        void get_nodesID(char *&);
        void set_nodeParentID(char,char);
        void set_rootID(char);
        ~tree(){}
};

#endif