#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    int oddKey=0, evenKey=0, oddChest=0, evenChest=0;
    for(int i=0;i<N;i++){
        int x; cin >> x;
        if(x%2 == 1) oddChest++;
        else evenChest++;
    }

    for(int i=0;i<M;i++){
        int x; cin >> x;
        if(x%2 == 1) oddKey++;
        else evenKey++;
    }

    cout << min(oddKey, evenChest) + min(evenKey, oddChest) << endl;

    return 0;
}