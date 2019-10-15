#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    // vector<int> count(26,0);
    // for(auto c: s){
    //     count[c-'a']++;
    // }

    // int i = 0;
    // while(count[i] == 0) i++;

    // for(auto c : s){
    //     if(c-'a' == i)
    //         cout << "Mike" <<endl;
    //     else
    //         cout << "Ann" << endl;
    // }

    int least = INT_MAX;
    for(auto c : s){
        int d = c-'a';

        if(d > least){
            cout << "Ann" << endl;
        }
        else if( d <= least) {
            least = d;
            cout << "Mike" << endl;
        }
    }

    return 0;
}