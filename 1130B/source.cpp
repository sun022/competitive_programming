#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(2*N);
    for(int i=0;i<2*N;i++){
        cin >> A[i]; A[i]--;
    }

    vector<vector<int>> z(N);
    for(int i=0;i<2*N;i++){
        z[A[i]].push_back(i);
    }

    int a=0;int b=0;
    int64_t ans=0;
    for(int i=0;i<N;i++){
        //cout << z[i].size() << endl;
        // cout << z[i][0] << " " << z[i][1] << endl;
        int c=z[i][0];
        int d=z[i][1];
        ans += min(abs(a-c) + abs(b-d), abs(a-d) + abs(b-c));
        a = c;
        b = d;
    }
    cout << ans << endl;

    return 0;
}