#include <bits/stdc++.h>

using namespace std;

void f(){
    string x,y;
    cin >> x >> y;
    int N = x.size();
    int M = y.size();

    int j = 0;
    while(y[M-1-j] == '0') j++;

    int i = j;
    while(x[N-1-i] == '0') i++;

    int k = i-j;
    cout << k << endl;
    // bool carry=false;
    // for(int a=0;;a++){
    //     char c = x[a];
    //     char d = a>=k ? y[a-k] : '0';
    //     int d = carry + (c == '1') + (d == '1');

    // }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int t=1;t<=T;t++)
        f();

    return 0;
}