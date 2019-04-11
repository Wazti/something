

#include "Dinic.h"
#include <list>
#include <iostream>
using namespace std;
Dinic::Dinic(vector<vector<int>> matrix, int V, vector<std::pair<int, int>> pairs)
{
    adject = new vector<Edge>[V];
    this->V = V;
    level = new int[V];
    readFromMatrix(matrix);
    this->pairs = pairs;
}


bool Dinic::bfs(int s, int t)
{
    for (int i = 0 ; i < V ; i++)
        level[i] = -1;

    level[s] = 0;  // Глубина графа

    //Создается очередь, поставлена в очередь исходная вершина
    // и отмечаем исходную вершину как посещенную
    // массив level [] также работает как посещаемый массив.
    list<int> q;
    q.push_back(s);

    vector<Edge>::iterator i ;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (i = adject[u].begin(); i != adject[u].end(); i++)
        {
            Edge &e = *i;
            if (level[e.v] < 0  && e.flow < e.C)
            {
                // Level of current vertex is,
                // level of parent + 1
                level[e.v] = level[u] + 1;

                q.push_back(e.v);
            }
        }
    }

    //
    //Если мы не можем добраться до раковины,
    // возвращаем false, иначе true
    return level[t] >= 0;
}

int Dinic::dfs(int u, int flow, int t, int start[])
{
    if (u == t)
        return flow;

    //Пересекаем все соседние ребра.
    for (  ; start[u] < adject[u].size(); start[u]++)
    {

        Edge &e = adject[u][start[u]];

        if (level[e.v] == level[u]+1 && e.flow < e.C)
        {
            // находим минимальный поток из u в v
            int curr_flow = min(flow, e.C - e.flow);

            int temp_flow = dfs(e.v, curr_flow, t, start);

            // поток больше чем 0
            if (temp_flow > 0)
            {
                // добавить поток к ребру
                e.flow += temp_flow;


                adject[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }

    return 0;
}

int Dinic::dinicMaxflow(int s, int t)
{
    if (s == t)
        return -1;

    int total = 0;  // Initialize result


    while (bfs(s, t) == true)
    {
        // подсчитать количество посещенных ребер
        // from V { 0 to V }
        int *start = new int[V+1];


        while (int flow = dfs(s, INT_MAX, t, start))

            //Добавить поток пути к общему потоку
            total += flow;
    }

    // return maximum flow
    return total;
}
void Dinic::addEdge(int u, int v, int C)
{

    Edge a{v, 0, C, (int)adject[v].size()};


    Edge b{u, 0, 0, (int)adject[u].size()};

    adject[u].push_back(a);
    adject[v].push_back(b); // reverse edge
}
void Dinic::readFromMatrix(vector<vector<int>> matrix)
{
    for (int i=0; i<matrix[0].size(); ++i) {
        for (int j=0; j<matrix.size(); ++j) {
            if (matrix[i][j] !=0) {
                addEdge(i, j, matrix[i][j]);
            }
        }
    }
}

void Dinic::run()
{
    for(int i=0; i<pairs.size(); ++i)
    {
        int res = dinicMaxflow(pairs[i].first, pairs[i].second);
        //cout << "Result of Dinic Algorithm "<<res<<endl;
    }
}