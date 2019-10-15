#include <bits/stdc++.h>

using namespace std;

int main(){
    int N = 100000;
    int M = 6;
    vector<long double> p(N, 0); // prob of hitting 0
    for(int n=0;n<M;n++)
        p[n] = 1;

    vector<int> last(N, 0);
    for(int t=1;true || t<=10000;t++){
        for(int n=M;n<N;n++) {
            long double adj = -p[n];
            int pot=1;
            long double prob=0.5;
            while(true){
                adj += prob*p[n+pot-M];

                pot*=2;prob/=2;
                if(n+pot-M >= N) break;
            }
            if(adj > 0){
                last[n] = max(last[n], 0) + 1;
            }
            else {
                last[n] = min(last[n], 0) - 1;
            }
            p[n] += adj;
        }
        //for(int i=0;i<100;i++)
        //    cout << p[i] << endl;
        cout << t << ":\t" << fixed << setprecision(10) << 1-p[10000] << " " << 1-p[9999] << endl;
    }
    return 0;
}