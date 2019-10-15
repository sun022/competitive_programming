#include <bits/stdc++.h>

using namespace std;

const int pN = 1000000;
vector<int> p;
vector<bool> primeBool(pN + 1, true);

bool isPrime(int64_t x){
    if(x < 0) throw std::out_of_range("x < 0");
    if(x <= pN) return primeBool[x];

    int i = 0;
    while(true){
        if((int64_t)p[i]*p[i] > x)
            return true;
        if(x %p[i] == 0)
            return false;
        i++;
    }
}

int main(){
    primeBool[0] = primeBool[1] = false;
	for (int i = 2; i <= pN; i++) {
		if (primeBool[i]) {
			for (int j = 2 * i; j <= pN; j += i)
				primeBool[j] = false;
			p.push_back(i);
		}
	}

    // start by enumerating factors of 13!

    vector<pair<int,int>> X = {{2, 10}, {3, 5}, {5,2}, {7,1}, {11,1}, {13,1}};

    vector<int> x(6,0);

    vector<int64_t> c;

    while(true){
        int64_t y=1;
        for(int i=0;i<6;i++){
            for(int k=1;k<=x[i];k++)
                y*=X[i].first;
        }

        if(isPrime(y+1)){
            // cout << ++num << ":\t" << y << endl;
            c.push_back(y);
        }

        int i = 5;
        while(i!= -1 && x[i] == X[i].second)
            i--;
        if(i == -1) break;
        x[i]++;
        while(++i <= 5) x[i] = 0;
    }

    vector<int> z(c.size());
    iota(z.begin(), z.end(), 0);
    sort(z.begin(), z.end(), [&c](int i,int j){return c[i]<c[j];});

    map<int64_t, vector<vector<int64_t>>> m_list; // m_list[x] = list of all routes to x
    map<int64_t, int64_t> m; // n[x] = no. routes of x
    m[6227020800] = 1; // 13!
    m_list[6227020800] = {{}};
    

    for(int i=c.size()-1;i>=1;i--){
        map<int64_t, int64_t> m1 = m;
        int64_t d = c[z[i]];
        // when d = 1,2,4,6,10,12 (IE d == X[i].first - 1)
        //      different(extra) rules apply
    
        bool special = false;
        int64_t p = d + 1;
        int64_t p_n = p;
        for(int j=0;j<6;j++){
            if(p == X[j].first)
                special = true;
        }
        
        // cout << i << "\t" << p << endl;

        for(int pow = 1; ; pow++){
            // cout << "\t" << pow << " " << p_n << endl;
            bool d_hit = false;
            for(auto [k,v] : m) {                
                if(k % d == 0) {
                    d_hit = true;
                    // if(pow != 1) cout << "!"<< endl;
                    m1[k/d] += m[k];
                    int count = m[k];
                    for(vector<int64_t> vec : m_list[k]){                        
                        vec.push_back(p_n);
                        m_list[k/d].push_back(vec);
                        if(--count == 0) break;                        
                    }
                    if(m_list[k].size() != m1[k]){
                        cout << "!!!!" << endl;
                        exit(0);
                    }
                }
            }
            if(!d_hit || !special) break;

            d *= p;
            p_n *= p;
        }
        

        m = m1;
    }

    vector<int64_t> all;

    int p = 2;
    int64_t p_n = 2;
    int64_t d = p-1;
    for(int pow = 1; pow <= 12; pow++){    
        cout << pow << "\t" << d << "\t" << m_list[d].size() << endl;

        for(auto vec : m_list[d]){
            int64_t x = 1;
            for(auto y : vec){
                x *= y;
            }
            all.push_back(p_n*x);
            if(d==1)
                all.push_back(x);
        }

        p_n *= p;
        d *= p;
    }

    cout << "all size:" << all.size() << endl;
    sort(all.begin(), all.end());

    // for(int i=0;i<10;i++)
    //     cout << all[i] << endl;
    cout << all[150000-1] << endl;
    return 0;
}