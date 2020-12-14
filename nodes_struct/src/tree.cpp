#include <map>
#include "../include/tree.h"
#include "../include/posesID.h"

#include <iostream>     //Provisional para depuración

int tree::get_nodesNum(){
    return nodesNum;
}
void tree::get_nodesID(char *&_nodesID){
    try{
        _nodesID = new char[nodesNum];              //Esto probablemente traiga problemas después
        for (size_t i = 0; i < nodesNum; i++){
            _nodesID[i] = nodes[i].ID;
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    return;
}
void tree::set_nodeParentID(char son, char parent){
    try{
        int sonFound = 0;
        int parentFound = 0;
        for (size_t j = 0; j < nodesNum; j++){
            if (nodes[j].ID == parent) parentFound = 1;
        }
        for (size_t i = 0; i < nodesNum; i++){
            if(nodes[i].ID == son){
                sonFound = 1;
                if(parentFound) nodes[i].parentID = parent;
            }
        }
        if(!sonFound) throw 1;
        if(!parentFound) throw 2;
    }
    catch(int e){
        if (e == 1) std::cerr << "[Exception] Son ("<< son <<") not found!\n";
        if (e == 2) std::cerr << "[Exception] Parent ("<< parent <<") not found!\n";
    }
}
void tree::set_rootID(char _rootID){
    try{
        int rootFound = 0;
        for (size_t j = 0; j < nodesNum; j++){
            if (nodes[j].ID == _rootID) rootFound = 1;
        }
        if(rootFound) rootID = _rootID;
        if(!rootFound) throw 1;
    }
    catch(int e){
        std::cerr << "[Exception] Root ("<< _rootID <<") not found!" << '\n';
    }
}
