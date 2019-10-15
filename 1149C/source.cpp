#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;

    vector<int> depth(s.size()+1);
    depth[0] = 0;
    for(int i=1;i<=s.size()+1;i++){
        char c = s[i-1];
        if(c == '(')
            depth[i] = depth[i-1] + 1;
        else
            depth[i] = depth[i-1] - 1;        
    }

    for(int i=0;i<=s.size();i++)
        cout << depth[i] << endl;

    return 0;
}