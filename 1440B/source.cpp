#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int n; string s;
        cin >> n >> s;
        
        int i=0;
        while(!(i==n || s[i] == '>')) i++;

        int j=0;
        while(!(j==n || s[n-1-j] == '<')) j++;

        cout << min(i,j) << endl;
    }

    return 0;
}