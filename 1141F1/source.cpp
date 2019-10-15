#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
        
    vector<int> S(N+1, 0);
    for(int i=1;i<=N;i++){
        S[i] = S[i-1] + A[i-1];
    }


    unordered_map<int, vector<pair<int,int>>> s;
    for(int i=0;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            s[S[j]-S[i]].push_back({i, j});
        }
    }
    vector<pair<int,int>> q;

    int best = -1;
    int bestVal = 0;
    for(auto &x : s){
        //cout << x.first << ":" << x.second.size() << endl;
        sort(x.second.begin(), x.second.end(), [](auto i,auto j){return i.second < j.second;});
        int count=0;
        int cur=0;
        for(auto p : x.second){
            // cout << p.first << "->" << p.second << endl;
            if(p.first >= cur) {
                cur = p.second;
                count++;
            }
        }
        if(count > bestVal){
            best = x.first;
            bestVal = count;
        }
        // cout << count << endl;
        // q.push_back({x.first, x.second});
    }

    int cur=0;
    cout << bestVal << endl;
    // sort(s[best].begin(), s[best].end(), [](auto i,auto j){return i.second < j.second;});
    for(auto &p : s[best]){
        if(p.first >= cur) {
            cout << p.first+1 << " " << p.second << endl;
            cur = p.second;
        }
    }

    
    return 0;
}