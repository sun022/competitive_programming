#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int B,G,N;
    cin >> B >> G >> N;

    int ans = 0;
    for(int b=0;b<=B;b++){
        int g = N-b;
        if(g>=0 && g<=G)
            ans++;
    }
    cout << ans << endl;

    return 0;
}