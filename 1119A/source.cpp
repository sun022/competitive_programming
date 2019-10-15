#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    if(A[0] != A[N-1]){
        cout << N-1 << endl;
        return 0;
    }
    int ret= 0;
    for(int m=1;m<=N-2;m++){
        if(A[0] != A[m])
            ret = max(ret, m);
        if(A[N-1] != A[m])
            ret = max(ret, N-1-m);
    }
    cout << ret << endl;
    return 0;
}