#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> A(N+1, 0);

    int n=0;
    for(int i=2;i<=N;i++) {
        if(A[i] != 0) continue;
        n++;
        for(int k=i; k <= N;k+=i){
            if(A[k] == 0) A[k] = n;
        }
    }
    for(int i=2;i<=N;i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}