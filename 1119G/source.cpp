#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> H(M);
    for(int i=0;i<M;i++)
        cin >> H[i];

    int sum = 0;
    for(int i=0;i<M;i++)
        sum += H[i];

    sort(H.begin(), H.end(), greater<int>());
    for(int i=0;i<M;i++)
        cout << H[i] << " ";
    cout << endl;

    // fix t
    int T = ((sum-1)/N) + 1;
    cout << "T=" << T << endl;

    for(int z=1;z<=6;z++){    
        // now pick high val such that there exists T values of greater than this value in H
        int val = H[T-1];
        cout << val << endl;
        for(int i=0;i<=T-1;i++)
            H[i] -= val;

        sort(H.begin(), H.end(), greater<int>());
        for(int i=0;i<M;i++)
            cout << H[i] << " ";
        cout << endl;

    }
    return 0;
}