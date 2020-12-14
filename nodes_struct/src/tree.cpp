#include <map>
#include <vector>
#include "../include/tree.h"
#include "../include/posesID.h"

#include <iostream>     //Provisional para depuración

int tree::get_nodesNum(){
    return nodesNum;
}
void tree::get_nodesID(char *&_nodesID){
    _nodesID = new char[nodesNum];
    for (size_t i = 0; i < nodesNum; i++){
        _nodesID[i] = nodes[i].ID;
    }
    return;
}
