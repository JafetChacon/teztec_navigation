#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include "../include/platform.h"
#include "../include/posesID.h"

void platform::set_ID(char _ID){
    ID = _ID;
}
char platform::get_ID(){
    return ID;
}
void platform::set_parentID(char _parentID){
    parentID = _parentID;
    outPose.insert(pair<char,posesID>(_parentID,{0.0,0.0,0.0,0.0,0.0,0.0}));
}
char platform::get_parentID(){
    return parentID;
}
void platform::set_childrenID(string argv){
    Nchild = argv.length();
    childIDpointer = new char[Nchild];
    strcpy(childIDpointer, argv.c_str());
    for (size_t i = 0; i < Nchild; i++){
        childID.push_back(childIDpointer[i]);
        outPose.insert(pair<char,posesID>(childIDpointer[i],{0.0,0.0,0.0,0.0,0.0,0.0}));
    }
}
int platform::get_childrenNum(){
    return Nchild;
}
char * platform::get_childrenID(){
    return childIDpointer;
}
void platform::set_outPose(char _childID,posesID pose){
    outPose[_childID] = pose;
}
void platform::set_outPose(posesID pose){
    outPose[parentID] = pose;
}
posesID platform::get_outPose(char _ID){
    if (count(childID.begin(),childID.end(),_ID) || _ID==parentID){
        return outPose[_ID];
    }
    else return {0.0,0.0,0.0,0.0,0.0,0.0};
}
posesID platform::get_parentPose(){
    return outPose[parentID];
}