#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int64_t> W;

int64_t tree_dfs(int x, int from){
    int64_t ret = 0;
    for(auto y : adj[x]){
        if(y==from) continue;
        ret = max(ret, tree_dfs(y, x));
    }
    return W[x] + ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    adj = vector<vector<int>>(N);

    W = vector<int64_t>(N);
    for(int i=0;i<N;i++){
        cin >> W[i];
    }

    for(int i=0;i<M;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s; cin >> s; s--;

    if(N-1 == M){ // TREE
        int64_t m = tree_dfs(s, -1);
        cout << m << endl;
        return 0;
    }

    vector<int> branchStatus(N, 0);
    int64_t start_branch_val = 0;

    vector<int64_t> potential;

    
    


    

    // get everything that isn't a branch for free

    // get exit amount if S was on a branch (deduct amount from branch future reward)

    // get a single branch value

    int64_t max_branch = 0;
    for(auto y : potential)
        max_branch = max(max_branch, y);

    int64_t score = start_branch_val;
    for(int i=0;i<N;i++){
        if(branchStatus[i] == 0)
            score += W[i];
    }
    score += max_branch;

    cout << score << endl;

    return 0;
}