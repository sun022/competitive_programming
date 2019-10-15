#include <bits/stdc++.h>

using namespace std;

int x_tar, y_tar;
int N;
int dx,dy,dt;
string s;

int f(int x_mult, int y_mult){
    long double grad = -(long double)x_mult*dx/dt -(long double)y_mult*dy/dt;
    cout << "grad:" << grad << endl;
    if(grad == 1){
        // cout << "wrong way" << endl;
        return -1;
    }
    int dx1=0,dy1=0,dt1=0;
    long double dip = 0;
    for(int i=0;i<N;i++){
        if(s[i] == 'U') dy1--;
        if(s[i] == 'D') dy1++;
        if(s[i] == 'L') dx1++;
        if(s[i] == 'R') dx1--;
        dt1++;
        dip = max(dip, dx1+dy1-grad*dt1);
        // cout <<  dx1+dy1 << "\t" << grad*dt1 << endl;
    }
    cout << "dip:" << dip << endl;

    // solve for t
    // t = x0 + (dx/dt).t - dip
    // t.(1 - dx/dt) = x0 - dip
    // t = (x0 - dip)/(1 - dx/dt)

    // has 1 soln as long as dx/dt != 1

    long double t = (long double)(x_mult*x_tar + y_mult*y_tar - dip)/(1 - grad);
    cout << "t:" << t << endl;
    int64_t k = (int64_t)floor(t) % dt;
    cout << "k:" << k << endl;

    int x_rem = x_mult*x_tar - k*dx;
    int y_rem = y_mult*y_tar - k*dy;
    cout << "rem: "<< x_rem << "," << y_rem << endl;
    int64_t t_tot = k*dt;

    for(int i=0;i<N;i++){
        if(x_rem + y_rem <= t_tot && abs(x_rem) == x_rem * x_mult && abs(y_rem) == y_rem * y_mult) {
            // cout << "completed in " << t_tot << endl;
            return t_tot;
        }
        if(s[i] == 'U') y_rem--;
        if(s[i] == 'D') y_rem++;
        if(s[i] == 'L') x_rem++;
        if(s[i] == 'R') x_rem--;
        t_tot++;
    }
    cout << "??" << endl;
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> N;
    cin >> s;

    // target amount to travel
    x_tar = x2-x1;
    y_tar = y2-y1;

    dx=0;
    dy=0;
    dt=0;
    for(int i=0;i<N;i++) {
        if(s[i] == 'U') dy++;
        if(s[i] == 'D') dy--;
        if(s[i] == 'L') dx--;
        if(s[i] == 'R') dx++;
        dt++;
    }

    int ret = -1;
    for(int a : {1,-1}){
        for(int b : {1,-1}){
            int f_ab = f(a,b);
            if(ret == -1) ret = f_ab;
            else {
                if(f_ab != -1) {
                    ret = min(ret, f_ab);
                }
            }
        }
    }

    cout << ret << endl;

    return 0;
}