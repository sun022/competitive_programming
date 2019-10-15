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

    L = 4;
    H = 12; //size 8 to 12

    

    // int B=12;
    // int j1;
    // for(j1 = 0; j1+B <= M; j1 += B){
    //     vector<int> dp(N+1, 0); // best for first N rows
    //     for(int i=1;i<=N;i++) { // find dp[i]
    //         for(int h = 1; h<=4; h++) {
    //             int w = B/h;
    //             if(h > i) continue;

    //             int score=0;
    //             for(int hx=0;hx<h;hx++){
    //                 if(check(i - h, i, j1 + hx*w , j1 + hx*w + w)){
    //                     score += B;
    //                 }
    //             }
    //             dp[i] = max(dp[i], dp[i-h] + score);
    //             //cout << "h= "<< h << " scored " << score << " making " << dp[i-h] + score << endl;      
    //         }
    //         // cout << "dp[" << i << "]= " << dp[i] << endl;
    //     }
    //     int block_score = dp[N];
    //     cout << j1 << "\t" << block_score << "\t" << setprecision(4) << (double)100*block_score/(N*B) << endl;
    // }

    // cout << endl << "extra columns:" << M-j1 << endl;

    int fin_score = 0;
    vector<tuple<int,int,int,int>> slice;
    for(int j1=0; j1 != M;){
        int W = min(12, M - j1);
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<W;j++)
        //         cout << A[i][j];
        //     cout << endl;
        // }

        vector<int> dp(N+1, 0); // best for first N rows
        vector<int> dp_how(N+1, -1);
        vector<vector<int>> dp1_final_how(N+1);
        for(int i=1;i<=N;i++) { // find dp[i]
            for(int h = 1; h <= 12; h++) {
                if(h > i) continue;

                vector<int> dp1(W+1, 0);
                vector<int> dp1_how(W+1, -2);
                for(int j=1;j<=W;j++){
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
            cout << dp_how[i] << ":\t";
            int j = W;
            while(j!=0){
                cout << dp1_final_how[i][j] << " ";
                if(dp1_final_how[i][j] < 0) {
                    // no more in this section?
                    break;
                }
                slice.push_back({i-dp_how[i], i, j1+j-dp1_final_how[i][j], j1+j});
                bool sanity = check(i-dp_how[i], i, j1+j-dp1_final_how[i][j], j1+j);
                if(!sanity){cerr << "!!!" << endl;
                    exit(0);
                }
                j -= dp1_final_how[i][j];                
            }
            i-=dp_how[i];
            cout << endl;
        }

        cerr << j1 << "\t" << block_score << "\t" << setprecision(4) << (double)100*block_score/(N*W) << endl;
        j1 += W;
        fin_score += block_score;
    }
    cerr << "final_score:" << fin_score << endl;
    
    // checker at end as well as output
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
    return 0;
}