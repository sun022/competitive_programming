#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int prev(int i){
    return (i+N-1)%N;
}


int dfs_root;
vector<int> dfs_cur;
vector<vector<int>> children;
vector<int> par;
vector<int> N_desc;
vector<int> path;

void dfs(int node) {
    path.push_back(node);
    if(path.size() >= N){
        N_desc[node] = path[path.size() - N];
    }
    for(auto y : children[node])
        dfs(y);
    path.pop_back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> Q;
    vector<int> P(N);
    vector<int> P_inv(N);
    for(int i=0;i<N;i++){
        int p_i;
        cin >> p_i; p_i--;
        P_inv[p_i] = i;
    }
    
    vector<int> A(M);
    for(int i=0;i<M;i++){
        int x;
        cin >> x; x--;
        A[i] = P_inv[x];
    }

    par = vector<int>(M, -1);
    children = vector<vector<int>>(M);
    vector<vector<int>> to_process(N);
    for(int i=0;i<M;i++){
        for(auto x : to_process[prev(A[i])]){
            par[x] = i;
            children[i].push_back(x);
        }
        to_process[prev(A[i])].clear();
        to_process[A[i]].push_back(i);
    }

    

    N_desc = vector<int>(M, -1); // (N-1)th descendant

    for(int i = M-1; i >= 0; i--){
        if(par[i] != -1) continue;
        dfs(i);
    }

    // for(int i=0;i<M;i++){
    //      cout << A[i]+1 << " " << par[i] << " " << N_desc[i] << endl;
    // }
    // cout << endl;

    // vector<int> req(M); // end, starting from i specifically
    vector<int> req_all(M); // end, starting from >= i

    for(int i=M-1; i>=0; i--){
        int x = (N_desc[i] == -1) ? INT_MAX : N_desc[i];
        int y = (i == M-1) ? INT_MAX : req_all[i+1];
        req_all[i] = min(x, y);
    }

    // for(int i=0;i<M;i++){
    //     cout << A[i]+1 << " " << N_desc[i] << " " << req_all[i] << endl;
    // }

    for(int q=1;q<=Q;q++){
        int a,b;
        cin >> a >> b; a--; b--;
        cout << (req_all[a] <= b) ? "1" : "0";
    }
    cout << endl;

    return 0;
}