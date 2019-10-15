#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> test = {{1,0,0}, {0, 0, 1}, {0, 0, 0}};
int test_query(int a, int b, int c, int d){
    return test[a-1][b-1] == test[c-1][d-1];
}

int opp(int x){
    if(x == 1) return 0;
    if(x == 0) return 1;
    if(x == 2) return 3;
    if(x == 3) return 2;
    if(x == 4) return 5;
    if(x == 5) return 4;
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N,-1));
    A[0][0] = 1;
    A[0][1] = 4;
    A[1][0] = 2;
    A[N-1][N-1] = 0;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            // if((i+j)%2 != 0) continue;
            if(A[i][j] != -1) continue;

            int i1,j1;
            if(j-2 >= 0){
                i1 = i;
                j1 = j-2;
            }
            else if(i-2 >= 0){
                i1 = i-2;
                j1 = j;
            }
            else {
                i1 = i-1;
                j1 = j-1;
            }

            // cout << "? " << i1+1 << " " << j1+1 << " " << i+1 << " " << j+1 << endl;            
            // int z; cin >> z;
            int z = test_query(i1 + 1, j1 + 1, i + 1, j + 1);

            if(z == 1)
                A[i][j] = A[i1][j1];
            else
                A[i][j] = opp(A[i1][j1]);
        }
    }

    // cout << "? 1 2 2 3" << endl;
    // int z; cin >> z;
    int z = test_query(1,2,2,3);
    
    int a1 = A[0][1]; // 4
    int a2 = opp(A[0][1]); // 5
    int b1 = (z == 1) ? A[1][2] : opp(A[1][2]);
    int b2 = opp(b1);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[i][j] == a1)
                A[i][j] = b1;
            if(A[i][j] == a2)
                A[i][j] = b2;
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout << A[i][j];
    //     }
    //     cout << endl;
    // }

    // now to use final 2 query for consolidate black and white squares

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!(i+2 < N && j+1 < N)) continue;
            if(!(A[i][j+1] == A[i+1][j] && A[i+1][j+1] == A[i+2][j])) continue;

            if(A[i][j] == A[i+1][j+1] && A[i+1][j] == A[i+2][j+1]){
                cout << "A" << endl;
            }
            else if(A[i][j] != A[i+1][j+1] && A[i+1][j] != A[i+2][j+1]){
                cout << "B" << endl;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!(j+2 < N && i+1 < N)) continue;
            if(!(A[i+1][j] == A[i][j+1] && A[i+1][j+1] == A[i][j+2])) continue;

            if(A[i][j] == A[i+1][j+1] && A[i][j+1] == A[i+1][j+2]){
                // cout << "C" << endl;
                cout << "? " << i+1 << " " << j+1 << " " << i+2 << " " << j+3 << endl;
                int z; cin >> z;
                if(z) convert_all(A[i+1][j], A[i+1][j+1]);
                
            }
            else if(A[i][j] != A[i+1][j+1] && A[i][j+1] != A[i+1][j+2]){
                // cout << "D" << endl;
                cout << "? " << i+1 << " " << j+1 << " " << i+2 << " " << j+3 << endl;
                int z; cin >> z;
            }
        }
    }


    return 0;
}