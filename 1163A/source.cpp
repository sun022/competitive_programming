#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    if(M == 0){
        cout << 1 << endl;
        return 0;
    }

    int rem = N-M;

    vector<bool> present(N, false);
    for(int i=0;i<N;i++){
        if(rem == 0) continue;
        if(N-i == rem || i%2 == 0){
            present[i] = true;
            rem--;
        }        
    }

    int blocks=0;
    for(int i=0;i<N;i++){
        if(present[i] && !present[(i+1)%N]) blocks++;
        //cout << present[i] << " ";
    }
    //cout << endl;

    cout << blocks << endl;

    return 0;
}