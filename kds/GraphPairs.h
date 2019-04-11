//
// Created by Weezle on 2019-04-11.
//

#ifndef KDS_GRAPHPAIRS_H
#define KDS_GRAPHPAIRS_H
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;

const string inputfiles[40] = {
        "../input/input_10_0.0.txt", "../input/input_10_0.5.txt" , "../input/input_10_1.0.txt", "../input/input_10_disco.txt",
        "../input/input_310_0.0.txt", "../input/input_310_0.5.txt" , "../input/input_310_1.0.txt", "../input/input_310_disco.txt",
        "../input/input_610_0.0.txt", "../input/input_610_0.5.txt" , "../input/input_610_1.0.txt", "../input/input_610_disco.txt",
        "../input/input_910_0.0.txt", "../input/input_910_0.5.txt" , "../input/input_910_1.0.txt", "../input/input_910_disco.txt",
        "../input/input_1210_0.0.txt", "../input/input_1210_0.5.txt" , "../input/input_1210_1.0.txt", "../input/input_1210_disco.txt",
        "../input/input_1510_0.0.txt", "../input/input_1510_0.5.txt" , "../input/input_1510_1.0.txt", "../input/input_1510_disco.txt",
        "../input/input_1810_0.0.txt", "../input/input_1810_0.5.txt" , "../input/input_1810_1.0.txt", "../input/input_1810_disco.txt",
        "../input/input_2110_0.0.txt", "../input/input_2110_0.5.txt" , "../input/input_2110_1.0.txt", "../input/input_2110_disco.txt",
        "../input/input_2410_0.0.txt", "../input/input_2410_0.5.txt" , "../input/input_2410_1.0.txt", "../input/input_2410_disco.txt",
        "../input/input_2710_0.0.txt", "../input/input_2710_0.5.txt" , "../input/input_2710_1.0.txt", "../input/input_2710_disco.txt",
};

int dfs(vector<vector<int>>& graph, int index);
vector<std::pair<int, int>> findAllPairs(vector<vector<int>>& graph);
bool isSource(vector<vector<int>>& graph, int index);
bool isTarget(vector<vector<int>>& graph, int index);
vector<vector<int>> readMatrix(string filename);




#endif //KDS_GRAPHPAIRS_H
