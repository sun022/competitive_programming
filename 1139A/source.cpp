#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string s;
    cin >> s;

    int ans=0;
    for(int i=0;i<N;i++){
        int d = s[i]-'0';
        if(d%2 == 0){
            ans += (i+1);
        }
    }
    cout << ans << endl;

    return 0;
}