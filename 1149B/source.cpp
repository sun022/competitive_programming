#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;

    vector<int> label(N,0);
    vector<int> next(4,0);

    for(int q=1;q<=Q;q++){
        char opp;
        int i;
        cin >> opp >> i;
        if(opp == '+'){
            char c;
            cin >> c;
            
        }
        else if(opp == '-') {

        }
    }

    return 0;
}