#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string s;
    cin >> s;

    vector<int> count(26,0);

    for(auto c : s)
        count[c-'a']++;

    int zero = count['z' - 'a'];
    int one = count['n' - 'a'];

    for(int k=1;k<=one;k++)
        cout << "1 ";
    for(int k=1;k<=zero;k++)
        cout << "0 ";
    cout << endl;

    return 0;
}