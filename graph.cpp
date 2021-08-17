#include <iostream>
#include "graph.h"

Graph::Graph()//mohit
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

Graph::Graph(int size)//mohit
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

bool Graph::isEmpty()//mohit
{
    if(last_vertex==0)
        {return true;}
    return false;
}



bool Graph::vertex_index_exists(int &index, int targetVertex)//mohit
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

void Graph::addVertex(int vertex)//mohit
{
    vertices[last_vertex]=vertex;
    last_vertex++;
}

void Graph::addEdge(int ver1, int ver2)//mohit
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


void Graph::trasverse()//mohit
{
    for (int i=0; i<last_vertex;i++)
    {
        std::cout<<vertices[i]<<":";
        for (int j=0; j<last_vertex;j++)
        {
            std::cout<<adjMatrix[i][j]<<" ";

        }
        std::cout<<"\n";
    }
}

void Graph::removeVertex(int vertex)//mohit
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

void Graph::removeEdge(int ver1, int ver2)//mohit
{
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

int Graph::numberOfEdges()//mohit
{
    // for directed
    if (this->isEmpty())
    {
        return 0;
    }
    
    int edges_count = 0;
    for (int i = 0; i < last_vertex; i++)
    {
        for (int j = 0; j < last_vertex; j++)
        {
            if (this->adjMatrix[i][j] == 1)
            {
                edges_count ++;
            }      
        }
    }

    return this->isDirected ? edges_count : edges_count/2;
}

int Graph::numberOfVertices()//mohit
{
    return last_vertex;
}

int Graph::indegree(int vertex) //mohit
{
    int indegree = 0, index;

    if (!vertex_index_exists(index, vertex))
    {
        std::cout << "The given vertex doesn't exist..." << std::endl;
        return 0;
    }
    

    for (int i = 0; i < last_vertex; i++)
    {
        if (this->adjMatrix[i][index] == 1)
        {
            indegree++;
        }
    }

    return indegree;
    
}

int Graph::outdegree(int vertex) //mohit
{
    int outdegree = 0, index;

    if (!vertex_index_exists(index, vertex))
    {
        std::cout << "The given vertex doesn't exist..." << std::endl;
        return 0;
    }

    for (int i = 0; i < last_vertex; i++)
    {
        if (this->adjMatrix[index][i] == 1)
        {
            outdegree++;
        }
    }
    return outdegree;
}

std::vector<int> Graph::neighbours(int vertex) //mohit
{
    int index;
    std::vector<int> neighbours;

    if (!vertex_index_exists(index, vertex))
    {
        std::cout << "The given vertex doesn't exist..." << std::endl;
        return neighbours;
    }

    for (int i = 0; i < last_vertex; i++)
    {
        for (int j = 0; j < last_vertex; j++)
        {
            if ( i == index && this->adjMatrix[i][j] == 1)
            {
                neighbours.push_back(this->vertices[j]);
            }
            else if (j == index && this->adjMatrix[i][j] == 1)
            {
                neighbours.push_back(this->vertices[i]);
            }
        }
    }

    return neighbours;
}

bool Graph::neighbours(int ver1, int ver2){
    int index_v1, index_v2;

    if (! (vertex_index_exists(index_v1, ver1) || vertex_index_exists(index_v2, ver2)))
    {
        std::cout << "One of the given vertices doesn't exist" << std::endl;
        return false;
    }
    else
    {
        for (auto neighbour : this->neighbours(ver1))
        {
            if (neighbour == ver2)
            {
                return true;
            }
        }

        return false;
        

    }
}
