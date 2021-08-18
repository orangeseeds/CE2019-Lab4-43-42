#include"graph.h"
#include <ctime>
#include <iostream>
#include <map>
using namespace std;

Graph generateGraph()
{
    std::vector<int> vertices;
    int vertices_count, vertex_value, possible_edges, possible_runs, vertex_1, vertex_2;
    unsigned seed = time(0);
    srand(seed);

    Graph R;

    vertices_count = rand() % (R.size + 1);
    for (int i = 0; i < vertices_count ; i++)
    {
        vertex_value = rand() % (100 + 1);
        vertices.push_back(vertex_value);
        R.addVertex(vertex_value);
    }

    possible_edges = vertices_count * (vertices_count - 1);
    possible_edges = R.isDirected ? possible_edges : possible_edges/2;

    possible_runs = rand() % (possible_edges + 1);
    // std::cout << possible_runs << std::endl;

    if (!R.isDirected)
    {
        map<int, int> combinations;
        for (int j = 0; j < possible_runs; j++)
        {
            vertex_1 = vertices[rand() % (vertices_count)];
            vertex_2 = vertices[rand() % (vertices_count)];

            if (combinations[vertex_1] == vertex_2 || vertex_2 == vertex_1){
                continue;
            }


            combinations.insert(pair<int, int>(vertex_1, vertex_2));
            combinations.insert(pair<int, int>(vertex_2, vertex_1));
            R.addEdge(vertex_1, vertex_2);
        }
    }
    else{
        map<int, int> combinations;
        for (int j = 0; j < possible_runs; j++)
        {
            vertex_1 = vertices[rand() % (vertices_count)];
            vertex_2 = vertices[rand() % (vertices_count)];

            if ((combinations[vertex_1] == vertex_2 && combinations[vertex_2] == vertex_1) || vertex_2 == vertex_1)
            {
                continue;
            }

            combinations.insert(pair<int, int>(vertex_1, vertex_2));
            R.addEdge(vertex_1, vertex_2);
        }
    }
    
    std::cout << "Traversal" << std::endl;
    R.trasverse();
    std::cout << std::endl;

    std::cout << "Number of Vertices: "<< R.numberOfVertices() << std::endl;
    std::cout << "Number of Edges: "<< R.numberOfEdges() << std::endl;
    vertex_2 = vertices[rand() % (vertices_count)];
    vertex_1 = vertices[rand() % (vertices_count)];
    std::cout << "Indegree of a random vertex: " << vertex_1 << " is " << R.indegree(vertex_1) << std::endl;
    std::cout << "Outdegree of a random vertex: " << vertex_2 << " is " << R.outdegree(vertex_2) << std::endl;
    return R;
}

int main(){
// A.addVertex(1);
// A.addVertex(2);
// A.addVertex(3);
// A.addVertex(4);
// A.addEdge(2,3);
// A.addEdge(2,1);
// A.trasverse();

// std::cout << A.numberOfEdges() << std::endl;
// std::cout << A.numberOfVertices() << std::endl;
// std::cout << A.indegree(3) << std::endl;
// std::cout << A.outdegree(2) << std::endl;
// std::cout << A.neighbours(2,1) << std::endl;

generateGraph();
return 0;
}
