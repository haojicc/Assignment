#include "iostream"
#include "sstream"
#include "fstream"
#include "vector"
#include "reader.h"
using namespace std;

/**
* D V E
 * e v_1 v_2
 * e v_3 v_4
 * ...
*/

typedef vector<vector<int>> Graph;

Graph fileReader::transformToAdjacencyList(string& fileName){
    ifstream graphFile;
    graphFile.open(fileName);
    Graph graph;
    if(graphFile.is_open()){
        string line;
        while(getline(graphFile, line)){
            istringstream iss(line);
            vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
            if(results[0].compare(0,1,"D") == 0){
                numOfVertics = stoi(results[1]);
                numOfEdge = stoi(results[2]);
                graph.resize(numOfVertics + 1);
            }else{
                int v1 = stoi(results[1]);
                int v2 = stoi(results[2]);
                graph[v1].push_back(v2);
            }
        }
        graphFile.close();
    }
    return graph;
}

int fileReader::getNumOfVertics() const {
    return numOfVertics;
}

void fileReader::setNumOfVertics(int numOfVertics) {
    fileReader::numOfVertics = numOfVertics;
}
