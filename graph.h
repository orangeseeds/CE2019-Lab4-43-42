class Graph
{
    int last_vertex=0;
    int size=6;
    bool isDirected;
    public:
    Graph();
    Graph(int size);
    bool isEmpty();
    void addVertex(int vertex);
    void addEdge(int ver1, int ver2);
    bool vertex_index_exists(int &index, int targetVertex);
    int vertices[16];
    int adjMatrix[16][16];
    void removeVertex(int vertex);
    void removeEdge(int ver1, int ver2);
    int numberOfEdges();
    int numberOfVertices();
    int indegree(int vertex);
    int outdegree(int vertex);
    void neighbours(int vertex);
    bool neighbours(int ver1, int ver2);
    void trasverse();
};
