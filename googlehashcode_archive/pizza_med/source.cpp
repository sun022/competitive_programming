#include <bits/stdc++.h>

using namespace std;

int N, M, L, H;
vector<vector<int>> A;

bool check(int i1, int i2, int j1, int j2){
    // cout << "check(" << i1 << "," << i2 << "," << j1 << "," << j2 << ")" << endl;
    int a=0;
    for(int i=i1; i < i2; i++){
        for(int j=j1; j < j2; j++){
            a+=A[i][j];
        }
    }
    int size = (i2-i1)*(j2-j1);
    return a>=L && size - a >= L;
}

int f(pair<int,int> x, pair<int,int> y, bool validate_print){
    int fin_score = 0;
    vector<tuple<int,int,int,int>> slice;
    int col_no=0;
    for(int j1=0; j1 != M;){
        int W = min(12, M - j1);
        if(col_no == x.first)
            W = x.second;
        if(col_no == y.first)
            W = y.second;
        col_no++;

        vector<int> dp(N+1, 0); // best for first N rows
        vector<int> dp_how(N+1, -2);
        vector<vector<int>> dp1_final_how(N+1);
        for(int i=1;i<=N;i++) { // find dp[i]            
            dp[i] = dp[i-1]; // can also have discard as base case
            dp_how[i] = -1; // means discarded gap of 1
            for(int h = 1; h <= 12; h++) {
                if(h > i) continue;

                vector<int> dp1(W+1, 0);
                vector<int> dp1_how(W+1, -2);
                for(int j=1;j<=W;j++){
                    dp1[j] = dp1[j-1]; // can also have discard as base case
                    dp1_how[j] = -1; // means discarded gap of 1
                    for(int w = 8/h; w <= 12/h; w++){
                        if(w > j) continue;
                        if(w*h < 8) continue;
                        if(check(i-h, i, j1 + j-w, j1 + j)){
                            if(dp1[j-w] + w*h > dp1[j]) {
                                dp1[j] = dp1[j-w] + w*h;
                                dp1_how[j] = w;
                            }
                        }
                    }
                    // cout << "dp1[" << j << "]= " << dp1[j] << endl;
                }
                // cout << "h = "<< h << " scored " << dp1[W] << " making " << dp[i-h] + dp1[W] << endl;      
                if(dp[i-h] + dp1[W] > dp[i]){
                    dp[i] = dp[i-h] + dp1[W];
                    dp_how[i] = h;
                    dp1_final_how[i] = dp1_how;
                }
            }
            // cout << "dp[" << i << "]= " << dp[i] << "(" << dp_how[i] << ")" << endl;        
        }
        int block_score = dp[N];

        // reverse to extract soln
        int i=N;
        while(i!=0){
            cerr << dp_how[i] << ":\t";
            if(dp_how[i] < 0){
                cerr << "dp_how[" << i << "]=" << dp_how[i] << endl;
                i--;
                continue;
                // exit(0);
            }
            int j = W;
            while(j!=0) {
                cerr << dp1_final_how[i][j] << " ";
                if(dp1_final_how[i][j] < 0) {
                    j--;
                    continue;
                }
                slice.push_back({i-dp_how[i], i, j1+j-dp1_final_how[i][j], j1+j});
                bool sanity = check(i-dp_how[i], i, j1+j-dp1_final_how[i][j], j1+j);
                if(!sanity){cerr << "!!!" << endl;
                    exit(0);
                }
                j -= dp1_final_how[i][j];                
            }
            i-=dp_how[i];
            cerr << endl;
        }

        cerr << j1 << "\t" << block_score << "\t" << setprecision(4) << (double)100*block_score/(N*W) << endl;
        j1 += W;
        fin_score += block_score;
    }
    cerr << "final_score:" << fin_score << endl;
    
    // checker at end as well as output
    if(!validate_print){
        return fin_score;
    }
    vector<vector<bool>> used(N, vector<bool>(M, false));
    int score = 0;
    cout << slice.size() << endl;
    for(auto [r1, r2, c1, c2] : slice){
        r2--; c2--;
        cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;

        int a = 0, b=0;
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                if(used[i][j]) cerr << "FAIL: used already" << endl;
                used[i][j] = true;
                score++;
                if(A[i][j]) a++;
                else b++;
            }
        }
        if(a < L) cerr << "FAIL: a<L" << endl;
        if(b < L) cerr << "FAIL: b<L" << endl;
        if(a+b > H) cerr << "FAIL: a+b>H" << endl;
    }
    cerr << "checked score:" << score << endl;
    return score;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> L >> H;
    A = vector<vector<int>> (N, vector<int>(M, 0));
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<M;j++){
            if(s[j]=='T')
                A[i][j] = 1;        
        }
    }
    
    for(int i=0;i<21;i++){
        int f_i = f({i,10}, {-1,-1}, false);
        cout << "f[" << i << "]=" << f_i << endl;
    }

    pair<int,int> best_ij={0,0};
    int best_score=0;
    for(int i=0;i<21;i++){
        for(int j=i+1;j<21;j++){
            int f_ij = f({i,11}, {j,11}, false);
            cout << "f[" << i << "," << j << "]=" << f_ij << endl;
            if(f_ij > best_score){
                best_score = f_ij;
                best_ij = {i,j};
            }
        }
    }
    cout << "f[" << best_ij.first << "," << best_ij.second << "]=" << best_score << endl;
    f({best_ij.first,11}, {best_ij.second,11 }, true);
    return 0;
}