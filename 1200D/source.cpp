#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<string> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int> row_black(N, 0); // counts
    vector<int> col_black(N, 0);
    int num_empty = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[i][j] == 'B'){
                row_black[i]++;
                col_black[j]++;
            }
        }    
    }
    for(int i=0;i<N;i++)
        num_empty += (row_black[i] == 0) + (col_black[i] == 0);

    vector<vector<int>> extra_row(N, vector<int>(N,0)); // for fixed row i, extra_row[i][j] is 1 if an eraser on [j : j+k-1] creates an extra row of i

    for(int i=0;i<N;i++){
        // sliding window of size K
        int contain = 0;
        for(int j=0;j<K;j++)
            contain += (A[i][j] == 'B');
        for(int j=0;;j++) { // consider window [j : j+K-1]
            extra_row[i][j] = (contain == row_black[i] && contain != 0);

            if(j+K == N)
                break;
            contain -= (A[i][j] == 'B');
            contain += (A[i][j+K] == 'B');
        }
    }

    vector<vector<int>> extra_col(N, vector<int>(N,0)); // for fixed col j, extra_col[i][j] is 1 if an eraser on [i : i+k-1] creates an extra col of j
    
    for(int j=0;j<N;j++){
        // sliding window of size K
        int contain = 0;
        for(int i=0;i<K;i++)
            contain += (A[i][j] == 'B');
        for(int i=0;;i++) { // consider window [i : i+K-1]
            extra_col[i][j] = (contain == col_black[j] && contain != 0);

            if(i+K == N)
                break;
            contain -= (A[i][j] == 'B');
            contain += (A[i+K][j] == 'B');
        }
    }
    
    

    vector<vector<int>> total_extra(N, vector<int>(N, 0));

    for(int i=0;i<N;i++){
        int sum = 0;
        for(int j=0;j<K;j++)
            sum += extra_col[i][j];
        for(int j=0;;j++) { // consider window [j : j+K-1]
            total_extra[i][j] += sum;

            if(j+K == N)
                break;
            sum += extra_col[i][j+K];
            sum -= extra_col[i][j];
        }
    }

    for(int j=0;j<N;j++){
        int sum = 0;
        for(int i=0;i<K;i++)
            sum += extra_row[i][j];
        for(int i=0;;i++) { // consider window [i : i+K-1]
            total_extra[i][j] += sum;

            if(i+K == N)
                break;
            sum += extra_row[i+K][j];
            sum -= extra_row[i][j];
        }
    }

    int max_val = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            max_val = max(max_val, total_extra[i][j]);
            //cout << total_extra[i][j];
        }
        //cout << endl;
    }

    cout << max_val + num_empty << endl;

    return 0;
}