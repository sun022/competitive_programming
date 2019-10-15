#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(2*N);
    for(int i=0;i<2*N;i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    if(A[0] == A[2*N-1]) {
        cout << -1 << endl;
        return 0;
    }

    for(auto x : A)
        cout << x << " ";
    cout << endl;

    return 0;
}