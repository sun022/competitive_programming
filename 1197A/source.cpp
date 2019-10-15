#include <bits/stdc++.h>

using namespace std;

int f(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    sort(A.begin(), A.end());
    int k_max = A[A.size()-2] - 1; // penultimate

    if(N == 2) return 0;
    return min(k_max, N-2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int ret = f();
        cout << ret << endl;
    }

    return 0;
}