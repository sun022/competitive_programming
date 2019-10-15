#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c,d;
    cin >> a >> b >> c >> d;

    if(a != d){
        cout << 0 << endl; return 0;
    }
    if(c > 2*a) {
        cout << 0 << endl; return 0;
    }

    cout << 1 << endl; return 0;
    return 0;
}