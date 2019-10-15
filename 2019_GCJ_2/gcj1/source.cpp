#include <bits/stdc++.h>

using namespace std;

int64_t hcf(int64_t a, int64_t b){
    if(a < 0) return hcf(-a, b);
    if(b < 0) return hcf(a, -b);
    if(b == 0) return a;
    return hcf(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int t=1;t<=T;t++){
        int N; cin >> N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin >> A[i] >> B[i];
        }

        set<pair<int,int>> s;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                // i to j:
                // cout << i << "," << j << "\t:" << A[j]-A[i] << "," << B[j] - B[i] << endl;
                int64_t p = A[j]-A[i];
                int64_t q = B[j]-B[i];
                if(q < 0 || (q==0 && p<0)) {
                    p = -p; q = -q;
                }
                if(p >= 0) continue;
                int64_t d = hcf(p,q);
                p /= d;
                q /= d;
                s.insert({p, q});
            }
        }
        // for(auto p : s){
        //     cout << -p.first << " " << p.second << endl;
        // }
        int ans = s.size() + 1;
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}