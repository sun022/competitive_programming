#include <bits/stdc++.h>

using namespace std;

int main(){
    const int pN = 300000000;
    vector<int> p;
    vector<bool> primeBool(pN + 1, true);
    vector<int> leastPrimeFac(pN + 1, -1);
    primeBool[0] = primeBool[1] = false;
	for (int i = 2; i <= pN; i++) {
		if (primeBool[i]) {
            leastPrimeFac[i] = i;
			for (int j = 2 * i; j <= pN; j += i){
				primeBool[j] = false;
                if(leastPrimeFac[j] == -1) leastPrimeFac[j] = i;
            }
			p.push_back(i);
		}
	}

    int64_t N = 110000000;
    // int64_t N = 1000;

    int64_t count = 0;
    for(int q = 0;;q++){
        int64_t x = 1 + 2*q;     
        int64_t a = (3*x + 1) / 2;
        if(a > N/2) break;
        
        int64_t xc = (int64_t)(1+q)*(1+q)*(8*q + 5);
        // want to know how many squares divide xc

        map<int,int> m_fac;
        {
            int x = 1+q;
            while(x!=1){
                int p = leastPrimeFac[x];
                m_fac[p]+=2;
                x/=p;
            }
        }
        {
            int x = 8*q + 5;
            while(x!=1){
                int p = leastPrimeFac[x];
                m_fac[p]++;
                x/=p;
            }
        }
        
        vector<int> fac;
        vector<int> pow;
        // cout << "a=" << a << "\txc=" << xc << "\t";
        for(auto [k,v] : m_fac){
            // cout << k << "^" << v << "\t";
            fac.push_back(k);
            pow.push_back(v);
        }
        // cout << endl;

        int num_fac = fac.size();

        vector<int> z(num_fac, 0);

        while(true){
            int64_t b=1; // big enough?
            int64_t c=1;
            for(int i=0;a+b+c<=N && i<num_fac;i++){
                for(int k=1; a+b+c<=N && k<=z[i];k++)
                    b*=fac[i];
                for(int k=1; a+b+c<=N && k<=pow[i] - 2*z[i];k++)
                    c*=fac[i];
            }

            if(a+b+c<=N) {

                // if(xc/c != b*b){
                //     int64_t c = xc/(b*b);
                //     cerr << "!\t" << b << endl;
                //     cerr << xc << endl;
                //     exit(0);
                // }

                count++;
                if(count % 100000 == 0 || count >= 18946000)
                    cout << count << ":\t" << a << "\t" << b << "\t" << c << endl;
            }

            int i = num_fac - 1;
            while(i!=-1 && 2*(z[i] + 1) > pow[i])
                i--;
            if(i==-1)
                break;
            z[i]++;
            while(++i < num_fac)
                z[i] = 0;
        }
    }

    cout << "count:" << count << endl;

    return 0;
}