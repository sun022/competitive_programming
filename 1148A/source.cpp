#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t A, B, C;
    cin >> A >> B >> C;
    
    int64_t m = min(A,B);
    A-=m;
    B-=m;
    C+=m;
    int64_t ans = 2*C + ((A+B)>=1 ? 1 : 0);
    cout << ans << endl;

    return 0;
}