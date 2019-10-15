#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string s;
    cin >> s;
    
    vector<int> x(10, 0);
    for(int i=0;i<N;i++){
        if(s[i] == 'L'){
            int j=0;
            while(x[j]) j++;
            x[j] = true;
        }
        else if(s[i] == 'R'){
            int j=9;
            while(x[j]) j--;
            x[j] = true;
        }
        else {
            int d = s[i]-'0';
            x[d] = 0;
        }
    }

    for(int i=0;i<10;i++)
        cout << x[i] ? "1":"0";
    cout << endl;

    return 0;
}