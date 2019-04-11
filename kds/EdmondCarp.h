//
// Created by Weezle on 2019-04-10.
//

#ifndef KDS_EDMONDCARP_H
#define KDS_EDMONDCARP_H
#include <vector>
#include <queue>
using namespace std;

class EdmondCarp
{
public:
    EdmondCarp(vector<vector<int>> G, vector<pair<int, int>> pairs);
    void run();
    int edmondCarp(vector<vector<int>>& G,int s,int t);

private:
    vector<vector<int>> G;
    vector<std::pair<int, int>> pairs;
};


#endif //KDS_EDMONDCARP_H
