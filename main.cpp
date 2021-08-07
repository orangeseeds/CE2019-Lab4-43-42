#include"graph.h"

#include <iostream>
using namespace std;
int main(){
Graph A;
A.addVertex(1);
A.addVertex(2);
A.addVertex(3);
A.addVertex(4);
A.addEdge(2,3);
A.addEdge(2,1);
A.trasverse();
return 0;
}
