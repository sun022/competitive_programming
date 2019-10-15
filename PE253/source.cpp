#include <bits/stdc++.h>

using namespace std;

int N = 40;

map<tuple<int,int,int,vector<int>>, double> EM;

double f(int prog, int L, int R, vector<int> S, int M){
    // cout << "f(" << prog << "," << L << "," << R << ")" << "\t";
    // if(S.size() != 0){
    //     for(auto y : S) cout << y << " ";
    // }
    // cout << endl;
    sort(S.begin(), S.end());
    int seg;
    if(prog == 0) seg = 0;
    else seg = S.size() + 1;    
    M = max(seg, M);

    
    if(EM.count({M,L,R,S})){
        return EM[{M,L,R,S}];
    }

    if(prog == N){
        double ans = M;
        EM[{M,L,R,S}] = ans;
        return ans;
    }
    double ans = 0;

    // if prog == 0, L AND R are shared otherwise seperate
    if(prog == 0){ 
        for(int h = 0; h < N; h++){
            ans += f(1, h, N-1-h, S, M);
        }        
    }
    else {
        // L points to hit in L
        for(int h = 0; h < L; h++){
            vector<int> S1 = S;
            if(L-1-h != 0) S1.push_back(L-1-h);

            ans += f(prog+1, h, R, S1, M);
        }
        // R points to hit in R
        for(int h = 0; h < R; h++){
            vector<int> S1 = S;
            if(h != 0) S1.push_back(h);
            
            ans += f(prog+1, L, R-1-h, S1, M);
        }
        // can also hit in S
        for(int i=0;i<S.size();i++){
            int s = S[i];
            for(int h = 0; h < s; h++){
                vector<int> S1 = S;
                if(h != 0) S1.push_back(h);
                if(s-1-h != 0) S1.push_back(s-1-h);
                swap(S1[i], S1.back());
                S1.pop_back();
                ans += f(prog+1, L, R, S1, M);
            }
        }
    }
    ans /= N-prog;
    EM[{M,L,R,S}] = ans;
    return ans;
}

int main(){

    f(0, 10, 10, vector<int>(), 0);
    cout << setprecision(10) << EM[{0, 10, 10, {}}] << endl;

    return 0;
}