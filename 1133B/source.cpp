#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> count(K, 0);
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        count[x%K]++;
    }

    int ret = 0;
    for(int i=0;i < K;i++) {
        int j = (K-i)%K;
        // cout << i << "," << j << endl;
        if(i==j){
            int amm = count[i]/2;
            ret += amm*2;
            count[i] -= amm*2;
        } else {
            int amm = min(count[i], count[j]);
            ret += amm*2;
            count[i] -= amm;
            count[j] -= amm;
        }
    }
    cout << ret << endl;

    return 0;
}