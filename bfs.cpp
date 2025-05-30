#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> bfs (int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    queue<int> q;

    vis[0] = 1;
    q.push(0);

    vector<int> bfs;

    while (!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (int it: adj[node]){
            if (!vis[it]){
                vis[it] = 1;
                q.push(it);

            }
        }

    }

    return bfs;

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
