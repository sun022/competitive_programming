#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for(int i=0;i<N;i++)
        cin >> A[i] >> B[i];

    int ans = 0;
    int prevA=0,prevB=0;
    for(int i=0;i<N;i++){
        int x = max(prevA, prevB);
        int y = min(A[i], B[i]);
        ans += max(y-x+1, 0);

        prevA = A[i];
        prevB = B[i];
        if(prevA <= prevB) prevA++;
        else prevB++;
    }
    cout << ans << endl;
    return 0;
}