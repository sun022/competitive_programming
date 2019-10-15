#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> par;
vector<vector<int>> child;

vector<int64_t> S;
vector<int64_t> A;

// dfs through the tree, assigning values for A
// odd numbers are trival from parent and even are max possible (or 0 if no children)
void dfs(int i){
    int64_t par_val = (par[i] != -1 ? S[par[i]] : 0);
    if(S[i] != -1){
        A[i] = S[i] - par_val;
    }
    else {
        if(child[i].size() == 0)
            A[i] = 0;
        else {
            A[i] = LLONG_MAX;
            for(auto y : child[i])
                A[i] = min(A[i], S[y] - par_val);
        }
        S[i] = par_val + A[i];
    }

    for(auto y : child[i])
        dfs(y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    par = vector<int>(N); par[0] = -1;
    child = vector<vector<int>>(N);
    for(int i=1;i<N;i++){
        cin >> par[i];par[i]--;
        child[par[i]].push_back(i);
    }

    S = vector<int64_t>(N);
    A = vector<int64_t>(N);
    for(int i=0;i<N;i++)
        cin >> S[i];

    
    dfs(0);

    int64_t sum = 0;
    bool soln = true;
    for(int i=0;i<N;i++){
        sum += A[i];
        if(A[i] < 0) soln = false;
    }

    if(!soln) sum = -1;
    cout << sum << endl;    

    return 0;
}