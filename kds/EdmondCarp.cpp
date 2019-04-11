#include "EdmondCarp.h"
#include <iostream>
#include <queue>
using namespace std;


EdmondCarp::EdmondCarp(vector<vector<int>> G, vector<pair<int, int>> pairs)
{
    this->G = G;
    this->pairs = pairs;
}
/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(vector<vector<int>>& G, int s, int t, vector<int>& parent)
{
    int size = parent.size();
    // Create a visited array and mark all vertices as not visited
    vector<bool> visited(size,false);
    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
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

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t]);
}

// Returns the maximum flow from s to t in the given graph
int EdmondCarp::edmondCarp(vector<vector<int>> &graph, int s, int t)
{
    int u, v;

    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph

    vector<vector<int>> rGraph; // Residual graph where rGraph[i][j] indicates
    copy(graph.begin(),graph.end(),back_inserter(rGraph));
    // residual capacity of edge from i to j (if there
    // is an edge. If rGraph[i][j] is 0, then there is not)
    vector<int> parent(graph.size());  // This array is filled by BFS and to store path

    int maxflow = 0;  // There is no flow initially

    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int pathflow = 1000000000;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            pathflow = min(pathflow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= pathflow;
            rGraph[v][u] += pathflow;
        }

        // Add path flow to overall flow
        maxflow += pathflow;
    }

    // Return the overall flow
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

