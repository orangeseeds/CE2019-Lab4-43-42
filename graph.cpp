#include <iostream>
#include "graph.h"

Graph::Graph()
{
    
    std::cout<<"Is the graph Directed(1) or undirected(0)?"<<std::endl;
    std::cin>>isDirected;
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
    
    std::cout<<"Is the graph Directed(1) or undirected(0)?"<<std::endl;
    std::cin>>isDirected;
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
        if (this->vertices[i]==targetVertex)
        {
            index=i;
            return true;
        }
    }
    return false;
}
void Graph::addVertex(int vertex)
{
    vertices[last_vertex]=vertex;
    last_vertex++;
}
void Graph::addEdge(int ver1, int ver2)

{
    int indexOfVer1, indexOfVer2;
     if(isDirected){
        if(vertex_index_exists(indexOfVer1,ver1)&&vertex_index_exists(indexOfVer2,ver2))
        {
            this->adjMatrix[indexOfVer1][indexOfVer2]=1;
            
        }
    }
    else{
        if(vertex_index_exists(indexOfVer1,ver1)&&vertex_index_exists(indexOfVer2,ver2))
        {
            this->adjMatrix[indexOfVer1][indexOfVer2]=1;
            this->adjMatrix[indexOfVer2][indexOfVer1]=1;
        }
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

void Graph::removeVertex(int vertex)
{
    int indx;
    if(vertex_index_exists(indx,vertex))
    {
        for(int i=0;i<last_vertex;i++)
        {
            this->adjMatrix[i][indx]=0;//removing outgoing edged
            this->adjMatrix[indx][i]=0;//removing incomming edged
        }
        vertices[indx]=0;
        for( int j=indx;j<last_vertex;j++)
        {
            this->vertices[j]=this->vertices[j+1];
        }
        last_vertex--;
    }
}
void Graph::removeEdge(int ver1, int ver2)
{
    int indexOfVer1,indexOfVer2;
     int indexOfVer1,indexOfVer2;
    if(isDirected){
        if(vertex_index_exists(indexOfVer1,ver1)&&vertex_index_exists(indexOfVer2,ver2))
        {
            this->adjMatrix[indexOfVer1][indexOfVer2]=0;
        }
    }
    else{
         if(vertex_index_exists(indexOfVer1,ver1)&&vertex_index_exists(indexOfVer2,ver2))
        {
            this->adjMatrix[indexOfVer1][indexOfVer2]=0;
            this->adjMatrix[indexOfVer2][indexOfVer1]=0;
        }
    }
}
