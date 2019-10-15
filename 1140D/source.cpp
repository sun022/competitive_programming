#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    int64_t ret=0;
    for(int x=3;x<=N;x++){
        ret += x*(x-1);
    }
    cout << ret << endl;
    return 0;
}