#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    int64_t sum = 0;
    int64_t ma = 0;
    for(int i=0;i<N;i++){
        sum += A[i];
        ma = max(ma, A[i]);
    }

    if(sum % 2 != 0 || 2*ma > sum)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    

    return 0;
}