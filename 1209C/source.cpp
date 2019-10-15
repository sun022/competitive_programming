#include <bits/stdc++.h>

using namespace std;

void f(){
    int N;
    cin >> N;
    string A;
    cin >> A;
    // cout << N << "\t" << A << endl;
    for(int D = 0; D <= 9; D++){ // 10 partitions

        int x = 0;
        int y = D;
        bool fail = false;
        string s(N, '0');
        // cout << s << endl;
        for(int i=0;i<N;i++){
            int val = A[i] - '0';
            // cerr << val << " " << x << " " << y << endl;

            if(val < D){
                if(val < x){
                    fail = true; break;
                }
                x = val;
                s[i] = '1';
            }
            else if(val > D){
                if(val < y){
                    fail = true; break;
                }
                y = val;
                s[i] = '2';
            }
            else if(val == D) {
                if(val >= y){
                    s[i] = '2';
                }
                else {
                    if(val < x){
                        fail = true; break;
                    }
                    x = val;
                    s[i] = '1';
                }
            }
        }
        if(!fail){
            cout << s << endl;
            return;
        }
    }
    cout << "-" << endl;
    return;
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