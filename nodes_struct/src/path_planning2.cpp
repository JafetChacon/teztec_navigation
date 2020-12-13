#include <iostream>
#include <stdlib.h>
#include "../include/tree.h"
#include "../include/posesID.h"

using namespace std;

int main(){
    char str[50] = "ABCDE";
    tree arbolito{str};
    cout<<"El nodo tiene "<<arbolito.get_nodesNum()<<" nodos."<<endl;
    return 0;
}

