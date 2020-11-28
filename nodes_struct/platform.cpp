#include "platform.h"
void platform::set_ID(char _ID){
    ID = _ID;
}
char platform::get_ID(){
    return ID;
}
void platform::set_fatherID(char _fatherID){
    fatherID = _fatherID;
}
char platform::get_fatherID(){
    return fatherID;
}
void platform::set_childrenID(int argc, char *argv[]){
    Nchild = argc - 1;
    childID = new char[Nchild];
}