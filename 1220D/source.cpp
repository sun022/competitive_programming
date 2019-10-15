#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int64_t> A(N);
    vector<int> pow(N, 0);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int> pow_count(64, 0);
    
    for(int i=0;i<N;i++){
        int64_t x = A[i];
        while(x % 2 == 0){
            x/=2;
            pow[i]++;
        }
        pow_count[pow[i]]++;
    }

    int I=0;
    for(int i=0;i<64;i++){
        if(pow_count[i] > pow_count[I]) I = i;
    }

    cout << N - pow_count[I] << endl;
    for(int i=0;i<N;i++)
        if(pow[i] != I)
            cout << A[i] << " ";
    cout << endl;

    return 0;
}