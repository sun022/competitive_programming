#include <bits/stdc++.h>

using namespace std;

char str_at(const string &a, const string &b, const int i){
    int N = a.size();
    if(i<N)
        return a[i];
    else
        return b[i-N];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    // s = string(5000, '0') + "12";
    // cout << s << endl;
    int N = s.size();

    char first = s[0];
    bool same = true;
    for(int i=0;i<s.size()/2;i++){
        if(s[i] != first){
            same = false;
            break;
        }
    }
    if(same) {
        cout << "Impossible" << endl; // catches n=1,2,3 always
        return 0;
    }

    for(int n=1;n<=s.size()/2;n++) {
        // take first n characters and split
        // s1 is s[0] to s[n-1]
        // s2 is s[n] to s[size-1]

        // s=s1 s2, s'=s2 s1

        string t = s.substr(n) + s.substr(0, n);
        // cout << t << endl;
        // require s != s'
        // require s' palindrome

        bool isPalin = true;
        for(int i=0;i<t.size()/2;i++){
            if(t[i] != t[N-1-i]){
                isPalin = false;
                break;
            }
        }
        if(!isPalin) continue;
        if(s != t) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 2 << endl;
    return 0;
}