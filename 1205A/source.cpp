#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    if(N % 2 == 0){
        cout << "NO" << endl;
        return 0;
    }

    vector<int> A(2*N);

    for(int i=0;i<N;i++){
        A[i] = 2*i;
        A[i+N] = 2*i + 1;
        if(i % 2 == 0)
            swap(A[i], A[i+N]);
    }

    cout << "YES" << endl;
    for(int i=0;i<2*N;i++) 
        cout << A[i] + 1 << " ";
    cout << endl;

    return 0;
}