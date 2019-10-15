#include <bits/stdc++.h>

using namespace std;

string decimal_string(__int128 x) {
    if (x < 10)
        return to_string((int)(x%10));
    return decimal_string(x/10) + to_string((int)(x%10));
}

vector<int> p;
int64_t eulerphi(int64_t n) {
    // attempt to factorise n
    int p_i = 0;
    int64_t ret = 1;
    while(n != 1){
        if(p[p_i]*p[p_i] > n) {
            ret*=n - 1;
            break;
        }
        if (n % p[p_i] == 0) {
            n /= p[p_i];
            ret*=p[p_i] - 1;
            while (n % p[p_i] == 0) {
                n /= p[p_i];
                ret*=p[p_i];
            }
        }
        p_i++;
    }
    return ret;
}

int main(){
    const int pN = 100000;
	vector<bool> primeBool(pN + 1, true);
	for (int i = 2; i <= pN; i++) {
		if (primeBool[i]) {
			for (int j = 2 * i; j <= pN; j += i)
				primeBool[j] = false;
			p.push_back(i);
		}
	}

    // int64_t ret = 0;
    // for(int n=1;n<=5*10000*10000;n+=2){
    //     if(n-1 % 10000 == 0)
    //         cout << n << endl;
    //     ret += eulerphi(n);
    // }

    // cout << ret << endl;

    const int64_t N = 5*10000*10000;
    vector<int64_t> phi(N+1, 1);
    for(int x = 2; x <= N; x++) {
        if(phi[x] != 1) continue;
        if(x < 10000) cout << x << endl;
        for(int k=x; k <= N; k += x){
            phi[k] *= x - 1;
        }        
        int pow = x;
        while(pow <= N/x) {
            pow*=x;
            for(int k=pow; k <= N; k += pow){
                phi[k] *= x;
            }             
        }
    }
    cout << phi[N] << endl;
    __int128 ret = 0;
    for(int n=1;n<=N;n+=2){
        ret += phi[n];
        // cout << n << "\t" << phi[n] << endl;
        if((n-1) % 50000 == 0){
            cout << n << "\t" << decimal_string(ret) << endl;
        }
    }
    cout << decimal_string(ret) << endl;

    return 0;
}