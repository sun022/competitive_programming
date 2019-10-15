#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int64_t xGCD(int64_t a, int64_t b, int64_t &x, int64_t &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
 
	int64_t x1, y1, gcd = xGCD(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return gcd;
}

int hcf(const int a, const int b){
    if(b == 0) return a;
    return hcf(b, a%b);
}

int main(){
    const int64_t N = 100000;
	vector<vector<int> > primeFactor(N + 1);
	for (int i = 2; i <= N; i++)
		if (primeFactor[i].empty())
			for (int j = i; j <= N; j += i)
				primeFactor[j].push_back(i);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int M;
    cin >> M;
    vector<int64_t> inv(M+1);
    for(int i=1;i<=M;i++){
        int64_t x, y;
        xGCD(i, MOD, x, y);
        // cout << i << ":" << x << " " << y << endl;
        inv[i] = x;
    }

    vector<int> f(M+1);
    f[1] = 0;

    for(int x=2;x<=M;x++){
        // M*f[x] = M + (sum m=1 to M f[hcf(x, m)] )
        int self = M;
        int sum = M;
        for(int n=1;n<=M;n++){
            int d = hcf(n, x);
            if(d != x) sum += f[d];
            else self--;
        }
        f[x] = (sum*inv[self])%MOD;
        // cout << x << " " << f[x] << endl;
    }

    int64_t ans = 0;
    for(int x=1;x<=M;x++){
        ans += f[x];
        // cout << ans << endl;
    }
    ans = (1 + ans*inv[M])%MOD;
    if(ans < 0) ans += MOD;
    cout << ans << endl;

    return 0;
}