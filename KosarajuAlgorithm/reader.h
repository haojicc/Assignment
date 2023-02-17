#ifndef KOSARAJU_READER_H
#define KOSARAJU_READER_H
using namespace std;
typedef vector<vector<int>> Graph;

class fileReader{
public:
    Graph transformToAdjacencyList(string& fileName);
    int numOfVertics;
    int numOfEdge;

    int getNumOfVertics() const;

    void setNumOfVertics(int numOfVertics);
};

#endif //KOSARAJU_READER_H
