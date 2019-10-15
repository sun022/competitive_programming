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
        if(A[i] < 0) A[i]*=-1;
    }

    sort(A.begin(), A.end());
    // for(int i=0;i<A.size();i++)
    //     cout << A[i] << " ";
    // cout << endl;

    int64_t ans = 0;
    for(auto it = A.begin(); it != A.end(); ++it){
        // A[i] will be X
        // count how many j>=i have A[j] <= 2*A[i]

        auto it1 = upper_bound(it, A.end(), 2*(*it));
        // cout << it1-it-1 << endl;
        ans += it1-it-1;
    }
    cout << ans << endl;

    return 0;
}