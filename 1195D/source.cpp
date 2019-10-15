#include <bits/stdc++.h>

using namespace std;

int64_t MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    int64_t sum=0;

    for(int i=0;i<N;i++){
        int64_t contrib=0;
        int64_t x = A[i];
        int64_t pow = 1;
        while(x!=0){
            int d = x%10; x/=10;
            contrib += d*pow;
            contrib += d*pow*10;
            
            
            pow = (pow*100)%MOD;
        }
        sum = sum + (N*contrib)%MOD;
        sum %= MOD;
    }

    cout << sum << endl;

    return 0;
}