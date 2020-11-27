#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
using namespace std;

class platform{
    private:
        char ID;
        char father_ID;
        int Nchild;
        int *childID;
    public:
        platform(char _ID, int _Nchild, char _father_ID){
            this->ID = _ID;
            this->Nchild = _Nchild;
            this->father_ID = _father_ID;
        }
        platform(char _ID){
            this->ID = _ID;
        }
        char get_ID();
        ~platform(){}
};

#endif