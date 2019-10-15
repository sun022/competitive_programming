#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string s; cin >> s;
        vector<int> count(26, 0);
        for(char c : s)
            count[c-'a']++;

        vector<int> groups;
        for(int i=0;i<26;i++)
            if(count[i] != 0)
                groups.push_back(i);

        bool veto = false;
        if(groups.size() == 2 && groups[0] + 1 == groups[1])
            veto = true;
        if(groups.size() == 3 && groups[0] + 1 == groups[1] && groups[1] + 1 == groups[2])
            veto = true;
        
        if(veto){
            cout << "No answer" << endl;
            continue;
        }

        if(groups.size() == 3 && groups[0] + 1 == groups[1]){
            string t;
            t += string(count[groups[1]], 'a' + groups[1]);
            t += string(count[groups[2]], 'a' + groups[2]);
            t += string(count[groups[0]], 'a' + groups[0]);
            cout << t << endl;
            continue;
        }
        string t;
        for(int i=1;i<groups.size();i+=2)
            t += string(count[groups[i]], 'a' + groups[i]);            
        for(int i=0;i<groups.size();i+=2)
            t += string(count[groups[i]], 'a' + groups[i]);
        cout << t << endl;        
    }

    return 0;
}