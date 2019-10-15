#include <bits/stdc++.h>

using namespace std;

bool nextFacA(vector<int> &x, const vector<int> &pow){
    int i = pow.size()-1;
    while(i!=-1 && x[i] >= pow[i]) i--;
    if(i==-1) return false;
    x[i]++;
    while(++i < pow.size())
        x[i]=0;
    return true;
}

bool nextFacB(vector<int> &y, const vector<int> &pow, const vector<int> &x){
    int i = pow.size()-1;
    while(i!=-1 && y[i] >= pow[i]-x[i]) i--;
    if(i==-1) return false;
    y[i]++;
    while(++i < pow.size())
        y[i]=0;
    return true;
}

bool nextFacC(vector<int> &z, const vector<int> &pow, const vector<int> &x, const vector<int> &y){
    int i = pow.size()-1;
    while(i!=-1 && z[i] >= pow[i]-x[i]-y[i]) i--;
    if(i==-1) return false;
    z[i]++;
    while(++i < pow.size())
        z[i]=0;
    return true;
}

int64_t construct_from_fac(const vector<int> &fac, const vector<int> &pow){
    int64_t ret=1;
    for(int i=0;i<fac.size();i++){
        for(int k=0;k<pow[i];k++)
            ret*=fac[i];
    }
    return ret;
}

int main(){
    const int64_t N = 1000000;
	vector<vector<int> > primeFactor(N + 1);
	for (int i = 2; i <= N; i++)
		if (primeFactor[i].empty())
			for (int j = i; j <= N; j += i)
				primeFactor[j].push_back(i);

    int64_t sum = 4;
    for(int64_t n=2;n<=1000000;n++) {
        set<vector<int64_t>> s;
        cout << "N:" << n << endl;
        // int64_t nn=n*n;
        // find 4 integers with product nn, and each one is less than half the total

        vector<int> fac;
        vector<int> pow;
        int n1=n;
        for(auto p : primeFactor[n]){
            int a=0;
            while(n1%p == 0){
                n1/=p;
                a++;
            }
            fac.push_back(p);
            pow.push_back(2*a);
        }
        vector<int> x(fac.size(), 0);        
        do {
            if(4*x[0] > pow[0]) break;
            int64_t X=construct_from_fac(fac, x);
            vector<int> y(fac.size(), 0); //y[0] = x[0];
            do {
                if(x[0] + 3*y[0] > pow[0]) break;
                int64_t Y=construct_from_fac(fac, y);
                vector<int> z(fac.size(), 0); //[0] = y[0];
                do {
                    if(x[0] + y[0] + 2*z[0] > pow[0]) break;
                    int64_t Z=construct_from_fac(fac, z);
                    int64_t W = n*n/X/Y/Z;
                    // cout << X << "\t" << Y << "\t" << Z << "\t" << W << endl;
                    if(X*Y*Z*W != n*n){                        
                        cout << "!" << endl; exit(0);
                    }

                    int64_t S = X + Y + Z + W;
                    if(S % 2 != 0) continue;
                    S /= 2;

                    vector<int64_t> t = {S-X,S-Y,S-Z,S-W}; sort(t.begin(), t.end());
                    if(t[0] > 0){
                        // cout << "\t"<< t[0] << "\t" << t[1] << "\t" << t[2] << "\t" << t[3] << endl;
                        s.insert(t);
                    }
                } while(nextFacC(z, pow, x, y));
            } while(nextFacB(y, pow, x));
        } while(nextFacA(x, pow));
        
        for(auto t : s){
            sum += t[0] + t[1] + t[2] + t[3];
            // cout << "*\t"<< t[0] << "\t" << t[1] << "\t" << t[2] << "\t" << t[3] << endl;
        }
        cout << "SUM:" << sum << endl;
    }

    return 0;
}