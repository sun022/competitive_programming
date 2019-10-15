#include <bits/stdc++.h>

using namespace std;

void f(){
    int N,M;
    cin >> N >> M;

    vector<int> col_max(M, 0);

    vector<vector<int>> A(N,vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> A[i][j];
            col_max[j] = max(col_max[j], A[i][j]);
        }
    }

    vector<int> w(M);
    iota(w.begin(), w.end(), 0);
    sort(w.begin(), w.end(), [&col_max](int i,int j){return col_max[i]>col_max[j];});

    int P = min(M, N);

    int ans = 0;

    int x = 1; // N^P;
    for(int i=1;i<=P;i++)
        x *= N;
    x--;

    for(;x>=0;x--){
        vector<int> max(N, 0);
        
        // x % 4 is status of col j
        int y = x;
        for(int p=0;p<P;p++){
            int j = w[p];
            for(int i=0;i<N;i++){
                max[i] = std::max(max[i], A[(i+(y%N))%N][j]);
            }
            y/= N;
        }
        
        int sum = 0;
        for(auto x : max)
            sum += x;
        
        ans = std::max(ans, sum);
    }
    cout << ans << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
        f();


   

    return 0;
}