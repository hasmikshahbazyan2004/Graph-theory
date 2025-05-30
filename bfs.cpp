#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> bfs (int V, vector<int> adj[]){
    vector<int> vis(V, 0); //array to mark nodes 1 when we visit them 
    queue<int> q; // queue, for keeping all the neighbours of a node

    vis[0] = 1; //mark the very first node as visited
    q.push(0); // pushing it to the queue

    vector<int> bfs; // vector for keeping the traversed nodes. It is returned at the end of the function

    while (!q.empty()){ //while the queue is not empty
        int node = q.front(); // keep the upper node in the queue
        q.pop(); // delete it from the queue, so next time we get the next one
        bfs.push_back(node); // push the node into the vector

        for (int it: adj[node]){ // go through all the neighbours of the node
            if (!vis[it]){ // iff the neighbour is not visited
                vis[it] = 1; // mark the neighbour as visited
                q.push(it); // push it into the queue

            }
        }

    }

    return bfs; // return the result

}

int main() {
    int V = 5;  // Number of vertices
    vector<int> adj[V];

    // Example graph:
    // 0 - 1
    // |   |
    // 3 - 2
    // 4 (disconnected)

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(3);
    adj[3].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    vector<int> result = bfs(V, adj);

    cout << "BFS traversal from node 0: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
