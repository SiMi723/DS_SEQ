#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin>> n >> m;
    // Undirected graph here..adj matrix
    // S.C--O(n^2)
    // int adj[n+1][m+1];
    // for(int i=0;i<m;i++) {
    //     int u, v;
    //     cin >> u>> v;
    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }

    // Undirected graph here..adj list
    // S.C--O(2*E)
    vector<int> adj[n+1];
    for(int i = 0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    return 0;
}