#include <bits/stdc++.h>

using namespace std;


int main(){
    vector<int> fac(10,1);
    for(int n=1;n<=9;n++)
        fac[n]=n*fac[n-1];

    // N is max no. of digits
    int N = 3;

    int count_tot = 0;
    int D = 9;
    vector<int> count(D, 0);
    int t = 0;
    for(;;){
        t++;

        // calc f(n)      
        int64_t f_n = 0;
        for(int i=0;i<D;i++)
            f_n += count[i]*fac[i+1];

        // calc sf(n)
        int64_t f_n1 = f_n;
        int64_t sf_n=0;
        while(f_n1 != 0){
            sf_n += f_n1 % 10;
            f_n1 /= 10;
        }
        
        for(int x : count)
             cout << x;
        cout << "\t" << f_n << "\t" << sf_n << endl;

        if(count_tot < N){
            count.back()++;
            count_tot++;
        }
        else {
            int i = D-1;
            while(count[i] == 0) i--;
            i--;
            if(i == -1) break;
            count[i]++;
            count_tot++;
            while(++i <= D-1){
                count_tot -= count[i];
                count[i] = 0;
            }
        }
    }

    cout << t << endl;

    return 0;
}