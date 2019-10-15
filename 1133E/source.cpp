#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    vector<vector<int>> f(N+1);
    for(int i=0;i<=N;i++){
        f[i] = vector<int>(K+1, 0);
    }
    

    int i=0, j=0;
    while(j != N) {
        if(A[j] - A[i] <= 5){
            // cur is largest valid team ending in j
            // cout << i << "->" << j << endl;
            // lets fix f[j+1][k]
            for(int k=1; k<=min(j+1, K);k++){
                f[j+1][k] = f[j][k];
                for(int sz = 1; sz <= j-i+1; sz++) {                
                    f[j+1][k] = max(f[j+1][k], sz + f[j+1 - sz][k - 1]);
                }
            }

            j++;
        } else {
            // not valid team
            i++;
        }
    }

    // for(int i=0;i<=N;i++){
    //     for(auto x : f[i])
    //         cout << x << " ";
    //     cout << endl;
    // }

    cout << f[N][K] << endl;

    return 0;
}