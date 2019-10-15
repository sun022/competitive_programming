#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> ret;
vector<int> A,B;
void s(int a, int b){
    ret.push_back({a+1,b+1});
    swap(B[A[a]],B[A[b]]);
    swap(A[a], A[b]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    A = vector<int>(N);
    B = vector<int>(N); // B[i] is index of i in A, ie A[B[i]] = i
    for(int i=0;i<N;i++){
        cin >> A[i]; A[i]--;
        B[A[i]] = i;
    }

    int D = N/2;
    for(int i=1;i<=N-1;i++){
        // for(int j=0;j<N;j++)
        //     cout << A[j] << " ";
        // cout << endl;
        int x = B[i];
        int y = A[x];
        if(x == y) continue;
        if(abs(x-y) >= D){
            s(x, y);
            continue;
        }
        if(x < D && y < D){
            s(x, N-1);
            s(N-1, y);
        }
        else if (x >= D && y >= D) {
            s(x, 0);
            s(0, y);
        }
        else if (x < D && y >= D) {
            s(x, N-1);
            s(N-1, 0);
            s(0, y);
        }
        else if (x >= D && y < D) {
            s(x, 0);
            s(0, N-1);
            s(N-1, y);
        }
    }
    // for(int i=0;i<N;i++)
    //      cout << A[i] << " ";
    // cout << endl;    

    cout << ret.size() << endl;
    for(auto p : ret){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}