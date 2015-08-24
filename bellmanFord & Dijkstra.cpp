#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("/Users/jiayajie/Desktop/graph.txt");

void Dijkstra(int nodeNum, int start, int end, int* graph) {
    vector<int> lastNode(nodeNum, start);
    vector<int> nodes(nodeNum, 0);
    vector<int> path(nodeNum, INT_MAX);
    path[start] = 0;
    
    while(1) {
        int min_path = INT_MAX, min_node = 0;
        for(int i = 0; i < nodeNum; i++)
            if(nodes[i] == 0 && path[i] < min_path) {
                min_path = path[i];
                min_node = i;
            }
        if(min_path == INT_MAX)
            break;
        else
            nodes[min_node] = 1;
        
        for(int i = 0; i < nodeNum; i++) {
            int length = *(graph + min_node * nodeNum + i);
            if(length < INT_MAX && length > 0) {
                if(path[min_node] + length < path[i] && !nodes[i]) {
                    path[i] = path[min_node] + length;
                    lastNode[i] = min_node;
                }
            }
        }
    }
    cout<<path[end]<<endl;
}

void BellmanFord(int nodeNum, int roadNum, int start, int end, int* graph) {
    vector<int> path(nodeNum, INT_MAX);
    vector<int> LastNode(nodeNum, start);
    path[start] = 0;
    for(int i = 0; i < nodeNum; i++) {
        for(int ii = 0; ii < nodeNum; ii++)
            for(int jj = 0; jj < nodeNum; jj++) {
                int length = *(graph + ii* nodeNum + jj);
                if(length < INT_MAX && path[ii] < INT_MAX
                   && path[ii] + length < path[jj]) {
                    path[jj] = path[ii] + length;
                    LastNode[jj] = ii;
                }
            }
    }
    cout<<path[end]<<endl;
}

int main() {
    int nodeNum, roadNum, start, end;
    string str;
    in>>nodeNum>>roadNum>>start>>end;
    getline(in, str);
    
    int* graph = new int(nodeNum*nodeNum);
    for(int i = 0; i < nodeNum; i++)
        for(int j = 0; j < nodeNum; j++) {
            if(i == j)
                *(graph + i * nodeNum + j) = 0;
            else
                *(graph + i * nodeNum + j) = INT_MAX;
        }
    
    int node1, node2, length;
    for(int i = 0; i < roadNum; i++) {
        in>>node1>>node2>>length;
        node1--, node2--;
        getline(in, str);
        int curlen = *(graph + node1*nodeNum + node2);
        if(curlen > length) {
            *(graph + node1*nodeNum + node2) = length;
            *(graph + node2*nodeNum + node1) = length;
        }
    }
    for(int i = 0; i < nodeNum; i++) {
        for(int j = 0; j < nodeNum; j++)
            cout<<*(graph + i * nodeNum + j)<<" ";
        cout<<endl;
    }
//    Dijkstra(nodeNum, start - 1, end - 1, graph);
 
    BellmanFord(nodeNum, roadNum, start -1, end - 1, graph);
    
    delete []graph;
}