//
// Created by Weezle on 2019-04-9.
//

#ifndef KDS_DINIC_H
#define KDS_DINIC_H
#include <vector>

using namespace std;
//Структура ребра между двумя вершинами
struct Edge
{
    int v ;  // вершина/Vertex v

    int flow ; // поток в ребре

    int C;    // вместимость

    int rev ; // To store index of reverse
    // edge in adjacency list so that
    // we can quickly find it.
};

// Остаточный граф
class Dinic {
    int V; // количество вершин
    int *level ; // уровни узла
    vector<Edge> *adject;
    vector<std::pair<int, int>> pairs;
public :
    Dinic(vector<vector<int>> matrix, int V, vector<std::pair<int, int>> pairs);
    void run();
    void readFromMatrix(vector<vector<int>> matrix);
    void addEdge(int u, int v, int C);
    bool bfs(int s, int t);
    int dfs(int s, int flow, int t, int ptr[]);
    int dinicMaxflow(int s, int t);
};


#endif //KDS_DINIC_H
