#ifndef NODE_H
#define NODE_H

#include <map>
#include <vector>
#include "../include/posesID.h"

using namespace std;

struct node{
    char ID;
    char parentID;
    int Nchild;
    char *childIDpointer;
    vector<char> childID;
    map<char,posesID> outPose;
};

#endif