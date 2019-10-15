#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, M, T;
    cin >> N >> K >> M >> T;
    
    int x = K;
    int y = N;
    for(int t=1;t<=T;t++){
        int com, i;
        cin >> com >> i;
        if(com == 1){
            if(i <= x)
                x++;
            y++;
        }
        else if(com == 0){
            if(i<x){ // keep second part
                x -= i;
                y -= i;
            }
            else if(i >= x){ // keep first
                y = i;
            }
        }

        cout << y << " " << x << endl;
    }

    return 0;
}