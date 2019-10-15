#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
 
    vector<int> Y(N+1), X(N+1);
    // split by y
    for(int i=1;i<=N;i++){
        cout << "? 1 1 " << N << " " << i << endl;
        cin >> Y[i];
    }

    // split by x
    for(int i=1;i<=N;i++){
        cout << "? 1 1 " << i << " " << N << endl;
        cin >> X[i];
    }

    // at some point it may go even -> odd -> even
    int x1 = INT_MAX;
    int x2 = INT_MIN;
    for(int i=1;i<=N;i++){
        if(X[i] % 2 != 1) continue;
        x1 = min(x1, i);
        x2 = max(x2, i);
    }

    int y1 = INT_MAX;
    int y2 = INT_MIN;
    for(int i=1;i<=N;i++){
        if(Y[i] % 2 != 1) continue;
        y1 = min(y1, i);
        y2 = max(y2, i);
    }

    if(x1 != INT_MAX && y1 != INT_MAX){
        x2++; y2++;
        // x coords are x1, x2
        // y coords are y1, y2
        // 2 combinations left
        cout << "? 1 1 " << x1 << " " << y1 << endl;
        int ret;
        cin >> ret;
        if(ret % 2 == 1)
            cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        else
            cout << "! " << x1 << " " << y2 << " " << x2 << " " << y1 << endl;        
    }
    else if(x1 != INT_MAX && y1 == INT_MAX){
        x2++;
        // x coords are x1, x2
        // y coords are same
        int y1 = 1, y2 = N+1;
        while(y1 != y2){
            int m = (y1+y2)/2;
            cout << "? 1 1 " << x1 << " " << m << endl;
            int ret;
            cin >> ret;
            if(ret % 2 == 1)
                y2 = m;            
            else
                y1 = m + 1;            
        }
        cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }    
    else if(y1 != INT_MAX && x1 == INT_MAX){
        y2++;
        // y coords are y1, y2+1
        // x coords are same
        int x1 = 1, x2 = N;
        while(x1 != x2){
            int m = (x1+x2)/2;
            cout << "? 1 1 " << m << " " << y1 << endl;
            int ret;
            cin >> ret;
            if(ret % 2 == 1)
                x2 = m;            
            else
                x1 = m + 1;
        }
        cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    else {
        
    }

    return 0;
}