#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int N = s.size();
    vector<bool> A(N);
    for(int i=0;i<N;i++)
        A[i] = s[i]-'0';
    
    vector<int> mid(N, INT_MAX); // minimum triple with i in middle
    for(int i=0;i<N;i++){
        int x = 1;
        int x_max = min(i, N-1-i);
        while(x<=x_max && (A[i-x] != A[i] || A[i+x] != A[i]))
            x++;
        if(x <= x_max)
            mid[i] = x;
    }
    vector<int> left(N, INT_MAX); // minimum triple with i on left (not really)
    for(int i=0;i<N;i++){
        if(mid[i] == INT_MAX) continue;
        int x = mid[i];
        left[i-x] = min(left[i-x], x);
    }

    vector<int> L(N, INT_MAX); // minimum elements in range [L, ?] so that range contains a triple
    for(int i=N-1;i>=0;i--){
        if(i+1 != N && L[i+1] != INT_MAX)
            L[i] = L[i+1] + 1;
        if(left[i] != INT_MAX)
            L[i] = min(L[i], 2*left[i]);        
    }

    int64_t ret=0;
    for(int i=0;i<N;i++){
        // cout << i << ":\t" << L[i] << endl;
        if(L[i] != INT_MAX)
            ret += N-(i+L[i]);
    }

    cout << ret << endl;

    return 0;
}