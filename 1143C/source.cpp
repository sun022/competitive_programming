#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> par(N), C(N);
    vector<vector<int>> child(N);
    for(int i=0;i<N;i++){
        cin >> par[i] >> C[i];
        if(par[i] != -1){
            par[i]--;
            child[par[i]].push_back(i);
        }
    }

    vector<int> rm;
    for(int i=0;i<N;i++){
        if(par[i] == -1) continue;
        if(C[i] != 1) continue;
        bool x=true;
        for(auto y : child[i])
            if(C[y] != 1)
                x = false;
        if(x)
            rm.push_back(i);
    }

    if(rm.size() > 0){
        for(auto x : rm)
            cout << x+1 << " ";
        cout << endl;
    }
    else {
        cout << "-1" << endl;
    }
    return 0;
}