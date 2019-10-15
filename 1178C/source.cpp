#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int W, H;
    cin >> W >> H;

    // ans = 4 * 2^(W+H-2)

    int64_t ans = 4;
    for(int k=0;k<W+H-2;k++)
        ans = ans * 2 % 998244353;
    cout << ans << endl;

    return 0;
}