#include "EdmondCarp.h"
#include <iostream>
#include <queue>
using namespace std;


EdmondCarp::EdmondCarp(vector<vector<int>> G, vector<pair<int, int>> pairs)
{
    this->G = G;
    this->pairs = pairs;
}
/*Возвращает true, если есть путь от источника 's' к стоку 't' в
  остаточный граф. Также заполняет parent [] для хранения пути */
bool bfs(vector<vector<int>>& G, int s, int t, vector<int>& parent)
{
    int size = parent.size();
    // Создаем посещенный массив и отмечаем все вершины как не посещенные
    vector<char> visited(size,false);

    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS цикл
    while (!q.empty())
    {
        if (visited[t])
            break;
        int u = q.front();
        q.pop();

        for (int v=0; v<size; v++)
        {
            if (visited[v] || G[u][v]<=0)
            {
                continue;
            }
            q.push(v);
            parent[v] = u;
            visited[v] = true;
        }
    }


    //Если мы достигли стока в BFS, начиная с исходного кода, вернемся
    //
    return (visited[t]);
}

//Возвращает максимальный поток от s до t в данном графе
int EdmondCarp::edmondCarp(vector<vector<int>> &graph, int s, int t)
{
    int u, v;


    vector<vector<int>> rGraph;
    copy(graph.begin(),graph.end(),back_inserter(rGraph));

    vector<int> parent(graph.size());

    int maxflow = 0;


    while (bfs(rGraph, s, t, parent))
    {
        //Находим минимальную остаточную емкость ребер
        // путь заполнен BFS. Или найти максимальный поток
        // через найденный путь.
        int pathflow = 1000000000;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            pathflow = min(pathflow, rGraph[u][v]);
        }

        //обновить остаточные емкости ребер и обратных ребер
        // по пути
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= pathflow;
            rGraph[v][u] += pathflow;
        }

        maxflow += pathflow;
    }

    return maxflow;
}
void EdmondCarp::run()
{
    for (int i=0; i<pairs.size(); ++i)
    {
        int res = edmondCarp(G, pairs[i].first, pairs[i].second);
        //cout <<"Result of EdmondCarp Algorithm " << res << endl;
    }
}

