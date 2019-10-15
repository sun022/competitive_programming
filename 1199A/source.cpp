#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    for(int i=0;i<N;i++){
        bool nsr = true;
        int val = A[i];
        for(int x=1;x<=X;x++){
            if(i-x >= 0 && A[i-x] < val) nsr = false;
        }
        for(int y=1;y<=Y;y++){
            if(i+y < N && A[i+y] < val) nsr = false;
        }

        if(nsr){
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}