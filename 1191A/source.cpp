#include <bits/stdc++.h>

using namespace std;

int hp(int x){
    x%=4;
    if(x==1) return 0;
    if(x==3) return 1;
    if(x==2) return 2;
    if(x==0) return 4;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> x;

    int bestAmm = 0;
    int bestRes = hp(x);
    
    if(hp(x+1) < bestRes){
        bestAmm = 1;
        bestRes = hp(x+1);
    }

    if(hp(x+2) < bestRes){
        bestAmm = 2;
        bestRes = hp(x+2);
    }

    char c = 'A' + bestRes;

    cout << bestAmm << " " << c << endl;


    return 0;
}