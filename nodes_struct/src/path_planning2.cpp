#include <iostream>
#include <stdlib.h>
#include "../include/tree.h"
#include "../include/posesID.h"

using namespace std;

int main(){
    char str[50] = "ABCDE";
    tree arbolito{str};
    char *nodesID;
    cout<<"El arbol tiene "<<arbolito.get_nodesNum()<<" nodos."<<endl;
    cout<<"Sus nodos son: "<<endl;
    arbolito.get_nodesID(nodesID);
    for (size_t i = 0; i < arbolito.get_nodesNum(); i++){
        cout<<nodesID[i]<<endl;
    }
    
    return 0;
}
