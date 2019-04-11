//
// Created by Weezle on 2019-04-11.
//

#ifndef KDS_DINIC_H
#define KDS_DINIC_H
#include <vector>

using namespace std;
// A structure to represent a edge between
// two vertex
struct Edge
{
    int v ;  // Vertex v (or "to" vertex)
    // of a directed edge u-v. "From"
    // vertex u can be obtained using
    // index in adjacent array.

    int flow ; // flow of data in edge

    int C;    // capacity

    int rev ; // To store index of reverse
    // edge in adjacency list so that
    // we can quickly find it.
};

// Residual Graph
class Dinic {
    int V; // number of vertex
    int *level ; // stores level of a node
    vector< Edge > *adj;
    vector<std::pair<int, int>> allPairs;
public :
    Dinic(vector<vector<int>> matrix, int V, vector<std::pair<int, int>> pairs);
    void runAlgorithm();
    void readFromMatrix(vector<vector<int>> matrix);
    void addEdge(int u, int v, int C);
    bool BFS(int s, int t);
    int dfs(int s, int flow, int t, int ptr[]);
    int dinicMaxflow(int s, int t);
};


#endif //KDS_DINIC_H
