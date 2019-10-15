#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1000000007;

vector<int64_t> A;
vector<int64_t> x;
vector<int64_t> y;

vector<int> next_greater_left;
vector<int> next_greater_right;

int64_t gtotal = 0;

int64_t f(int i, int j, int dir){
    if(!(i<=j)) return 0;
    
    int m = i;
    for(int k = i; k <= j; k++){
        if(A[k] > A[m]) m=k;
    }
    
    // m is index of greatest element in [i, j]
    
    if(dir != -1){
        for(int k = i; k < m; k++){
            //cout << "k=" << k << endl;
            int prev = next_greater_left[k];
            //cout << "prev=" << prev << endl;
            if(i <= prev) {
                x[k] = (x[prev] + (k-prev) * A[k]) % MOD;
            }
            else {
                x[k] = ((k-i+1) * A[k] ) % MOD;
            }
            y[k] = (k==i ? 0 : y[k-1]) + (x[k] - (k-i+1) * A[k]);
            y[k] %= MOD;

        }
    }
    // cout << "tot1:" << tot1 << endl;

    if(dir != 1){
        for(int k = j; k > m; k--){
            //cout << "k=" << k << endl;
            int prev = next_greater_right[k];
            //cout << "prev=" << prev << endl;
            if(i <= prev && prev <= j) {
                x[k] = (x[prev] + (prev - k) * A[k]) % MOD;
            }
            else {
                x[k] = ((j-k+1) * A[k] ) % MOD;
            }
            y[k] = (k==j ? 0 : y[k+1]) + (x[k] - (j-k+1) * A[k]);
            y[k] %= MOD;
        }
    }

    if(m-1 >= i)
        gtotal += y[m-1] * (j - m + 1);
    if(m+1 <= j)
        gtotal += y[m+1] * (m - i + 1);
    gtotal %= MOD;
    f(i, m-1, -1);
    f(m + 1, j, 1);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;

    for(int t=1;t<=T;t++){
        int N;
        cin >> N;
        A = vector<int64_t>(N);
        for(int i=0;i<N;i++)
            cin >> A[i];

        next_greater_right = vector<int>(N, -1);
        {
            stack<pair<int,int>> s;
            for(int i=0;i<N;i++){
                while(s.size() != 0 && A[i] > s.top().first) {
                    next_greater_right[s.top().second] = i;
                    s.pop();
                }
                s.push({A[i],i});
            }
        }
        next_greater_left = vector<int>(N, -1);
        {
            stack<pair<int,int>> s;
            for(int i=N-1;i>=0;i--){
                while(s.size() != 0 && A[i] > s.top().first) {
                    next_greater_left[s.top().second] = i;
                    s.pop();
                }
                s.push({A[i],i});
            }
        }       

        x = vector<int64_t>(N);
        y = vector<int64_t>(N);

        gtotal = 0;
        f(0, N-1, 0);
        if(gtotal < 0)
            gtotal += MOD;
        cout << "Case #" << t << ": " << gtotal << endl;
    }
    

    return 0;
}