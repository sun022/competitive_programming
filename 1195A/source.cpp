#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> req(K, 0);

    for(int i=0;i<N;i++) {
        int x;
        cin >> x; x--;
        req[x]++;
    }

    int res=0;
    int odd=0;
    for(int k=0;k<K;k++){
        res += 2*(req[k]/2);
        odd += req[k]%2;
    }

    res += (odd%2 == 0 ? odd/2 : (odd+1)/2);
    cout << res << endl;
    return 0;
}