#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int i=0, j = s.size()-1;
    string t;
    while(i<j){
        // cout << i << " " << j << endl;
        // dist >= 1
        if(s[i] == s[j]){
            t += s[i];
            i++;
            j--;
            continue;
        }
        if(j-i == 1) break;

        // one of these 3 cases is always true:
        // s[i] == s[j-1]
        // s[i+1] == s[j]
        // s[i+1] == s[j-1]

        // fine for dist >= 2
        if(s[i] == s[j-1]){
            t += s[i];
            i++;
            j-=2;
            continue;            
        }
        if(s[i+1] == s[j]){
            t += s[i+1];
            i+=2;
            j-=1;
            continue;            
        }
        i++;
        j--;
    }

    cout << t;
    if(i<=j)
        cout << s[i];
    for(int i=t.size()-1;i>=0;i--)
        cout << t[i];
    cout << endl;

    return 0;
}