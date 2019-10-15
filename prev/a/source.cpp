#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, V;
    cin >> N >> V;
    vector<int> A(N);
    
    int rem = N-1;
    int fuel = 0;
    int cost = 0;
    for(int n=1;n<=N;n++){
        if(rem > 0) {
            // fill up tank
            int buy = min(rem, V - fuel);
            fuel += buy;
            rem -= buy;
            cost += buy*n;
            // cout << n << " " << buy << endl;
        }
        fuel--;
    }
    cout << cost << endl;

    return 0;
}