#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t a=1;
    int64_t b=1;
    int64_t c;

    while(true){
        c = a+b;
        cout << c << endl;

        if(c >= 99194853094755497)
            break;

        a=b;
        b=c;
    }

    return 0;
}