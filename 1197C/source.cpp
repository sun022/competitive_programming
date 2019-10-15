#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    vector<int64_t> diff(N-1);

    for(int i=0;i<N;i++)
        cin >> A[i];
    
    for(int i=0;i<N-1;i++)
        diff[i] = A[i+1]-A[i];
    
    sort(diff.begin(), diff.end());

    // sum (k-1) maximum diffs
    int64_t sum = 0;
    for(int a=0; a<K-1; a++){
        sum += diff[N-2 -a];
    }
    //cout << "SUM:" << sum << endl;

    cout << A[N-1] - A[0] - sum << endl;

    return 0;
}