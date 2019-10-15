#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M, 0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> A[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int x;
            cin >> x;
            A[i][j] = A[i][j] ^ x;
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(int i=0;i<=N-2;i++){
        for(int j=0;j<=M-2;j++){
            if(A[i][j] == 1){
                A[i][j] = 1 - A[i][j];
                A[i+1][j] = 1 - A[i+1][j];
                A[i][j+1] = 1 - A[i][j+1];
                A[i+1][j+1] = 1 - A[i+1][j+1];
            }
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=0;i<N;i++)
        if(A[i][M-1] == 1){
            cout << "No" << endl; return 0;
        }
    for(int j=0;j<M;j++)
        if(A[N-1][j] == 1){
            cout << "No" << endl; return 0;
        }
    
    cout << "Yes" << endl;
    return 0;
}