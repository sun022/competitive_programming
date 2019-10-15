#include <bits/stdc++.h>

using namespace std;

vector<int> opp;
vector<int> par;
vector<vector<int>> child;

vector<int> min_val,max_val;
vector<int> sz;

void dfs(int x){
    if(child[x].size() == 0){
        sz[x] = 1;
        min_val[x] = 0;
        max_val[x] = 0;
        //cout << x << "(" << opp[x] << ")\t" << sz[x] << "\t" << min_val[x] << "\t" << max_val[x] << endl;
        return;
    }
    sz[x]=0;
    for(auto y:child[x]){
        dfs(y);
        sz[x] += sz[y];
    }

    if(opp[x] == 1){
        // work out max
        int loss = sz[x];
        for(auto y:child[x]){
            loss = min(loss, sz[y] - max_val[y]);
        }
        max_val[x] = sz[x] - loss;

        // work out min
        loss = 0;
        for(auto y:child[x]){
            loss += min_val[y] + 1;
        }
        min_val[x] = loss - 1;
    }
    else {
        // work out min
        int loss = sz[x]-1;
        for(auto y:child[x]){
            loss = min(loss, min_val[y]);
        }
        min_val[x] = loss;

        // work out max
        loss = 0;
        for(auto y:child[x]){
            loss += sz[y] - max_val[y];
        }
        max_val[x] = sz[x] - loss;

    }

    
    //cout << x << "(" << opp[x] << ")\t" << sz[x] << "\t" << min_val[x] << "\t" << max_val[x] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    opp = vector<int>(N);
    for(int i=0;i<N;i++)
        cin >> opp[i];

    par = vector<int>(N);
    child = vector<vector<int>>(N);
    sz = vector<int>(N);
    min_val = vector<int>(N);
    max_val = vector<int>(N);

    par[0] = -1;
    for(int i=1;i<N;i++){
        cin >> par[i]; par[i]--;
        child[par[i]].push_back(i);
    }

    // for every node x, calc min and max of this subtree with x as root
    dfs(0);
    cout << max_val[0] + 1 << endl;

    return 0;
}