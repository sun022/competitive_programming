#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int L, H;
    cin >> H >> L;
    
    long double ret = (long double)L*L - (long double)H*H;
    ret /= 2*H;

    cout << fixed << std::setprecision(9) <<ret << endl;

    return 0;
}