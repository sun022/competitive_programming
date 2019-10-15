#include <bits/stdc++.h>

using namespace std;

string flip_str(const string s){
    string t = "";
    for(auto c : s)
        t += (c == 'S') ? 'E' : 'S';
    return t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int tt=1;tt<=T;tt++){
        int N;
        cin >> N;
        string P;
        cin >> P;
        
        // garuantee P[0] = 'E'
        bool flip = (P[0] != 'E');
        if(flip)
            P = flip_str(P);

        string t="";
        if(P[P.length() - 1] == 'S'){
            // then go all S then all E
            t = string(N-1, 'S') + string(N-1, 'E');
        }
        else if(P[P.length() - 1] == 'E'){
            // then there must be a row where Lydia did 2 S in a row
            int row=0;
            for(int i=0;i<P.size()-1;i++){
                if(P[i] == 'S'){
                    row++;
                    t+='S';
                    if(P[i+1] == 'S')
                        break;
                }                
            }
            t += string(N-1, 'E');
            t += string(N-1-row, 'S');            
        }
        if(flip) t = flip_str(t);
        cout << "Case #" << tt << ": " << t << endl;
    }

    return 0;
}