#include <iostream>
#include "graph.h"

Graph::Graph()
{
for(int i=0;i<size;i++)
{
    for(int j=0;j<size;j++)
    {
        adjMatrix[i][j]=0;
    }
}

}
Graph::Graph(int size)
{
    for(int i=0;i<size;i++)
{
    for(int j=0;j<size;j++)
    {
        adjMatrix[i][j]=0;
    }
}
}

bool Graph::isEmpty()
{
    if(last_vertex==0)
        {return true;}
    return false;
}



bool Graph::vertex_index_exists(int &index, int targetVertex)
{
    for(int i=0;i<=last_vertex;i++)
    {
        if (this->vertices[i]=targetVertex)
        {
            index=i;
            return true;
        }
    }
    return false;
}
void Graph::addVertex(int vertex)
{
    vertices[last_vertex]==vertex;
    last_vertex++;
}
void Graph::addEdge(int ver1, int ver2)
{
    int indexOfVer1, indexOfVer2;
    if(vertex_index_exists(indexOfVer1,ver1)&&vertex_index_exists(indexOfVer2,ver2))
    {
        this->adjMatrix[indexOfVer1][indexOfVer2]=1;
    }
}

void Graph::trasverse()
{
    for (int i=0; i<last_vertex;i++)
    {
        std::cout<<i<<":";
        for (int j=0; j<last_vertex;j++)
        {
            std::cout<<adjMatrix[i][j]<<" ";

        }
        std::cout<<"\n";
    }
}
