#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N, K;
vector<vector<int>> A;
vector<int> state(N, 0);
vector<int> compSize;
int numComponents=0;

void dfs(int x){
    if(state[x] != 0) return;
    state[x] = 1;
    compSize[numComponents]++;
    for(auto y : A[x])
        dfs(y);
}

int64_t pow_mod(int N, int K) {
    int64_t ret=1;
    for(int k=1;k<=K;k++){
        ret = (ret*N) % MOD;
    }
    // cout << N << "^" << K << "=" << ret << endl;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    A = vector<vector<int>>(N);
    for(int i=0;i<N-1;i++){
        int u,v,x;
        cin >> u >> v >> x; u--; v--;
        // cout << u << " " << v << " " << x << endl;
        if(x == 1) continue;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    state = vector<int>(N, 0);
    // dfs find connect components
    for(int root = 0; root < N; root++){
        if(state[root] != 0) continue;
        compSize.push_back(0);
        dfs(root);
        numComponents++;
    }

    int64_t ans = pow_mod(N, K);
    for(int i=0;i < compSize.size(); i++){
        // cout << compSize[i] << endl;
        ans -= pow_mod(compSize[i], K);
        ans %= MOD;
    }
    if(ans < 0) ans += MOD;
    cout << ans << endl;

    return 0;
}