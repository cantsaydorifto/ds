#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class graph {
   public:
    int vertices;
    unordered_map<int, list<int> > adj;
    graph(int v) {
        vertices = v;
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void BFS(int start) {
        vector<bool> visited(vertices);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            start = q.front();
            cout << start << " ";
            q.pop();
            for (auto i : adj[start]) {
                if (!visited[i]) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    void callDFS(unordered_map<int, bool> &visited, int node) {
        cout << node << " ";
        visited[node] = 1;
        for (auto i : adj[node]) {
            if (!visited[i]) {
                callDFS(visited, i);
            }
        }
    }
    void DFS(int start) {
        unordered_map<int, bool> visited;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                vector<int> temp;
                callDFS(visited, start);
            }
        }
    }
};
int main() {
    int n, m;
    cout << "Enter number of nodes : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int a;
    cout << "Enter starting point for BFS:";
    cin >> a;
    g.BFS(a);
    cout << endl;
    int b;
    cout << "Enter starting point for DFS:";
    cin >> b;
    g.DFS(b);
    return 0;
}