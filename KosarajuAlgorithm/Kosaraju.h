#ifndef KOSARAJU_KOSARAJU_H
#define KOSARAJU_KOSARAJU_H

#include <stack>
#include "iostream"
#include "vector"
#include "Kosaraju.h"
#include "reader.h"

typedef vector<vector<int>> ssc;

class stronglyConnectedComponentsAlgo{
public:
    int numOfVertics;

    int getNumOfVertics() const;

    void setNumOfVertics(int numOfVertics);
    Graph reverse(Graph &g, int numOfVertics);
    void DFS(Graph &g, vector<int> &visited, std::__1::stack<int> &s, int v);
    void findSSCDFS(vector<int> &ssc, vector<int> &visited, Graph &g, int v);

    ssc findSSC(Graph &rg, stack<int>& s);
};

#endif //KOSARAJU_KOSARAJU_H
