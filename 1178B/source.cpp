#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int num_v = 0;
    for(int i=0;i<s.size()-1;i++)
        num_v += (s[i] == 'v' && s[i+1] == 'v');

    int64_t L = 0;
    int64_t sum = 0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i] == 'v' && s[i+1] == 'v') L++;
        if(s[i] == 'o'){
            int64_t R = num_v - L;
            sum += L*R;
        }
    }
    cout << sum << endl;

    return 0;
}