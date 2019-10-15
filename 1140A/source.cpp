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

    int m = -1;
    int days=0;
    for(int i=0;i<N;i++){
        m = max(m, A[i]);
        if(m == i)
            days++;
    }
    cout << days << endl;
    return 0;
}