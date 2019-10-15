#include <bits/stdc++.h>

using namespace std;

int f(int x){
    return x*(x-1)/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(26, 0);
    for(int i=0;i<N;i++){
        string s; cin >> s;
        A[s[0]-'a']++;
    }

    int ans=0;
    for(int i=0;i<26;i++){
        ans += f(A[i]/2);
        ans += f(A[i] - A[i]/2);
    }
    cout << ans << endl;
    return 0;
}