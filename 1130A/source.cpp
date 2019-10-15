#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int p=0,n=0,z=0;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        if(x > 0) p++;
        else if(x < 0) n++;
        else z++;
    }

    if(p >= n + z)
        cout << "1" << endl;
    else if(n >= p + z)
        cout << "-1" << endl;
    else
        cout << "0" << endl;

    return 0;
}