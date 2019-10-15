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

    bool odd=false,even=false;
    for(auto x : A){
        if(x % 2 == 0) even=true;
        else odd=true;
    }

    if(even && odd) sort(A.begin(), A.end());
    
    for(auto x : A){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}