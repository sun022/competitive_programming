#include <bits/stdc++.h>

using namespace std;

int64_t hcf(int64_t a, int64_t b){
    if(a<0) return hcf(-a,b);
    if(b<0) return hcf(a,-b);
    if(b==0) return a;
    return hcf(b, a%b);
}

void normalize(int64_t &n, int64_t &d){
    int64_t x = hcf(n,d);
    n/=x;
    d/=x;
    if(d < 0 || (d==0 && n <0)){
        n=-n;
        d=-d;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    vector<int64_t> X(N),Y(N);
    for(int i=0;i<N;i++){
        cin >> X[i] >> Y[i];
    }

    // basically need to sort all the N^2 cables into a way we can get rid of duplicates and group by gradient
    set<tuple<int64_t,int64_t,int64_t,int64_t>> s; // lines set, canonical form
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int64_t dx = X[j]-X[i];
            int64_t dy = Y[j]-Y[i];
            normalize(dy, dx);
            // handle dx = 0 seperately?
            if(dx == 0){
                // use intercept with x-axis instead
                int64_t c = X[i];
                s.insert({dy,dx,c,1});
            }
            else {
                int64_t c1 = Y[i]*dx - dy*X[i];
                int64_t c2 = dx;
                normalize(c1,c2);
                s.insert({dy,dx,c1,c2});
            }
        }
    }

    vector<int> sz;
    int a1,b1,c1,d1;
    for(auto it = s.begin(); it != s.end(); it++){
        auto [a,b,c,d] = *it;
        if(it == s.begin() || a1!=a || b1!=b)
            sz.push_back(1);
        else
            sz.back()++;
        
        a1=a;b1=b;c1=c;d1=d;
    }

    int num_lines = s.size();
    int64_t ans=0;
    for(int i=0;i<sz.size();i++){
        ans += sz[i]*(num_lines - sz[i]);
    }
    ans /= 2;
    cout << ans << endl;

    return 0;
}