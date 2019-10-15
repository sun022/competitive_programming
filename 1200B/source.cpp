#include <bits/stdc++.h>

using namespace std;

bool f(){
    int64_t N, M, K;
    cin >> N >> M >> K;
    vector<int64_t> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    // go down to max(0, A[i] - K)
    int cur = A[0];
    for(int i=0;i<N-1;i++){
        int64_t target = max((int64_t)0, (int64_t)(A[i+1] - K));
        int64_t diff = target - cur;
        if(diff > M)
            return false;
        M -= diff;
        cur = A[i+1];
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
        cout << (f() ? "YES" : "NO") << endl;

    return 0;
}