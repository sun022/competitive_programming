#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N;
        string s;
        cin >> N >> s;
        // is there an 8 in the first (n-10) digits? (all except 10)
        int eight=-1; //first eight
        for(int i=0;i<N;i++){
            if(s[i] == '8'){
                eight=i;
                break;
            }
        }

        if(eight != -1 && eight + 10 < N)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
    }

    return 0;
}