#include "iostream"
#include "Kosaraju.h"
#include "stack"

typedef vector<vector<int>> ssc;


Graph stronglyConnectedComponentsAlgo::reverse(Graph &g, int numOfVertics) {
    Graph rg = vector<vector<int>>(numOfVertics+1);
    for(int i = 0; i < g.size(); i++){
        for(auto v: g[i]){
            rg[v].push_back(i);
        }
    }
    return rg;
}

void stronglyConnectedComponentsAlgo::DFS(Graph &g, vector<int> &visited, stack<int> &s, int v) {
    if(visited[v] == 1){
        return;
    }
    visited[v] = 1;
    for(auto u: g[v]){
        if(visited[u] == 0){
            DFS(g, visited, s, u);
        }
    }
    s.push(v);
}

void stronglyConnectedComponentsAlgo::findSSCDFS(vector<int>& ssc, vector<int> &visited, Graph& g, int v){
    if(visited[v] == 1){
        return;
    }
    visited[v] = 1;
    ssc.push_back(v);
    for(auto u: g[v]){
        if(visited[u] == 0){
            findSSCDFS(ssc, visited, g, u);
        }
    }
}

ssc stronglyConnectedComponentsAlgo::findSSC(Graph &rg, stack<int>& s) {
    vector<int> vitd(numOfVertics+1,0);
    ssc res;
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(vitd[v] == 1){
            continue;
        }else{
            vector<int> s;
            findSSCDFS(s, vitd, rg, v);
            res.push_back(s);
        }
    }
    return res;
}

void stronglyConnectedComponentsAlgo::setNumOfVertics(int numOfVertics) {
    stronglyConnectedComponentsAlgo::numOfVertics = numOfVertics;
}

int stronglyConnectedComponentsAlgo::getNumOfVertics() const {
    return numOfVertics;
}

