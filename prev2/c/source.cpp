#include <bits/stdc++.h>

using namespace std;

int sgn(int64_t x){
    if(x < 0) return -1;
    if(x == 0) return 0;
    else return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x2 -= x1;
    y2 -= y1;

    int n;
    cin >> n;

    string s;
    cin >> s;
    n = s.size();

    int64_t dx=0, dy=0;
    int64_t max_dev = 0; // edit: in correct direction
    for(int i=0;i<n;i++) {
        if(s[i] == 'U')
            dy++;
        if(s[i] == 'D')
            dy--;
        if(s[i] == 'L')
            dx--;
        if(s[i] == 'R')
            dx++;
        max_dev = max(max_dev,
            (sgn(dx) == sgn(x2) ? abs(dx) : 0) 
            + (sgn(dy) == sgn(y2) ? abs(dy) : 0)
        );
    }
    // cout << max_dev << endl;
    // cout << dx << " " << dy << endl;

    int64_t ans = 0;
    // cout << ans << " " << x2 << " " << y2 << endl;

    // waiting till ship has moved x times via wind and is within x moves
    while(true) {
        // total dist of target is |x2| + |y2|
        // maximum move in n turns is n + max_dev
        // so apply wind (|x2| + |y2|) / (2*n) times
        int64_t prog = (abs(x2) + abs(y2)) - (abs(x2 - dx) + abs(y2 - dy) - n);
        if(prog == 0) {
            cout << "-1" << endl;
            return 0;
        }

        int64_t k = (abs(x2) + abs(y2) - ans - max_dev)/(prog);
        // cout << k << " " << (abs(x2) + abs(y2) - ans) << endl;
        if(k <= 0)
            break;
        x2 -= dx*k;
        y2 -= dy*k;
        ans += k*n;
        // cout << ans << " " << x2 << " " << y2 << endl;
    }
    int extra = 0;
    while(true) {
        if(abs(x2) + abs(y2) == abs(x2 - dx) + abs(y2 - dy) - n) {
            cout << "-1" << endl;
            return 0;
        }

        if(s[extra%n] == 'U')
            y2--;
        if(s[extra%n] == 'D')
            y2++;
        if(s[extra%n] == 'L')
            x2++;
        if(s[extra%n] == 'R')
            x2--;
        // cout << ans << " " << x2 << " " << y2 << endl;
        ans++;
        if(abs(x2) + abs(y2) <= ans) {
            cout << ans << endl;
            return 0;
        }
        extra++;
    }

    return 0;
}