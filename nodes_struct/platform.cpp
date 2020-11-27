#include "platform.h"

char platform::get_ID(){
    return ID;
}
void platform::set_fatherID(char _fatherID){
    fatherID = _fatherID;
}
char platform::get_fatherID(){
    return fatherID;
}