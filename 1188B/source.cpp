#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,P,K;
    cin >> N >> P >> K;
    vector<int64_t> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    map<int,int> m;

    for(auto x : A){
        int64_t c = x * x % P * x % P * x % P;
        c = c - K*x;
        c %= P;
        if(c<0) c+= P;
        m[c]++;
    }

    int64_t ans = 0;
    for(auto [k,v]:m){
        ans += v * (v-1)/2;
    }
    cout << ans << endl;

    return 0;
}