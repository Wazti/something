//
// Created by Weezle on 2019-04-10.
//

#ifndef KDS_FORDFULKERSON_H
#define KDS_FORDFULKERSON_H

#include <vector>
using namespace std;
class FordFulkerson {
public:
    FordFulkerson(vector<vector<int>> vector1, vector<pair<int, int>> pairs);
    void run();
    int fordFulkerson(vector<vector<int>>& G, int s, int t);
private:
    vector<vector<int>> G;
    vector<std::pair<int, int>> pairs;
    int findPath(vector<vector<int>>& G, vector<bool>& visitedArr, int u, int t, int f);
};


#endif //KDS_FORDFULKERSON_H
