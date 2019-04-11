//
// Created by Weezle on 2019-04-11.
//
#include "algorithm"
#include "vector"
#include "limits.h"
#include <queue>
#include "GraphPairs.h"
#include <string>

int dfs(vector<vector<int>>& graph, int index)
{
    bool visited[graph.size()];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(index);
    visited[index] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < graph.size(); v++)
        {
            if (!visited[v] && graph[u][v] != 0)
            {
                q.push(v);
                visited[v] = true;
                if (isTarget(graph, v))
                    return v;
            }
        }
    }
}

vector<std::pair<int, int>> findAllPairs(vector<vector<int>>& graph)
{
    vector<pair<int, int>> result;
    for (int i = 0; i < graph.size(); i++)
        if (isSource(graph, i))
            result.push_back(make_pair(i, dfs(graph, i)));
    return result;
}
bool isSource(vector<vector<int>>& graph, int index)
{
    for (int i = 0; i < graph.size(); i++)
        if (graph[i][index] != 0)
            return false;
    return true;
}

bool isTarget(vector<vector<int>>& graph, int index)
{
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[index][i] != 0)
            return false;
    }
    return true;
}
vector<vector<int>> readMatrix(string filename)
{
    ifstream fin;
    fin.open(filename);
    string row;
    vector<vector<int>> result;
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            vector<int> arr;
            getline(fin, row);
            stringstream stream(row);
            int n;
            while (stream >> n)
                arr.push_back(n);
            if (!arr.empty())
                result.push_back(arr);
        }
    }
    else
    {
        cout << "File broken!";
        exit(1);
    }
    return result;
}
