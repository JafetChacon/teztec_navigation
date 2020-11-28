#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
using namespace std;

class platform{
    private:
        char ID;
        char fatherID;
        int Nchild;
        char *childID;
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
        void set_childrenID(int argc, char *argv[]);

        ~platform(){}
};

#endif