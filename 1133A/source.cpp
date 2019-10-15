#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h1,m1,h2,m2;
    char c;
    cin >> h1 >> c >> m1; cin.ignore();
    cin >> h2 >> c >> m2; cin.ignore();

    int x = 60*h1 + m1;
    int y = 60*h2 + m2;
    if(y < x)
        y += 24*60;
    int m = (x+y)/2;
    if(m >= 24*60)
        m -= 24*60;

    cout << fixed << setprecision(2) << setfill('0');
    cout << setw(2) << m/60 << ":" << setw(2) << m%60 << endl;
    return 0;
}