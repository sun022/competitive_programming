#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 10;

int64_t MOD = 998244353;

int len(int x){
    int ret=0;
    while(x!=0){
        x/=10;
        ret++;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int> len_count(MAX_LEN+1, 0);
    for(int i=0;i<N;i++){
        len_count[len(A[i])]++;
    }

    int64_t sum = 0;
    for(int i=0;i<N;i++){
        int L = len(A[i]);
        for(int L2 = 0; L2 <= MAX_LEN; L2++){
            if(len_count[L2] == 0) continue;
            int64_t contrib=0;
            
            int x = A[i];
            int L2_copy = L2;
            int64_t pow = 1;
            while(x!=0) {
                if(L2_copy > 0){
                    pow = pow*10 % MOD;
                    L2_copy--;
                }
                int d = x%10; x/=10;
                contrib += d*pow;
                pow = pow*10 % MOD;
            }
            x = A[i];
            L2_copy = L2;
            pow = 1;
            while(x!=0) {    
                int d = x%10; x/=10;
                contrib += d*pow;
                pow = pow*10 % MOD;
                if(L2_copy > 0){
                    pow = pow*10 % MOD;
                    L2_copy--;
                }
            }

            sum += contrib * len_count[L2] % MOD;
            sum %= MOD;
        }
    }

    cout << sum << endl;

    return 0;
}