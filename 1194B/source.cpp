#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N,M;
        cin >> N >> M;

        vector<string> g(N);
        for(int i=0;i<N;i++){
            cin >> g[i];
        }

        vector<int> row_sum(N, 0);
        vector<int> col_sum(M, 0);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(g[i][j] == '*'){
                    row_sum[i]++;
                    col_sum[j]++;
                }
            }
        }

        // find max row_sum, max col_sum
        int max_row_val = 0, min_row_val = N, max_col_val = 0, min_col_val = M;
        vector<int> max_row_ind, min_row_ind, max_col_ind, min_col_ind;
        for(int i=0;i<N;i++){
            if(row_sum[i] > max_row_val){
                max_row_val = row_sum[i];
                max_row_ind.clear();
            }
            if(row_sum[i] == max_row_val)
                max_row_ind.push_back(i);

            // if(row_sum[i] < min_row_val){
            //     min_row_val = row_sum[i];
            //     min_row_ind.clear();
            // }
            // if(row_sum[i] == min_row_val)
            //     min_row_ind.push_back(i);
        }

        for(int i=0;i<M;i++){
            if(col_sum[i] > max_col_val){
                max_col_val = col_sum[i];
                max_col_ind.clear();
            }
            if(col_sum[i] == max_col_val)
                max_col_ind.push_back(i);

            // if(col_sum[i] < min_col_val){
            //     min_col_val = col_sum[i];
            //     min_col_ind.clear();
            // }
            // if(col_sum[i] == min_col_val)
            //     min_col_ind.push_back(i);
        }

        int best_cost = N*M;
        // convert to '*'s
        for(auto i : max_row_ind){
            for(auto j : max_col_ind){
                int cost = (N - max_row_val) + (M - max_col_val);
                if(g[i][j] == '.')
                    cost--;
                best_cost = min(best_cost, cost);
            }
        }
        // EDIT WHITE CROSS NOT ALLOWED
        // // convert to '.'s
        // for(auto i : min_row_ind){
        //     for(auto j : min_col_ind){
        //         int cost = min_row_val + min_col_val;
        //         if(g[i][j] == '*')
        //             cost--;
        //         best_cost = min(best_cost, cost);
        //     }
        // }
        cout << best_cost << endl;
    }
    return 0;
}