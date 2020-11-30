#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <map>
#include <vector>
#include "../include/posesID.h"
using namespace std;

class platform{
    private:
        posesID parentPose;
        char ID;
        char parentID;
        int Nchild;
        char *childIDpointer;
        vector<char> childID;
        map<char,posesID> outPose;
    public:
        platform(){
            Nchild=0;
            parentPose = {0,0,0};
        }
        platform(char _ID){
            this->ID = _ID;
        }
        void set_ID(char);
        char get_ID();
        void set_parentID(char);
        char get_parentID();
        void set_childrenID(string);
        int get_childrenNum();
        char * get_childrenID();
        void set_outPose(char,posesID);
        void set_outPose(posesID);
        posesID get_outPose(char);
        posesID get_parentPose();
        ~platform(){}
};

#endif