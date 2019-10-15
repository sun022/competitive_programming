#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N  >> M;

    vector<int> X(M), Y(M);
    for(int i=0;i<M;i++)
        cin >> X[i] >> Y[i];

    unordered_map<int, vector<int>> x_edge, y_edge;

    for(int i=0;i<M;i++){
        x_edge[X[i]].push_back(Y[i]);
        y_edge[Y[i]].push_back(X[i]);
    }
    
    

    return 0;
}