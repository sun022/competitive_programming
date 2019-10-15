#include <bits/stdc++.h>

using namespace std;

int main(){
    int N = 20;
    vector<int> S(2*N+1);
    vector<int> T(2*N+1);
    S[0] = 290797;
    for(int i=1;i<=2*N;i++){
        S[i] = (int64_t)S[i-1]*S[i-1] % 50515093;
        T[i] = (S[i]%2000) - 1000;
    }

    vector<int> X(N), Y(N);
    for(int i=1;i<=N;i++){
        X[i] = T[2*i - 1];
        Y[i] = T[2*i];
    }

    int r = 0;
    cout << X[0] << "," << Y[0] << endl;

    for(int i=0;i<N;i++){
        if(i == r) continue;
        if(Y[i] < Y[r]) continue;
        cout << atan2(Y[i]-Y[r], X[i]-X[r]) << endl;
    }

    return 0;
}