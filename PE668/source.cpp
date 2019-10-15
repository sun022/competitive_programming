#include <bits/stdc++.h>

using namespace std;

int main(){
    // sieve for primes <= 10^5
    const int pN = 100000;
	vector<bool> primeBool(pN + 1, true);
	vector<int64_t> p;
	for (int i = 2; i <= pN; i++) {
		if (primeBool[i]) {
			for (int j = 2 * i; j <= pN; j += i)
				primeBool[j] = false;
			p.push_back(i);
		}
	}

    int64_t total = 0;
    const int64_t NN = 10ll*1000*1000*1000;
    const int64_t K = 20;
    const int64_t N = NN/K;
    int64_t* X = new int64_t[N];

    for(int k = 0; k < K; k++){
        int64_t a = 1 + k * NN/K;
        int64_t b = (k + 1) * NN/K;
        for(int i=0;i<N;i++)
            X[i]=1;
        
        for(auto pr : p){
            int64_t pow = pr;

            int64_t base = max(a, pr*pr + 1);
            while(true){
                int64_t x = pow;
                // first multiple of pow greater equal to base
                int64_t init = ((base-1)/pow + 1)*pow;
                for(int64_t x = init; x <= b; x += pow){
                    X[x-a] *= pr;
                }
                //if(pow * pr > b) break;
                if(pow > b / pr) break;
                pow*=pr;
            }
        }

        int64_t count=0;
        for(int i=0;i<N;i++){
            // cout << a+i << ":\t" << X[i] << endl;
            if(X[i] == a+i) count++;
        }
        cout << a << " to " << b << ":\t" << count << endl;
        total += count;
    }
    cout << "TOTAL:" << total << endl;
    return 0;
}