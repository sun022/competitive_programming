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

    int i = N-1;
    while(A[i] == A[N-1])
        i--;
    
    cout << i+1 << endl;

    return 0;
}