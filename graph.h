#include <vector>

class Graph
{
    int last_vertex=0;

    public:
    bool isDirected;
    int size=16;
    // DONE---
        Graph();
        Graph(int size);
        bool isEmpty();
        bool vertex_index_exists(int &index, int targetVertex);
        void addVertex(int vertex);
        void addEdge(int ver1, int ver2);
        void trasverse();
        void removeVertex(int vertex);
        void removeEdge(int ver1, int ver2);

        int vertices[16];
        int adjMatrix[16][16];

    // REMAINING -- DONE
        int numberOfEdges();
        int numberOfVertices();
        int indegree(int vertex);
        int outdegree(int vertex);
        std::vector<int> neighbours(int vertex);
        bool neighbours(int ver1, int ver2);
};
