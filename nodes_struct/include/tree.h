#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <map>
#include <vector>
#include "../include/posesID.h"
using namespace std;

class tree{
    private:
        int nodesNum;
        
    public:
        tree(){
            
        }
        tree(char nodes[]){
            nodesNum = 0;
            int i = 0;
            while (nodes[i] != '\0'){
                nodesNum++;
                i++;
            }
        }
        int get_nodesNum();
        ~tree(){}
};

#endif