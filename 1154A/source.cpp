#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> x(4);
    cin >> x[0] >> x[1] >> x[2] >> x[3];
    sort(x.begin(), x.end());

    cout << x[3]-x[0] << " " << x[3]-x[1] << " " << x[3]-x[2] << endl;
    return 0;
}