#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int d;
    cin >> d;

    int n = 666;
    int a = 0;
    int x;
    for(x = 1;;x++){
        if((1332*x - d) % 1999 == 0){
            a = (1332*x - d) / 1999;
            if(a < x)
                break;
        }
    }

    //cout << x << " " << a << endl;
    int rem;

    rem = x-a;
    for(int i=0;i<n-1;i++){
        rem -= (x-a)/n;
        cout << ((x-a)/n) << " ";
    }
    cout << rem << " ";

    rem = -x;
    for(int i=0;i<n-1;i++){
        rem -= -x/n;
        cout << (-x/n) << " ";
    }
    cout << rem << " ";
    
    rem = x;
    for(int i=0;i<n;i++){
        rem -= x/n;
        cout << (x/n) << " ";
    }
    cout << rem << " ";
    

    return 0;
}