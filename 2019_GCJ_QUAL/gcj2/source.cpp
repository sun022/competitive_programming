#include <bits/stdc++.h>

using namespace std;

vector<int> query = {8, 9, 5, 7, 11, 13, 17};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, N, M;
    cin >> T >> N >> M; M = 1000000;
    for(int t=1;t<=T;t++){
        vector<bool> X(M + 1, true);
        for(int n=0;n<query.size();n++){
            int x = query[n];
            for(int k=0;k<18;k++)
                cout << x << " ";
            cout << endl;

            int y = 0;
            for(int k=0;k<18;k++){
                int z; cin >> z;
                y += z;
            }
            y %= x;
            // int y = 30 % x;

            for(int m=0;m<=M;m++){
                if(X[m] && m%x != y)
                    X[m] = false;
            }
        }
        
        // for(int m=0;m<=50;m++)
        //     cout << m << "\t" << X[m] << endl;
        int m = 0;
        while(!X[m]) m++;
        cout << m << endl;

        int resp;
        cin >> resp;
        if(resp == -1)
            return -1;
    }

    return 0;
}