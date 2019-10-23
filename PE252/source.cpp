#include <bits/stdc++.h>

using namespace std;

const double PI = 4*atan(1);

vector<int> X,Y;

double to_deg(double rad){
    return 360*rad/(2*PI);
}

double angle_AB(int i,int j){
    return atan2(Y[j]-Y[i], X[j]-X[i]);
}

int area(int a, int b,int c){ // actually returns double the area of the triangle
    // cout << "AREA:" << X[a]*(Y[b] - Y[c]) + X[b]*(Y[c] - Y[a]) + X[c]*(Y[a] - Y[b]) << endl;
    return X[a]*(Y[b] - Y[c]) + X[b]*(Y[c] - Y[a]) + X[c]*(Y[a] - Y[b]);
}

int main(){
    int N = 500;
    vector<int> S(2*N+1);
    vector<int> T(2*N+1);
    S[0] = 290797;
    for(int i=1;i<=2*N;i++){
        S[i] = (int64_t)S[i-1]*S[i-1] % 50515093;
        T[i] = (S[i]%2000) - 1000;
    }

    X = vector<int>(N+1);
    Y = vector<int>(N+1);
    for(int i=1;i<=N;i++){
        X[i] = T[2*i - 1];
        Y[i] = T[2*i];
    }

    int m = 0;
    for(int r = 1; r<=N;r++){
        // int r = 1;
        // cout << X[r] << "," << Y[r] << endl;

        vector<int> z;
        for(int i=1;i<=N;i++){
            if(i == r) continue;
            if(Y[i] < Y[r]) continue;
            z.push_back(i);
        }

        sort(z.begin(), z.end(), [r](int i,int j){
            return angle_AB(r, i) < angle_AB(r, j);
        });

        z.insert(z.begin(), r);
        // for(auto i : z){
        //     cout << i << "\t" << angle_AB(r, i) << endl;        
        // }
        // cout << endl;

        int M = z.size();
        vector<vector<int>> f(M, vector<int>(M)); // f[i][j], i < j

        int ans = 0;
        for(int j = M - 1; j >= 1; j--){ // X
            for(int i = 0; i < j; i++){ // constraint X1
                f[j][i] = 0; // straight home from X an option

                double bound_angle = angle_AB(z[j], z[i]);
                for(int k = j+1; k < M; k++){ // or next stop k
                    if(!(angle_AB(z[k], z[j]) >= bound_angle)) continue; // ensure X is convex
                    f[j][i] = max(f[j][i], area(r, z[j], z[k]) + f[k][j]);

                    bound_angle = angle_AB(z[k], z[j]); // new bound angle, ensures triangle contains no points
                }
                if(r == 1)
                    cout << "f[" << j << "][" << i << "]=\t" << f[j][i] << endl;
            }
            ans = max(ans, f[j][0]);
        }
        cout << "r:" << r << "\t" <<  ans << endl;        
        m = max(m, ans);
    }
    cout << m << endl;
    return 0;
}