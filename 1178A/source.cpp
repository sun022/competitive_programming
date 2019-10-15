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

    int sum = 0;
    for(int i=0;i<N;i++)
        sum += A[i];

    int req = (sum+2)/2;
    
    vector<int> use = {0};
    int amm = A[0];
    for(int i=1;i<N;i++){
        if(A[i]*2 <= A[0]){
            use.push_back(i);
            amm += A[i];
        }
    }

    if(amm > sum - amm){
        cout << use.size() << endl;
        for(auto x : use)
            cout << x+1 << " ";
        cout << endl;
    }
    else {
        cout << 0 << endl;
    }
    
    return 0;
}