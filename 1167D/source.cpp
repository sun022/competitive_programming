#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string s;
    cin >> s;

    vector<int> col(N);

    int r=0; // 0
    int b=0; // 1
    // mantain r == b OR r == b+1
    for(int i=0;i<N;i++){
        if(s[i] == '('){
            if(r == b){
                col[i] = 0;
                r++;
            }
            else {
                col[i] = 1;
                b++;
            }
        }
        else {
            if(r == b){
                col[i] = 1;
                b--;
            }
            else {
                col[i] = 0;
                r--;
            }
        }
    }

    for(auto x : col)
        cout << x;
    cout << endl;

    return 0;
}