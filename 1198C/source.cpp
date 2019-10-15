#include <bits/stdc++.h>

using namespace std;

void f(){
    int N,M;
    cin >> N >> M;
    vector<vector<pair<int,int>>> edge(3*N);

    for(int i=1;i<=M;i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        edge[u].push_back({v,i});
        edge[v].push_back({u,i});
    }

    vector<int> state(3*N, 0);
    vector<int> matching;
    vector<int> indep;
    for(int i=0;i<3*N;i++){
        if(state[i] != 0) continue;
        for(auto [y, edge_index] : edge[i]){
            if(state[y] == 0){
                matching.push_back(edge_index);
                state[y] = 1;
                state[i] = 1;
                break;
            }
        }
        if(state[i] == 0){
            state[i] = 2;
            indep.push_back(i+1);
        }
    }

    if(matching.size() >= N){
        cout << "Matching" << endl;
        for(int i=0;i<N;i++)
            cout << matching[i] << " ";
        cout << endl;
    }
    else {
        cout << "IndSet" << endl;
        for(int i=0;i<N;i++)
            cout << indep[i] << " ";
        cout << endl;
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