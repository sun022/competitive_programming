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

    vector<int> B(N);
    B[N-1] = A[N-1];
    for(int i = N-2; i>=0; i--){
        B[i] = min(B[i+1] - 1, A[i]);
        if(B[i] < 0)
            B[i] = 0;
    }

    int64_t sum=0;
    for(int i=0;i<N;i++){
        sum += B[i];
    }

    cout << sum << endl;
    // for(int i=0;i<N;i++){
        
    //     cout << B[i] << " ";
    // }


    return 0;
}