#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
using namespace std;

class platform{
    private:
        float fatherPose[3];
        char ID;
        char fatherID;
        int Nchild;
        char *childID;
    public:
        platform(){
            Nchild=0;
        }
        platform(char _ID){
            this->ID = _ID;
        }
        void set_ID(char);
        char get_ID();
        void set_fatherID(char);
        char get_fatherID();
        void set_childrenID(string);
        int get_childrenNum();
        char * get_childrenID();

        ~platform(){}
};

#endif