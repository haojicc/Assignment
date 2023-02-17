#include <iostream>
#include "vector"
#include "reader.h"
#include "Kosaraju.h"


void printGraph(Graph& g){
    for(int i = 0; i < g.size(); i++){
        cout << "From" << i << ":";
        for(auto ele: g[i]){
            cout << ele << " , ";
        }
        cout << "\n";
    }
}

void printSSC(ssc& re){
    for(int i = 0; i < re.size(); i++){
        cout << "第" << i << "个ssc：" ;
        for(auto item: re[i]){
            cout << item << ",";
        }
        cout << "\n";
    }
}

int main() {
    string fileName = "/Users/haoji/CLionProjects/Kosaraju/dataSet";
    fileReader reader;
    Graph g = reader.transformToAdjacencyList(fileName);
    printGraph(g);
    stronglyConnectedComponentsAlgo sscAlgo;
    sscAlgo.setNumOfVertics(reader.getNumOfVertics());
    vector<int> visited(reader.getNumOfVertics()+1, 0);
    stack<int> s;
    for(int v = 1; v <= reader.getNumOfVertics(); v++){
        sscAlgo.DFS(g,visited,s,v);
    }

    Graph rg = sscAlgo.reverse(g, reader.getNumOfVertics());
    ssc ret = sscAlgo.findSSC(rg, s);
    printSSC(ret);

    return 0;
}
