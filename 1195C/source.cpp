#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int64_t> A(N), B(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
    for(int i=0;i<N;i++)
        cin >> B[i];

    vector<int64_t> C(N);
    vector<int64_t> D(N);

    C[0] = A[0];
    D[0] = B[0];

    for(int i=1;i<N;i++){
        C[i] = max(C[i-1], D[i-1] + A[i]);
        D[i] = max(D[i-1], C[i-1] + B[i]);
    }

    cout << max(C[N-1], D[N-1]) << endl;

    return 0;
}