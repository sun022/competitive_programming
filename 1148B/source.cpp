#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N, M, T1, T2, K;
    cin >> N >> M >> T1 >> T2 >> K;
    
    vector<int64_t> A(N), B(M);
    for(int64_t i=0;i<N;i++)
        cin >> A[i];
    for(int64_t i=0;i<M;i++)
        cin >> B[i];

    if(!(K < N && K < M)){
        cout << "-1" << endl;
        return 0;
    }
    // x = num cancelled on first leg]

    int64_t ret=-1;
    int64_t it=0;
    for (int64_t x=0;x<=K;x++) {
        int64_t y = A[x] + T1;
        while(it != M && B[it] < y) it++;
        if(it + (K-x) >= M){
            cout << -1 << endl;
            return 0;
        }
        ret = max(ret, B[it + (K-x)] + T2);
        // cout << x << " " << it + (K-x) << endl;
    }
    cout << ret << endl;
    return 0;
}