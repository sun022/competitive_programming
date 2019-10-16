#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int64_t> X(N),Y(N),Z(N);
    for(int i=0;i<N;i++)
        cin >> X[i] >> Y[i] >> Z[i];

    vector<int> m1(N), m2(N), m3(N), m4(N), m5(N), m6(N), m7(N), m8(N);
    for(int i=0;i<N;i++){
        m1[i] = max(abs(X[i]), max(abs(Y[i]), abs(Z[i])));
        m8[i] = max(abs(X[i]-m1[i]), max(abs(Y[i]-m1[i]), abs(Z[i]-m1[i])));
        m2[i] = max(abs(X[i]-0), max(abs(Y[i]-m1[i]), abs(Z[i]-m1[i])));
        m3[i] = max(abs(X[i]-m1[i]), max(abs(Y[i]-0), abs(Z[i]-m1[i])));
        m4[i] = max(abs(X[i]-m1[i]), max(abs(Y[i]-m1[i]), abs(Z[i]-0)));
        m5[i] = max(abs(X[i]-m1[i]), max(abs(Y[i]-0), abs(Z[i]-0)));
        m6[i] = max(abs(X[i]-0), max(abs(Y[i]-m1[i]), abs(Z[i]-0)));
        m7[i] = max(abs(X[i]-0), max(abs(Y[i]-m1[i]), abs(Z[i]-0)));
    }

    vector<int> z(N);
    iota(z.begin(), z.end(), 0);

    sort(z.begin(), z.end(), [&m1,&m2,&m3,&m4,&m5,&m6,&m7,&m8](int i,int j){
        if(m1[i]!=m1[j]) return m1[i] < m1[j];
        if(m8[i]!=m8[j]) return m8[i] < m8[j];
        if(m2[i]!=m2[j]) return m2[i] < m2[j];
        if(m3[i]!=m3[j]) return m3[i] < m3[j];
        if(m4[i]!=m4[j]) return m4[i] < m4[j];
        if(m5[i]!=m5[j]) return m5[i] < m5[j];
        if(m6[i]!=m6[j]) return m6[i] < m6[j];
        return m7[i] < m7[j];
    });

    for(int i=0;i<N;i+=2)
        cout << z[i]+1 << " " << z[i+1]+1 << endl;

    // vector<bool> removed(N, false);

    // for(int i=0;i<N;i++){
    //     // find closest nonremoved point
    //     if(removed[i]) continue;

    //     int64_t best = LLONG_MAX;
    //     int bestIndex = -1;
    //     for(int j = i+1;j<N;j++){
    //         if(removed[j]) continue;
            
    //         int64_t dd = (X[i] - X[j])*(X[i] - X[j]) + (Y[i] - Y[j])*(Y[i] - Y[j]) + (Z[i] - Z[j])*(Z[i] - Z[j]);
    //         if(bestIndex == -1 || dd < best){
    //             best = dd;
    //             bestIndex = j;
    //         }
    //     }

    //     cout << i+1 << " " << bestIndex+1 << endl;
    //     removed[i] = true;
    //     removed[bestIndex] = true;
    // }

    return 0;
}