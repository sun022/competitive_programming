#include <bits/stdc++.h>

using namespace std;

const int C = 19;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int> most_rec(C, -1); // iterator
    vector<vector<int>> next(N, vector<int>(C, -1));
    vector<vector<int>> X(N, vector<int>(C, INT_MAX)); // X[i][c] is earliest no. that can reach >=i with bit c true

    for(int i=0;i<N;i++){
        for(int c=0; c < C ;c++){
            bool b = (A[i] >> c)&1;
            if(!b) continue;
            if(most_rec[c] != -1)
                next[most_rec[c]][c] = i;
            most_rec[c] = i;
        }
    }

    for(int i=N-1;i>=0;i--){
        for(int c=0;c < C;c++){
            bool b = (A[i] >> c)&1;
            if(!b) continue;
            X[i][c] = i;
            int next_c = next[i][c];
            if(next_c == -1) continue;
            for(int c1=0;c1<C;c1++)
                X[i][c1] = min(X[i][c1], X[next_c][c1]);
        }
    }

    // for(int i=0;i<N;i++){
    //     cout << i << ":\t";
    //     for(int c=0;c < 3;c++){
    //         cout << X[i][c] << " ";
    //     }
    //     cout << endl;
    // }

    for(int q=1;q<=Q;q++){
        int x,y;
        cin >> x >> y;
        x--; y--;
        bool pos=false;
        for(int c=0;c<C;c++){ // destination col
            if(!((A[y] >> c)&1)) continue;
            if(X[x][c] <= y){
                pos = true;
                break;
            }
        }
        cout << (pos ? "Shi" : "Fou") << endl;
    }

    return 0;
}