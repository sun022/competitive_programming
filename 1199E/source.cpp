#include <bits/stdc++.h>

using namespace std;

void f(){
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> edges(3*N);
    for(int i=0;i<M;i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
        f();

    return 0;
}