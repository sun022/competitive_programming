#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<string> map(N);
    for(int i=0;i<N;i++)
        cin >> map[i];

    vector<vector<int>> p(N, vector<int>(M));;
    p[0][0] = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(i == 0 && j == 0) continue;
            if(map[i][j] == '#'){
                p[i][j] = 0;
                continue;
            }
            p[i][j] = 0;
            if(i-1 >= 0) p[i][j] += p[i-1][j];
            if(j-1 >= 0) p[i][j] += p[i][j-1];

            if(p[i][j] > 1) p[i][j] = 1;
        }
    }
    
    if(p[N-1][M-1] == 0){
        cout << "0" << endl; return 0;
    }

    vector<vector<int>> q(N, vector<int>(M));
    q[0][0] = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(i == 0 && j == 0) continue;
            if(map[N-1-i][M-1-j] == '#'){
                q[i][j] = 0;
                continue;
            }
            q[i][j] = 0;
            if(i-1 >= 0) q[i][j] += q[i-1][j];
            if(j-1 >= 0) q[i][j] += q[i][j-1];

            if(q[i][j] > 1) q[i][j] = 1;
        }
    }

    vector<int> X(N+M-1, 0);

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(p[i][j] && q[N-1-i][M-1-j])
                X[i+j]++;
        }
    }

    bool single = false;
    for(int i = 1; i <= N+M-3; i++){
        // cout << i << ":" << X[i] << endl;
        if(X[i] == 1)
            single = true;
    }

    if(single)
        cout << "1" << endl;    
    else
        cout << "2" << endl;


    return 0;
}