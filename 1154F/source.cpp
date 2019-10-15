#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N); // cost
    for(int i=0;i<N;i++)
        cin >> A[i];
    sort(A.begin(), A.end());

    vector<int> B_x(M);
    vector<int> B_y(M);

    for(int i=0;i<M;i++)
        cin >> B_x[i] >> B_y[i];

    // cheapest cost to buy the first k shovels?

    vector<vector<int>> interval_sum(K, vector<int>(K)); // incl. [a,b]
    for(int a=0;a<K;a++){
        interval_sum[a][a] = A[a];
        for(int b=a+1;b<K;b++){
            interval_sum[a][b] = interval_sum[a][b-1] + A[b];
        }
    }

    vector<int> dp(K+1);
    dp[0] = 0;
    for(int k=1;k<=K;k++){
        int best = dp[k-1] + A[k-1];
        for(int i=0;i<M;i++){
            if(B_x[i] <= k){ // if offer possible
                //int cost = dp[k-B_x[i]] + plus the next (B_y[i]-B_x[i]);
                int cost;
                if(B_x[i] == B_y[i])
                    cost = dp[k-B_x[i]];
                else
                    cost = dp[k-B_x[i]] + interval_sum[k-(B_x[i]-B_y[i])][k-1];
                best = min(cost, best);
            }
        }
        dp[k] = best;
        // cout << k << ":\t" << best << endl;
    }
    cout << dp[K] << endl;
    return 0;
}