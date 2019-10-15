#include <bits/stdc++.h>

using namespace std;

void f(){
    int b, w;
    cin >> b >> w;

    int x = 1;
    int Y = 2; // black start

    if(w > b){
        Y++;
        swap(w,b);
    }

    vector<pair<int,int>> v;
    for(int x=1;;x++){
        v.push_back({x,Y});
        if(x%2 == 1){
            b--;
        }
        else {
            w--;
            if(b-w >= 1){
                b--;
                v.push_back({x,Y-1});
            }
            if(b-w >= 1){
                b--;
                v.push_back({x,Y+1});
            }
        }

        if((b == 0 && w == 0) || b < 0 || w < 0)
            break;
    }

    if(b == 0 && w == 0){
        cout << "YES" << endl;
        for(auto [p,q] : v)
            cout << p << " " << q << endl;
    }
    else
        cout << "NO" << endl;    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int t=1;t<=T;t++){
        f();
    }

    return 0;
}