#include "platform.h"
#include <cstring>

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
void platform::set_childrenID(string argv){
    Nchild = argv.length();
    childID = new char[Nchild];
    strcpy(childID, argv.c_str());
}
int platform::get_childrenNum(){
    return Nchild;
}
char * platform::get_childrenID(){
    return childID;
}