#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;
    cin >> a >> b >> c;

    int z = INT_MAX;
    z = min(z, a/3);
    z = min(z, b/2);
    z = min(z, c/2);
    a -= z*3;
    b -= z*2;
    c -= z*2;

    //cout << a << " " << b << " " << c << endl;

    const vector<int> day = {0,1,2,0,2,1,0};
    vector<int> x = {a,b,c};

    int best_extra = 0;
    for(int i=0;i<7;i++){
        vector<int> x1 = x;
        int extra = 0;

        while(true){
            int req = day[(i+extra)%7];
            if(x1[req] > 0){
                x1[req]--;
            }
            else {
                break;
            }
            extra++;
        }
        best_extra = max(best_extra, extra);
    }

    cout << z*7 + best_extra << endl;

    return 0;
}