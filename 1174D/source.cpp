#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int K, X;
    cin >> K >> X;
    
    int N = pow(2,K);
    
    vector<int> B;

    B.push_back(0);
    for(int i=0;i<N;i++){
        int y = i^X;
        if(i <= y && i != 0 && i != X)
            B.push_back(i);
    }

    cout << B.size() - 1 << endl;
    if(B.size() != 1){
        for(int i=1;i<B.size();i++){
            cout << (B[i]^B[i-1]) << " ";
        }
        cout << endl;
    }
    return 0;
}