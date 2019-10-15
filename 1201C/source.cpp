#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int64_t K;
    cin >> N >> K;
    vector<int64_t> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    const int m = N/2;
    int64_t val = A[m];
    int sz = 1;

    while(m+sz != N){
        int64_t to_next = (A[m+sz] - val)*sz;
        // cout << "cost to " << sz+1 << "=" << to_next << endl;
        if(to_next <= K){
            val = A[m+sz];
            sz++;
            K -= to_next;
        }
        else {            
            break;
        }
    }
    val += K/sz;
    cout << val << endl;

    return 0;
}