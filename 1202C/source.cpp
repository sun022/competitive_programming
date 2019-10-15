#include <bits/stdc++.h>

using namespace std;

void f(){
    string s; cin >> s;
    
    int h_min = 0, h_max = 0;
    int h_min_t1 = 0,h_min_t2 = 0;
    int h_max_t1 = 0,h_max_t2 = 0;

    int v_min = 0, v_max = 0;
    int v_min_t1 = 0,v_min_t2 = 0;
    int v_max_t1 = 0,v_max_t2 = 0;

    int h = 0, v=0;    
    for(int t=1;t<=s.size();t++){        
        char c = s[t-1];
        if(c == 'A') h--;
        if(c == 'D') h++;
        if(c == 'W') v++;
        if(c == 'S') v--;

        // h
        if(h < h_min){
            h_min = h;
            h_min_t1 = t;
        }
        if(h == h_min)
            h_min_t2 = t;

        if(h > h_max){
            h_max = h;
            h_max_t1 = t;
        }
        if(h == h_max)
            h_max_t2 = t;

        // v
        if(v < v_min){
            v_min = v;
            v_min_t1 = t;
        }
        if(v == v_min)
            v_min_t2 = t;

        if(v > v_max){
            v_max = v;
            v_max_t1 = t;
        }
        if(v == v_max)
            v_max_t2 = t;
    }
    bool h_reduce = ((h_min_t2 < h_max_t1 || h_max_t2 < h_min_t1) && h_max - h_min >= 2);
    bool v_reduce = ((v_min_t2 < v_max_t1 || v_max_t2 < v_min_t1) && v_max - v_min >= 2);
    //cout << h_reduce << endl;
    //cout << v_reduce << endl;

    int64_t ans = (int64_t)(1 + h_max - h_min) * (1 + v_max - v_min);
    // cout << ans << endl;
    if(h_reduce)
        ans = min(ans, (int64_t)(1 + h_max - h_min - 1) * (1 + v_max - v_min));
    if(v_reduce)
        ans = min(ans, (int64_t)(1 + h_max - h_min) * (1 + v_max - v_min - 1));
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
        f();

    return 0;
}