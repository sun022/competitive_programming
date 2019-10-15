#include <bits/stdc++.h>

using namespace std;

int64_t hcf(int64_t x, int64_t y){
    if(y == 0) return x;
    return hcf(y, x%y);
}

bool nextFac(vector<int> &x, const vector<int> &y){
    int N = x.size();
    int i = 0;
    while(i!=N && x[i] == y[i]) i++;
    if(i == N) return false;
    x[i]++;
    while(--i >= 0)
        x[i]=0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int N = 1000000;
	vector<bool> primeBool(N + 1, true);
	vector<int> p;
	for (int i = 2; i <= N; i++) {
		if (primeBool[i]) {
			for (int j = 2 * i; j <= N; j += i)
				primeBool[j] = false;
			p.push_back(i);
		}
	}

    int A,B;
    cin >> A >> B;

    if(B < A) swap(A,B);

    if(A==B){
        cout << "0" << endl;
        return 0;
    }

    // for each factor f of B-A
    vector<int> fac;
    vector<int> pow;
    int BA = B-A;
    for (auto pr : p) {
        if(BA % pr != 0) continue;
        fac.push_back(pr);
        pow.push_back(0);
        while(BA % pr == 0){
            BA /= pr;
            pow.back()++;
        }
    }
    if(BA != 1){
        fac.push_back(BA);
        pow.push_back(1);
    }

    int bestK=0;
    int64_t bestVal=(int64_t)A*B;
    vector<int> x(fac.size(),0);
    do {
        int z=1;
        for(int i=0;i<fac.size();i++){
            for(int k=1;k<=x[i];k++)
                z*=fac[i];
        }
        // cout << z << endl;

        // try z as hcf
        int k;
        if(A % z == 0)
            k=0;
        else {
            k = (1+(A/z))*z - A;
        }
        int64_t lcm = (int64_t)(A+k)*(B+k) / z;
        if(lcm < bestVal){
            bestVal = lcm;
            bestK = k;
        }
    } while (nextFac(x, pow));

    cout << bestK << endl;

    return 0;
}