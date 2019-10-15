#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> X(N);
    vector<int> Y(N);
    for(int i=0;i<N;i++)
        cin >> X[i] >> Y[i];

    vector<int> z(N);
    iota(z.begin(), z.end(), 0);
    // sort points by y desc
    sort(z.begin(), z.end(), [&X, &Y](int a,int b){return Y[a]>Y[b] || (Y[a] == Y[b] && X[a]<X[b]);});

    map<int, int> m;

    int64_t ret = 0;
    for(int i=0;i<N;){
        int y = Y[z[i]];

        vector<int> add;
        while(i!=N && Y[z[i]] == y){
            add.push_back(X[z[i]]);
            i++;
        }
        
        // int64_t sz = m.size();
        // ret += sz*(sz+1)/2;

        
        for(int j = 0;j< add.size();j++){
            
        }

    }

    cout << ret << endl;

    return 0;
}