#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, D;
    cin >> N >> D;
    vector<int> gem(30001, 0);
    for(int i=0;i<N;i++){
        int y; cin >> y;
        gem[y]++;
    }

    vector<map<int, int>> dp(30001);
    dp[D][D] = 0;

    int ans = 0;
    for(int i=D;i<=100;i++){
        // project forward
        int e = gem[i];
        cout << i << "\t" << dp[i].size() << endl;
        for(auto [d, v] : dp[i]){
            ans = max(ans, v+e);
            if(i+d-1 > i && i+d-1 <= 30000)
                dp[i+d-1][d-1] = max(v+e, dp[i+d-1][d-1]);
            if(i+d > i && i+d <= 30000)
                dp[i+d][d] = max(v+e, dp[i+d][d]);
            if(i+d+1 > i && i+d+1 <= 30000)
                dp[i+d+1][d+1] = max(v+e, dp[i+d+1][d+1]);
        }
    }
    cout << ans << endl;
    return 0;
}