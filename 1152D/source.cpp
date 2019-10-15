#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    vector<vector<int64_t>> X(N+1, vector<int64_t>(N+1));
    vector<vector<int64_t>> Y(N+1, vector<int64_t>(N+1));

    X[0][0] = 0;
    Y[0][0] = 0;
    for(int T = 1; T <= 2*N; T++){
        for(int a = 0; a <= T; a++){
            int b = T-a;
            if(b < a) continue;
            if(b > N) continue;

            //cout << a << " " << b << endl;

            if(a == 0){ // close only
                X[a][b] = 1 + Y[a][b-1];
                Y[a][b] = X[a][b-1];
            }
            else if(a == b){ // open only
                X[a][b] = 1 + Y[a-1][b];
                Y[a][b] = X[a-1][b];
            }
            else {
                X[a][b] = 1 + max(X[a-1][b] + Y[a][b-1], Y[a-1][b] + X[a][b-1]);
                Y[a][b] = X[a-1][b] + X[a][b-1];
            }
            X[a][b] %= 1000000007;
            Y[a][b] %= 1000000007;

            //cout << "X[" << a << "][" << b << "] = \t" << X[a][b] << endl;
            //cout << "Y[" << a << "][" << b << "] = \t" << Y[a][b] << endl;
            //cout << endl;
        }

    }
    cout << X[N][N] << endl;

    return 0;
}