//
// Created by Weezle on 2019-04-10.
//

#include "FordFulkerson.h"
#include <limits.h>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include "FordFulkerson.h"

using namespace std;

FordFulkerson::FordFulkerson(vector<vector<int>> graph, vector<pair<int,int>> pairs)
{
    G = graph;
    this->pairs = pairs;
}

int FordFulkerson::fordFulkerson(vector<vector<int>> &G, int s, int t)
{
    for (int flow = 0;;)
    {
        vector<char> visitedArr(G.size(), false);
        int df = findPath(G,visitedArr,s,t,INT_MAX);
        if (df == 0)
            return flow;
        flow += df;
    }
}
/// DFS
/// \param G graph
/// \param visitedArr visited points
/// \param u
/// \param t
/// \param f поток
/// \return
int FordFulkerson::findPath(vector<vector<int>> &G, vector<char> &visitedArr, int u, int t, int f)
{
    if (u == t)
        return f;
    visitedArr[u] = true;
    for (int v = 0; v < visitedArr.size(); v++)
    {
        if (!visitedArr[v] && G[u][v] > 0)
        {
            int df = findPath(G, visitedArr, v, t, min(f, G[u][v]));
            if (df > 0) {
                G[u][v] -= df;
                G[v][u] += df;
                return df;
            }
        }
    }
    return 0;
}

void FordFulkerson::run()
{
    for(int i=0; i<pairs.size(); ++i)

    {
        int res = fordFulkerson(G, pairs[i].first, pairs[i].second);

    }
}