#include <bits/stdc++.h>

using namespace std;

// https://cp-algorithms.com/graph/bridge-searching.html
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void IS_BRIDGE(int x, int y){
    cout << x << "," << y << " is a bridge" << endl;
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M;
    cin >> n >> M;

    adj = vector<vector<int>>(n);
    // visited = vector<bool>(N, false);
    // tin = vector<int>(N);
    // low = vector<int>(N);

    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin >> A[i];

    for(int i=0;i<M;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s; cin >> s; s--;

    find_bridges();
    

    return 0;
}