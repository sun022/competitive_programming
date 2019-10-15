#include <bits/stdc++.h>

using namespace std;

bool f(){
    string s,t,p;
    cin >> s >> t >> p;
    // match letters in s to t
    // p = pool of letters
    
    vector<int> req(26,0);
    int i=0,j=0;
    while(j!=t.size()){
        if(i!=s.size() && s[i] == t[j]){
            i++;
            j++;
        }
        else {
            req[t[j]-'a']++;
            j++;
        }
    }
    if(i != s.size())
        return false;

    for(auto c : p)
        req[c-'a']--;

    for(int i=0;i<26;i++){
        if(req[i] > 0)
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        cout << (f() ? "YES" : "NO") << endl;
    }

    return 0;
}