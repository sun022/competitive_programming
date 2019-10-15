#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int64_t s_sum=0,t_sum=0;
    cin >> N;
    multiset<pair<int,int>> S;
    multiset<int> T;
    for(int i=0;i<N;i++){
        int x; cin >> x;
        s_sum += x;
        S.insert({x,i+1});
    }
    for(int i=0;i<N;i++){
        int x; cin >> x;
        t_sum += x;
        T.insert(x);
    }
    if(s_sum != t_sum){
        cout << "NO" << endl;
        return 0;
    }

    vector<tuple<int,int,int>> ans;
    while(T.size() >= 2){
        // for(auto x : S)
        //     cout << x.first << "(" << x.second << ") ";
        // cout << endl;

        int s1 = S.begin()->first;
        int i1 = S.begin()->second;
        int t1 = *T.begin();

        int s2 = prev(S.end())->first;
        int i2 = prev(S.end())->second;
        int t2 = *prev(T.end());

        // invariant s1 <= t1 and t2 <= s2, else impossible
        if(!(s1 <= t1 && t2 <= s2)){
            cout << "NO" << endl;
            return 0;
        } 

        if(t1 - s1 < s2 - t2){
            int d = t1-s1;
            ans.push_back({i1, i2, d});
            S.erase(S.begin());
            T.erase(T.begin());

            S.erase(prev(S.end()));
            S.insert({s2 - d, i2});
        }
        else {
            int d = s2-t2;
            ans.push_back({i1, i2, d});
            S.erase(prev(S.end()));
            T.erase(prev(T.end()));

            S.erase(S.begin());
            S.insert({s1+d, i1});
        }
    }
    // for(auto x : S)
    //     cout << x.first << " ";
    // cout << endl;

    cout << "YES" << endl << ans.size() << endl;
    for(auto [i,j,d] : ans){
        cout << i << " " << j << " " << d << endl;
    }

    return 0;
}