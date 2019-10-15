#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, H;
    cin >> N >> M >> H;

    vector<int> A(M);
    for(int i=0;i<M;i++)
        cin >> A[i];
    
    vector<int> B(N);
    for(int i=0;i<N;i++)
        cin >> B[i];

    vector<vector<bool>> T(N, vector<bool>(M, false));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int x; cin >> x;
            T[i][j] = x;
        }
    }

    vector<vector<int>> X(N, vector<int>(M)); // answer

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            X[i][j] = H;
            if(!T[i][j]) X[i][j] = 0;
            X[i][j] = min(X[i][j], A[j]);
            X[i][j] = min(X[i][j], B[i]);
            cout << X[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}