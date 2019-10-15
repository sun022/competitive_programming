#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, X;
    cin >> N >> X;
    vector<int64_t> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<vector<int64_t>> dp(N, vector<int64_t>(3,0));
    dp[0] = {A[0], A[0]*X, max(A[0], A[0]*X)};
    int64_t ans = 0;
    ans = max(ans, dp[0][0]);
    ans = max(ans, dp[0][1]);
    ans = max(ans, dp[0][2]);
    for(int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i-1][0] + A[i], A[i]);
        dp[i][1] = max(dp[i-1][0] + A[i]*X, max(dp[i-1][1] + A[i]*X, A[i]*X));
        dp[i][2] = max(dp[i-1][2] + A[i], max(dp[i-1][1] + A[i], A[i]));
        // cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
        ans = max(ans, dp[i][2]);
    }

    cout << ans << endl;    

    return 0;
}