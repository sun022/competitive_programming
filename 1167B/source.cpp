#include <bits/stdc++.h>

using namespace std;

vector<int> A = {4, 8, 15, 16, 23, 42};

int test_query(int i, int j){
    i--; j--;
    i = (i+3)%6;
    j = (j+3)%6;
    return A[i]*A[j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> r(4);

    cout << "? 1 2" << endl;
    cin >> r[0];
    cout << "? 1 3" << endl;
    cin >> r[1];
    cout << "? 4 5" << endl;
    cin >> r[2];
    cout << "? 4 6" << endl;
    cin >> r[3];

    // r[0] = test_query(1,2);
    // r[1] = test_query(1,3);
    // r[2] = test_query(4,5);
    // r[3] = test_query(4,6);

    vector<int> v(6);
    iota(v.begin(), v.end(), 0);

    do {
        // i-th char is A[v[i]]

        if(A[v[0]]*A[v[1]] != r[0]) continue;
        if(A[v[0]]*A[v[2]] != r[1]) continue;
        if(A[v[3]]*A[v[4]] != r[2]) continue;
        if(A[v[3]]*A[v[5]] != r[3]) continue;

        cout << "! ";
        for(int i=0;i<6;i++){
            cout << A[v[i]] << " ";
        }
        cout << endl;
        break;
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}