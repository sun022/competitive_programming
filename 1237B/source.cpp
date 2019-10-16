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

    vector<int> B(N);
    for(int i=0;i<N;i++)
        cin >> B[i];

    
    vector<bool> exit(N+1, false);
    vector<bool> fined(N+1, false);
    int j = 0;
    for(int i=0;i<N;i++){
        int val = A[i];
        if(exit[val]) continue;

        while(true){
            exit[B[j]] = true;
            if(B[j] == val) {
                j++;
                break;
            } 
            else {
                fined[B[j]] = true;
                j++;
            }
        }
    }

    int ret = 0;
    for(int i=1;i<=N;i++)
        ret += fined[i];

    cout << ret << endl;


    return 0;
}