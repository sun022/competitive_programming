#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> val(N);

    bool fail = false;
    int d = 0;
    int u = 0;
    for(int i=0;i<N;i++){
        int prev = (i==0 ? 0 : val[i-1]);
        
        if(S[i] == ')') d++;
        else u++;

        if(S[i] == ')' && d==1)
            val[i] = prev;
        else
            val[i] = prev + (S[i]=='(' ? 1 : -1);
            
        // cout << val[i] << endl;
        if(val[i] < 0) fail = true;
    }
    if(d != u) fail = true;

    cout << (fail ? "No":"Yes") << endl;
}