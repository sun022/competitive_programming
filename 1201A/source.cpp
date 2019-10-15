#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<string> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int> reward(M);
    for(int i=0;i<M;i++)
        cin >> reward[i];

    int64_t ans = 0;
    for(int i=0;i<M;i++){
        vector<int> count(5,0);
        for(int j=0;j<N;j++)
            count[A[j][i]-'A']++;
        
        int m = 0;
        for(int j=0;j<5;j++)
            m = max(m, count[j]);
        ans += m*reward[i];
    }
    cout << ans << endl;

    return 0;
}