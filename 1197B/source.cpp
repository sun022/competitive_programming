#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
        A[i]--;
    }

    int peak;
    for(int i=0;i<N;i++)
        if(A[i] == N-1)
            peak = i;

    bool ret = true;
    for(int i=1;i<=peak;i++) {
        if(!(A[i-1] < A[i]))
            ret = false;
    }

    for(int i=peak+1;i<N;i++) {
        if(!(A[i-1] > A[i]))
            ret = false;
    }

    cout << (ret ? "YES" : "NO") << endl;

    return 0;
}