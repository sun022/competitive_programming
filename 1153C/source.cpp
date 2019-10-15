#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string s;
    cin >> s;

    int a=0,b=0;
    for(char c : s){
        if(c == '(') a++;
        if(c == ')') b++;
    }

    int x=0;
    bool fail = false;
    for(int i=0;i<N;i++){
        if(s[i] == '?'){
            if(2*a < N){
                s[i] = '('; a++;
            }
            else {
                s[i] = ')'; b++;
            }
        }

        if(s[i] == ')')
            x--;
        else
            x++;
        if(i!=N-1 && x <= 0) fail = true;
    }
    if(x!=0) fail = true;

    if(fail){
        cout << ":(" << endl;
    }
    else {
        cout << s << endl;
    }

    return 0;
}