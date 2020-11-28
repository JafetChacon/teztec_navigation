#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
using namespace std;

class platform{
    private:
        char ID;
        char fatherID;
        int Nchild;
        int *childID;
    public:
        platform(){

        }
        platform(char _ID, int _Nchild, char _fatherID){
            this->ID = _ID;
            this->Nchild = _Nchild;
            this->fatherID = _fatherID;
        }
        platform(char _ID){
            this->ID = _ID;
        }
        void set_ID(char);
        char get_ID();
        void set_fatherID(char);
        char get_fatherID();

        ~platform(){}
};

#endif