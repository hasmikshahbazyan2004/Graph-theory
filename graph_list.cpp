#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph{
private:
    unordered_map<int, vector<int>> list;

public:
    void addEdge(int u, int v, bool isDirected = false){
        list[u].push_back(v);

        if (!isDirected){
            list[v].push_back(u);
        }
    }

    void display(){
        cout << "Adjacency matrix\n";

        for (auto node: list){
            cout << node.first << " -> ";
            for (int neighbour: node.second){
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph g;

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4, true);

    g.display();
}