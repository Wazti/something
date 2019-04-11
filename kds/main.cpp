#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include "vector"
#include <ctime>
#include "time.h"
#include "FordFulkerson.h"
#include "EdmondCarp.h"
#include "Dinic.h"
#include "GraphPairs.h"
using namespace std;

double alghorithms(int i, vector<vector<int>> graph, vector<pair<int,int>> pairs);
int main()
{
    ofstream fout;
    fout.open("output.txt");
    for (int k = 0; k< 6; k++)
    {
        cout<<inputfiles[k]<<endl;
        vector<vector<int>> graph = readMatrix(inputfiles[k]);
        //cout << "Size of graph " << graph.size() << endl;
        vector<pair<int, int>> pairs = findAllPairs(graph);
        double res[3] = {0};
        for (int j = 0; j < 10; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                res[i] += alghorithms(i, graph, pairs);
            }
        }
        fout << res[0] / 10 << ";" << res[1] / 10 << ";" << res[2] / 10<<";"<<endl;
    }
    fout.close();
    return 0;
}
double alghorithms(int i, vector<vector<int>> graph, vector<pair<int,int>> pairs){
    clock_t startTime;
    clock_t endTime;
    double duration;
    switch (i)
    {
        case 0:{
            FordFulkerson fordFulkerson = FordFulkerson(graph, pairs);
            startTime = clock();
            fordFulkerson.run();
            break;
        }
        case 1:{
            EdmondCarp edmondCarp = EdmondCarp(graph,pairs);
            startTime = clock();
            edmondCarp.run();
            break;
        }
        case 2:{
            Dinic dinic = Dinic(graph, graph.size(), pairs);
            startTime = clock();
            dinic.run();
            break;
        }

    }
    endTime = clock();
    duration = (endTime - startTime) / (double) CLOCKS_PER_SEC * 1000 ;
    return duration;
}