#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    vector<string> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
    
    vector<vector<int>> X(26, vector<int>(26, 0));
    bool fail = false;

    for(int i=0;i<N-1;i++){
        // process A[i], A[i+1] pair
        string s = A[i];
        string t = A[i+1];

        int j = 0;
        while(j!=s.size() && j!=t.size() && s[j] == t[j])
            j++;
        if(j == s.size()){ // s is substr of t
        }
        else if(j == t.size()){ // t is substr of s
            fail = true;
        }
        else {
            int a = s[j]-'a';
            int b = t[j]-'a';
            // character s[j] must be less than t[j]
            if(X[a][b] == 1) fail = true;
            X[a][b] = -1;
            if(X[b][a] == -1) fail = true;
            X[b][a] = 1;
        }
    }

    if(fail){
        cout << "Impossible" << endl;
        return 0;
    }
    
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            cerr << X[i][j] << " ";
        }
        cerr << endl;
    }

    vector<bool> used(26, false);
    string out;

    for(int k=0;k<26;k++){
        // find character than is <= all other
        int next = -1;
        for(int i=0;i<26;i++){
            if(used[i]) continue;
            bool less = true;
            for(int j=0;j<26;j++){
                if(used[j]) continue;
                if(X[i][j] > 0)
                    less = false;
            }
            if(less){
                next = i;
                break;
            }
        }
        if(next == -1){
            fail = true;
            break;
        }
        used[next]=true;
        out += (char)('a' + next);

    }


    if(fail){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << out << endl;
    return 0;
}