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
void platform::set_childrenID(char argv[]){
    int i=0;
    Nchild=0;
    while (argv[i]!='\0'){
        Nchild++;
        i++;
    }
    childID = new char[Nchild];
    for (i = 0; i < Nchild; i++){
        childID[i]=argv[i];
    }
}
int platform::get_childrenNum(){
    return Nchild;
}
char * platform::get_childrenID(){
    return childID;
}